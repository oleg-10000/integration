/********************************************************************************
** Form generated from reading UI file 'form1.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM1_H
#define UI_FORM1_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_integrationClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QFormLayout *formLayout;
    QComboBox *comboBox;
    QLineEdit *lineEdit;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QLabel *label_4;
    QLabel *label_5;
    QSpacerItem *verticalSpacer;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *integrationClass)
    {
        if (integrationClass->objectName().isEmpty())
            integrationClass->setObjectName(QStringLiteral("integrationClass"));
        integrationClass->resize(699, 368);
        centralWidget = new QWidget(integrationClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setSizeConstraint(QLayout::SetMinimumSize);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetMinimumSize);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setSizeConstraint(QLayout::SetMinimumSize);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_4->addWidget(pushButton);

        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout_4->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        horizontalLayout_4->addWidget(pushButton_3);


        verticalLayout_2->addLayout(horizontalLayout_4);

        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        formLayout->setWidget(0, QFormLayout::FieldRole, comboBox);

        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy);

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        sizePolicy.setHeightForWidth(lineEdit_2->sizePolicy().hasHeightForWidth());
        lineEdit_2->setSizePolicy(sizePolicy);

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEdit_2);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        lineEdit_3 = new QLineEdit(centralWidget);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        sizePolicy.setHeightForWidth(lineEdit_3->sizePolicy().hasHeightForWidth());
        lineEdit_3->setSizePolicy(sizePolicy);

        formLayout->setWidget(3, QFormLayout::FieldRole, lineEdit_3);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);


        verticalLayout_2->addLayout(formLayout);

        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout_2->addWidget(label_5);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout_3->addLayout(verticalLayout_2);


        gridLayout->addLayout(horizontalLayout_3, 0, 0, 1, 1);

        integrationClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(integrationClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 699, 21));
        integrationClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(integrationClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        integrationClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(integrationClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        integrationClass->setStatusBar(statusBar);

        retranslateUi(integrationClass);

        QMetaObject::connectSlotsByName(integrationClass);
    } // setupUi

    void retranslateUi(QMainWindow *integrationClass)
    {
        integrationClass->setWindowTitle(QApplication::translate("integrationClass", "\320\227\320\260\320\264\320\260\321\207\320\260 \320\232\320\276\321\210\320\270 \320\264\320\273\321\217 \321\201\320\270\321\201\321\202\320\265\320\274\321\213 \320\236\320\224\320\243 1-\320\263\320\276 \320\277\320\276\321\200\321\217\320\264\320\272\320\260", 0));
        pushButton->setText(QApplication::translate("integrationClass", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\203\321\200\320\260\320\262\320\275\320\265\320\275\320\270\320\265", 0));
        pushButton_2->setText(QApplication::translate("integrationClass", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \321\203\321\200\320\260\320\262\320\275\320\265\320\275\320\270\320\265", 0));
        pushButton_3->setText(QApplication::translate("integrationClass", "\320\222\321\213\321\207\320\270\321\201\320\273\320\270\321\202\321\214", 0));
        label->setText(QApplication::translate("integrationClass", "\320\234\320\265\321\202\320\276\320\264", 0));
        label_2->setText(QApplication::translate("integrationClass", "\320\250\320\260\320\263", 0));
        label_3->setText(QApplication::translate("integrationClass", "t<span style=\" vertical-align:sub;\">0</span>", 0));
        label_4->setText(QApplication::translate("integrationClass", "t<span style=\" vertical-align:sub;\">k</span>", 0));
        label_5->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class integrationClass: public Ui_integrationClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM1_H
