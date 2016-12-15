#pragma once
#include <memory>
#include <string>
#include <vector>
#include <functional>
namespace userfunction
{

	class function // f(...)
	{
	protected:
		//using unary_ld_function_ptr = long double(*)(long double f);
		//using binary_ld_function_ptr = long double(*)(long double f1, long double f2);
		using unary_ld_function_ptr = std::function<long double(long double f)>;
		using binary_ld_function_ptr = std::function<long double(long double f1, long double f2)>;
		using uptr_function = std::unique_ptr<function>;
	public:
		function() {}
		virtual long double operator()(const std::vector<long double>& A)const = 0;
		virtual ~function() = default;
	};

	class function_unary :public function //F(f(...))
	{
	private:
		uptr_function f;
		unary_ld_function_ptr F;
	public:
		function_unary(uptr_function&& f, unary_ld_function_ptr F)
			:function(), f(std::move(f)), F(F) {}
		virtual long double operator()(const std::vector<long double>& A)const override
		{
			return F((*f)(A));
		}
	};

	class function_binary :public function //F(f1(...), f2(...))
	{
	private:
		uptr_function f1;
		uptr_function f2;
		binary_ld_function_ptr F;
	public:
		function_binary(uptr_function&& f1, uptr_function&& f2, binary_ld_function_ptr F)
			:function(), f1(std::move(f1)), f2(std::move(f2)), F(F) {}
		virtual long double operator()(const std::vector<long double>& A)const override
		{
			return F((*f1)(A), (*f2)(A));
		}
	};

	class function_const :public function //a=const
	{
	private:
		long double a;//значение константы
	public:
		function_const(const long double a) :function(), a(a) {}
		virtual long double operator()(const std::vector<long double>& A)const noexcept override
		{
			return a;
		}
	};

	class function_variable :public function //A[n]=double
	{
	private:
		size_t n;//номер переменной
	public:
		function_variable(const size_t n) :function(), n(n) {}
		virtual long double operator()(const std::vector<long double>& A)const override
		{
			return A[n];
		}
	};

	std::unique_ptr<function> make_function(const std::string& s, const std::vector<std::string>& S);//Фабричная функция для function

}

	class function_const :public function //a=const
	{
	private:
		long double a;//çíà÷åíèå êîíñòàíòû
	public:
		function_const(const long double a) :function(), a(a) {}
		virtual long double operator()(const std::vector<long double>& A)const noexcept override
		{
			return a;
		}
	};

	class function_variable :public function //A[n]=double
	{
	private:
		size_t n;//íîìåð ïåðåìåííîé
	public:
		function_variable(const size_t n) :function(), n(n) {}
		virtual long double operator()(const std::vector<long double>& A)const override
		{
			return A[n];
		}
	};

	std::unique_ptr<function> make_function(const std::string& s, const std::vector<std::string>& S);//Ôàáðè÷íàÿ ôóíêöèÿ äëÿ function

}
