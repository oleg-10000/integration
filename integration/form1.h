#ifndef INTEGRATION_H
#define INTEGRATION_H

#include <QtWidgets/QMainWindow>
#include "ui_form1.h"

#include <QtWidgets\QLabel>
#include <QtWidgets\QLineEdit>
#include "vector"

class DrawWidget :public QWidget
{
	Q_OBJECT
	std::vector<std::vector<long double>> data;
public:
	DrawWidget(QWidget *parent = 0) :QWidget(parent), data() {}
	void setData(const std::vector<std::vector<long double>> &data) { this->data = data; }
	void setData(std::vector<std::vector<long double>> &&data) { this->data = std::move(data); }
	void paintEvent(QPaintEvent *pe);

};

class form1 : public QMainWindow
{
	Q_OBJECT

	QString t;//Аргумент функции

	QGridLayout* ptrQGL;//Указатель на QGridLayout для ввода системы уравнений

	size_t EquationCount;//Количество уравнений
	//xi'(t)=F(t,x1,...,xn)	xi(t0)=xi0
	std::vector<QLineEdit*> vptrQLE1;//xi
	std::vector<QLabel*> vptrQL1;//'(
	std::vector<QLineEdit*> vptrQLE2;//t
	std::vector<QLabel*> vptrQL2;//)=
	std::vector<QLineEdit*> vptrQLE3;//F(t,x1,...,xn)
	std::vector<QLabel*> vptrQL3;//xi(t0)=
	std::vector<QLineEdit*> vptrQLE4;//xi0

	DrawWidget* ptrDW;

public:
	form1(QWidget *parent = 0);
	~form1();

private:
	Ui::integrationClass ui;
private slots:
	void AddEquation();//Добавить уравнение
	void DelEquation();//Удалить уравнение
	void sett(const QString& t_str);//Изменить t
	void calculate();//Вычислить

signals:
	void tChanged(const QString& );//t изменено слотом sett, необходимо обновить Edit-ы и label-ы

};

#endif // INTEGRATION_H

	void DelEquation();//Óäàëèòü óðàâíåíèå
	void sett(const QString& t_str);//Èçìåíèòü t
	void calculate();//Âû÷èñëèòü

signals:
	void tChanged(const QString& );//t èçìåíåíî ñëîòîì sett, íåîáõîäèìî îáíîâèòü Edit-û è label-û

};

#endif // INTEGRATION_H
