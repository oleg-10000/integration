#include "form1.h"
#include "userfunction.h"
#include "integr.h"
#include <QPainter>
#include <QErrorMessage>
#include <QTextCodec>

class strValidator :public QValidator
{
public:
	strValidator(QObject* parent) :QValidator(parent) {}
	virtual State validate(QString& str, int& pos) const override
	{
		QRegExp rxp = QRegExp("[\\w]*");//�����, ����� � ����� �������������
		if (rxp.exactMatch(str))//������ ������������
			return Acceptable;
		else return Invalid;
	}
};

form1::form1(QWidget *parent)
	: QMainWindow(parent), EquationCount(0), t(""), ptrQGL(nullptr), ptrDW(nullptr)
	, vptrQLE1(), vptrQL1(), vptrQLE2(), vptrQL2(), vptrQLE3(), vptrQL3(), vptrQLE4()
{
	ui.setupUi(this);

	
	//QTextCodec *codec = QTextCodec::codecForName(QString("Windows-1251").toUtf8());// ����� ������
	//ui.comboBox->addItem(codec->toUnicode("����� �����-�����"));
	//ui.comboBox->addItem(codec->toUnicode("����� ������"));

	//ui.comboBox->addItem(QString::fromWCharArray(L"����� �����-�����"));
	//ui.comboBox->addItem(QString::fromWCharArray(L"����� ������"));

	//ui.comboBox->addItem(tr(QString::fromWCharArray(L"����� �����-�����").toUtf8()));
	//ui.comboBox->addItem(tr(QString::fromWCharArray(L"����� ������").toUtf8()));
	
	auto trUnicode = [](const wchar_t* string) {return tr(QString::fromWCharArray(string).toUtf8()); };
	ui.comboBox->addItem(trUnicode(L"����� �����-�����"));
	ui.comboBox->addItem(trUnicode(L"����� ������"));

	//�������� ����� ��� ����, t0 � tk
	ui.lineEdit->setValidator(new QDoubleValidator(ui.lineEdit));
	ui.lineEdit_2->setValidator(new QDoubleValidator(ui.lineEdit_2));
	ui.lineEdit_3->setValidator(new QDoubleValidator(ui.lineEdit_3));

	ptrQGL = new QGridLayout();
	ui.verticalLayout_2->insertLayout(1,ptrQGL);

	ptrDW = new DrawWidget();
	ui.horizontalLayout_3->addWidget(ptrDW);
	ptrDW->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

	
	connect(ui.pushButton, &QPushButton::clicked, this, &form1::AddEquation);//�������� ���������
	connect(ui.pushButton_2, &QPushButton::clicked, this, &form1::DelEquation);//������� ���������
	connect(ui.pushButton_3, &QPushButton::clicked, this, &form1::calculate);//���������
	//��� ��������� ��������� (string t) �������� label-� t0 � tk
	connect(this, &form1::tChanged, [ptrQL = ui.label_3](const QString& str) {
		ptrQL->setText(str + R"(<span style=" vertical-align:sub;">0</span>)"); });
	connect(this, &form1::tChanged, [ptrQL = ui.label_4](const QString& str) {
		ptrQL->setText(str + R"(<span style=" vertical-align:sub;">k</span>)"); });

	//resize(1000,700);//������ ������ �����

	//�������� �� ��������� ��� ����, t0 � tk
	ui.lineEdit->setText(QLocale().toString(0.01));//���
	ui.lineEdit_2->setText("0");//t0
	ui.lineEdit_3->setText("10");//tk

	AddEquation();//�������� 1-�� ���������

	//������ � Edit-� �������� ������
	sett("t");
	vptrQLE1[0]->setText("x1");
	vptrQLE3[0]->setText("2*sin(-x2/(t+1))^2");
	vptrQLE4[0]->setText("7");
	AddEquation();
	vptrQLE1[1]->setText("x2");
	vptrQLE3[1]->setText("1.5*cos(x1)*t");
	vptrQLE4[1]->setText("3");

	
	
}

form1::~form1()
{

}

