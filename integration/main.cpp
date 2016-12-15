#include "userfunction.h"
#include "integr.h"

#include "form1.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	/*std::string Fstr = "((+sin(5.0*x1)*(-cos(7.0/x2))))";
	std::vector<std::string> varstr = { "x1", "x2" };
	std::vector<long double> var = { 5, 10 };
	auto F = userfunction::make_function(Fstr, varstr);
	auto D = [](long double ti, const integration::v_t<long double>& xi) {};
	auto F1 = [&F](const long double t,const std::vector<long double> var) {return (*F)(var); };
	integration::vF_t<long double> vF = {F1,F1};
	auto R = (*F)(var);
	
	auto vRez = integration::Cauchy(vF, var, 0.0l, 10.0l, 0.01l, (integration::method_t<long double>)integration::RungeKuttaMethod<long double>, (std::function<void(long double ti, const integration::v_t<long double>& xi)>)D);
	*/
	
	
	QApplication a(argc, argv);
	form1 w;
	w.show();
	return a.exec();
}
