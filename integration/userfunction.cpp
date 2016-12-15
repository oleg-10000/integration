#include "userfunction.h"
#include <math.h>
#include <regex>
#include <stack>
#include <array>
#include <stdexcept>
#include <algorithm>

namespace userfunction
{
	std::unique_ptr<function> make_function(const std::string & s, const std::vector<std::string>& S)
	{
		std::vector<std::array<size_t, 2>> brackets;//индексы скобок
		brackets.reserve(s.size());
		std::stack<size_t *> ob;//стек указателей на индексы не закрытых скобок
		for (auto i=s.find_first_of("()")//поиск первой скобки
			;i!=s.npos//завершить цикл если скобок не найдено
			;i=s.find_first_of("()",i+1))//поиск следующей скобки
		switch(s[i])
		{
		case '(':
			brackets.push_back({ i,0 });
			ob.push(&brackets.back()[1]);
			break;
		case ')':
			if (ob.empty()) throw std::invalid_argument("скобки не согласованы");
			*ob.top() = i;
			ob.pop();
			break;
		}
		if (!ob.empty()) throw std::invalid_argument("скобки не согласованы");

		size_t Nb = 0;//количество внешних скобок
		for (const auto& b : brackets)
		if (std::regex_match(s.substr(0, b[0]), std::regex("[ \t\n\\(]*")) &&
			std::regex_match(s.substr(b[1] + 1), std::regex("[ \t\n\\)]*")))
			++Nb;
		else break;
		const size_t ns0 = Nb ? brackets[Nb-1][0] + 1 : 0;//номер первого символа внутри внешних скобок
		const size_t nsk = Nb ? brackets[Nb-1][1] - 1 : s.size() - 1;//Номер последнего символа внутри внешних скобок
		
		for (auto i = s.find_last_of("+-")//поиск последнего знака + или -
			; i != s.npos
			; i = s.find_last_of("+-", i - 1))//поиск следующего знака + или -
		//Если найденный знак находится не в скобках
		if (!std::count_if(brackets.cbegin() + Nb, brackets.cend(),
			[i](const std::array<size_t, 2> &b) {return i > b[0] && i < b[1]; } ))
		{
			const auto f1 = s.substr(ns0, i - ns0);
			const auto f2 = s.substr(i + 1, nsk - i);
			const auto op = s[i];
			if(std::regex_match(f1, std::regex("[ \t\n]*")))//Унарная операция
			switch (op)
			{
			case '+':
				return make_function(f2, S);
				break;
			case '-':
				return std::make_unique<function_unary>(make_function(f2, S), std::negate<long double>());
				break;
			}
			else switch (op)//Бинарная операция
			{
			case '+':
				return std::make_unique<function_binary>(make_function(f1, S), make_function(f2, S), std::plus<long double>());
				break;
			case '-':
				return std::make_unique<function_binary>(make_function(f1, S), make_function(f2, S), std::minus<long double>());
				break;
			}
		}
	
		for (auto i = s.find_last_of("*/")//поиск последнего знака * или /
			; i != s.npos
			; i = s.find_last_of("*/", i - 1))//поиск следующего знака * или /
		//Если найденный знак находится не в скобках
		if (!std::count_if(brackets.cbegin() + Nb, brackets.cend(),
			[i](const std::array<size_t, 2> &b) {return i > b[0] && i < b[1]; }))
		{
			const auto f1 = s.substr(ns0, i - ns0);
			const auto f2 = s.substr(i + 1, nsk - i);
			const auto op = s[i];
			switch (op)
			{
			case '*':
				return std::make_unique<function_binary>(make_function(f1, S), make_function(f2, S), std::multiplies<long double>());
				break;
			case '/':
				return std::make_unique<function_binary>(make_function(f1, S), make_function(f2, S), std::divides<long double>());
				break;
			}
		}

		for (auto i = s.rfind('^')//поиск последнего знака ^
			; i != s.npos
			; i = s.rfind('^', i - 1))//поиск следующего знака ^
		//Если найденный знак находится не в скобках
		if (!std::count_if(brackets.cbegin() + Nb, brackets.cend(),
			[i](const std::array<size_t, 2> &b) {return i > b[0] && i < b[1]; }))
		{
			const auto f1 = s.substr(ns0, i - ns0);
			const auto f2 = s.substr(i + 1, nsk - i);
			return std::make_unique<function_binary>(make_function(f1, S), make_function(f2, S), (long double(*)(long double, long double))&pow);
		}

		const auto sv = s.substr(ns0, nsk + 1 - ns0);//Строка внутри внешних скобок
		std::smatch m;//для возвращаемой информации
		//если sv функция
		if (std::regex_match(sv, m, std::regex("[ \t\n]*(\\w+)[ \t\n]*\\(((.|\n)+)\\)[ \t\n]*")))
		if (m[1].str() == "sin")
			return std::make_unique<function_unary>(make_function(m[2].str(), S), (long double(*)(long double))&sin);
		else if (m[1].str() == "cos")
			return std::make_unique<function_unary>(make_function(m[2].str(), S), (long double(*)(long double))&cos);
		else throw std::invalid_argument("Неизвестная функция " + m[1].str());
		//Если sv число
		if(std::regex_match(sv, m, std::regex("[ \t\n]*([[:digit:]]*\\.?[[:digit:]]+)[ \t\n]*")))
			return std::make_unique<function_const>(std::stold(m[1].str()));
		//Если sv переменная
		for (auto i = 0; i < S.size(); ++i)
		if (std::regex_match(sv, std::regex("[ \t\n]*(" + S[i] + ")[ \t\n]*")))
			return std::make_unique<function_variable>(i);

		throw std::invalid_argument("Неизвестная переменная " + sv);

		//return std::unique_ptr<functional>();
	}
}