void form1::AddEquation()
{
	//�������� label-�� � edit-�� ��� ����� ���������
	QLineEdit* ptrQLE1 = new QLineEdit();
	ptrQGL->addWidget(ptrQLE1, EquationCount, 0);
	vptrQLE1.push_back(ptrQLE1);
	ptrQLE1->setValidator(new strValidator(ptrQLE1));
	ptrQLE1->setMaxLength(2);
	ptrQLE1->setMaximumWidth(20);
	ptrQLE1->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
	QLabel* ptrQL1 = new QLabel("'(");
	ptrQGL->addWidget(ptrQL1, EquationCount, 1);
	vptrQL1.push_back(ptrQL1);
	QLineEdit* ptrQLE2 = new QLineEdit(t);
	ptrQGL->addWidget(ptrQLE2, EquationCount, 2);
	vptrQLE2.push_back(ptrQLE2);
	ptrQLE2->setValidator(new strValidator(ptrQLE2));
	ptrQLE2->setMaxLength(2);
	ptrQLE2->setMaximumWidth(20);
	ptrQLE2->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
	QLabel* ptrQL2 = new QLabel(")=");
	ptrQGL->addWidget(ptrQL2, EquationCount, 3);
	vptrQL2.push_back(ptrQL2);
	QLineEdit* ptrQLE3 = new QLineEdit();
	ptrQGL->addWidget(ptrQLE3, EquationCount, 4);
	vptrQLE3.push_back(ptrQLE3);
	ptrQLE3->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
	QLabel* ptrQL3 = new QLabel(R"(_<span style=" vertical-align:sub;">0</span>=)");
	ptrQGL->addWidget(ptrQL3, EquationCount, 5);
	vptrQL3.push_back(ptrQL3);
	QLineEdit* ptrQLE4 = new QLineEdit();
	ptrQGL->addWidget(ptrQLE4, EquationCount, 6);
	vptrQLE4.push_back(ptrQLE4);
	ptrQLE4->setValidator(new QDoubleValidator(ptrQLE4));
	ptrQLE4->setMaximumWidth(50);
	ptrQLE4->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
	++EquationCount;//��������� �������� ���������� ���������
	
	//��� ��������� t �������� edit-� � label-�
	connect(ptrQLE2, &QLineEdit::textChanged, this, &form1::sett);
	connect(this, &form1::tChanged, ptrQLE2, &QLineEdit::setText);
	connect(ptrQLE1, &QLineEdit::textChanged, [ptrQL3](const QString& str) {
		ptrQL3->setText(str+R"(<span style=" vertical-align:sub;">0</span>=)"); });

	//������ "������� ���������" �������� ������ ���� � ������� ������ ������ ���������
	if (EquationCount > 1) ui.pushButton_2->setEnabled(true);
	else ui.pushButton_2->setEnabled(false);

	//ui.gridLayout->setMargin(10);
	//ui.gridLayout->setSpacing(10);
	//ui.gridLayout->setRowMinimumHeight(5, 10);
}
void form1::DelEquation()
{
	if (EquationCount>1)
	{
		delete vptrQLE1.back();
		vptrQLE1.pop_back();
		delete vptrQL1.back();
		vptrQL1.pop_back();
		delete vptrQLE2.back();
		vptrQLE2.pop_back();
		delete vptrQL2.back();
		vptrQL2.pop_back();
		delete vptrQLE3.back();
		vptrQLE3.pop_back();
		delete vptrQL3.back();
		vptrQL3.pop_back();
		delete vptrQLE4.back();
		vptrQLE4.pop_back();
		--EquationCount;
	}
	if (EquationCount == 1) ui.pushButton_2->setEnabled(false);
	else ui.pushButton_2->setEnabled(true);
}

void form1::sett(const QString& t_str)
{
	if (this->t != t_str)//���� t ����������
	{
		this->t = t_str;
		emit tChanged(t);
	}
}
void form1::calculate()
{
	try
	{
	//������ {x1, x2, ..., xn}
	std::vector<std::string> vvarstr(EquationCount);
	for (size_t i = 0; i < EquationCount; ++i)
		vvarstr[i] = vptrQLE1[i]->text().toStdString();

	//������ {t, x1, x2, ..., xn}
	std::vector<std::string> vtvarstr(EquationCount+1);
	vtvarstr[0] = t.toStdString();
	std::copy(vvarstr.cbegin(), vvarstr.cend(), vtvarstr.begin() + 1);

	//������ {x1(t0), x2(t0), ..., xn(t0)}
	std::vector<long double> vvar0(EquationCount);
	for (size_t i = 0; i < EquationCount; ++i)
		vvar0[i] = vptrQLE4[i]->text().toDouble();

	//������ {F1(t, x1, ..., xn), ..., Fn(t, x1, ..., xn)}
	integration::vF_t<long double> vF(EquationCount);
	for (size_t i = 0; i < EquationCount; ++i)
	{
		using namespace userfunction;
		std::shared_ptr<function> Fi
			= make_function(vptrQLE3[i]->text().toStdString(), vtvarstr);
		vF[i]=[F=std::move(Fi)](const long double t, const std::vector<long double>& var)
		{
			//������ {tj, x1(tj), x2(tj), ..., xn(tj)}
			std::vector<long double> vtvar(var.size() + 1);
			vtvar[0] = t;
			std::copy(var.cbegin(), var.cend(), vtvar.begin() + 1);
			//Fi(t, x1, ..., xn)
			return (*F)(vtvar);
		};
	}

	//�����
	integration::method_t<long double> method;
	switch (ui.comboBox->currentIndex())
	{
	case 0:
		method = integration::RungeKuttaMethod<long double>;
		break;
	case 1:
		method = integration::EulerMethod<long double>;
		break;
	default:
		throw std::invalid_argument("����������� ����� ��������������");
		break;
	}

	//
	std::vector<std::vector<long double>> DataDraw(EquationCount + 1);
	std::function<void(long double ti, const integration::v_t<long double>& xi)> D
		= [&DataDraw](long double ti, const std::vector<long double>& xi)
	{
		DataDraw[0].push_back(ti);
		for (size_t i = 0; i < xi.size(); ++i)
			DataDraw[i + 1].push_back(xi[i]);
	};
	
	long double h = QLocale().toDouble(ui.lineEdit->text());
	long double t0 = QLocale().toDouble(ui.lineEdit_2->text());
	long double tk = QLocale().toDouble(ui.lineEdit_3->text());

	if (h <= 0) throw std::invalid_argument("h<=0");

	auto vRez = integration::Cauchy(vF, vvar0, t0, tk, h, method, D);

	std::string strRez;
	for (size_t i = 0; i < EquationCount; ++i)
		strRez += vvarstr[i] + "(" + std::to_string(tk) + ")=" + std::to_string(vRez[i]) + "\n";
	ui.label_5->setText(QString::fromStdString(strRez));

	ptrDW->setData(std::move(DataDraw));
	ptrDW->update();
	}
	catch (std::exception e)
	{
		QTextCodec *codec = QTextCodec::codecForName(QString("Windows-1251").toUtf8());
		(new QErrorMessage(this))->showMessage(codec->toUnicode(e.what()));
	}
}

void DrawWidget::paintEvent(QPaintEvent *pe)
{
	if (data.empty()) return;

	long double xmin = *std::min_element(data[0].cbegin(), data[0].cend());
	long double xmax = *std::max_element(data[0].cbegin(), data[0].cend());

	std::vector<long double> yimin(data.size() - 1);
	std::vector<long double> yimax(data.size() - 1);
	for (size_t i = 0; i < data.size() - 1; ++i)
	{
		yimin[i] = *std::min_element(data[i + 1].cbegin(), data[i + 1].cend());
		yimax[i] = *std::max_element(data[i + 1].cbegin(), data[i + 1].cend());
	}
	long double ymin = *std::min_element(yimin.cbegin(), yimin.cend());
	long double ymax = *std::max_element(yimax.cbegin(), yimax.cend());

	std::vector<QPointF*> DataPoint(data.size() - 1);
	for (size_t i = 0; i < DataPoint.size(); ++i)
	{
		DataPoint[i] = new QPointF[data[0].size()];
		for (size_t j = 0; j < data[0].size(); ++j)
			DataPoint[i][j] = QPointF(data[0][j], -data[i + 1][j]);
	}

	QPainter QP(this);
	//QP.save();//��������� ��������� painter
	QP.setRenderHint(QPainter::Antialiasing, true);//�������� �����������
	QP.setPen(QPen(Qt::red, 0, Qt::SolidLine));//����
	
	QP.scale(this->width() / (xmax - xmin), this->height() / (ymax - ymin));//���������������
	QP.translate(-xmin, ymax);//�����������

	for (const auto& pointarray : DataPoint)
		QP.drawPolyline(pointarray, data[0].size());
	
	//QP.restore();//������������ ��������� painter

	for (size_t i = 0; i < DataPoint.size(); ++i)
		delete[] DataPoint[i];
}