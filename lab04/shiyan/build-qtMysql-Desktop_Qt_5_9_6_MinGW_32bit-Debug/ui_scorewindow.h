/********************************************************************************
** Form generated from reading UI file 'scorewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCOREWINDOW_H
#define UI_SCOREWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ScoreWindow
{
public:
    QAction *actionAdd;
    QAction *actionPL;
    QAction *action;
    QAction *actionsql;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QTextEdit *textEdit;
    QWidget *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QSplitter *splitter_7;
    QRadioButton *radioStName;
    QRadioButton *radioStNumber;
    QSplitter *splitter_2;
    QLabel *label;
    QLineEdit *edtInput;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnQuery;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QSplitter *splitter_4;
    QLabel *label_2;
    QLineEdit *lineEditID;
    QSplitter *splitter_5;
    QLabel *label_3;
    QLineEdit *lineEditName;
    QSplitter *splitter_6;
    QLabel *label_4;
    QLineEdit *lineEditMajor;
    QSplitter *splitter_3;
    QLabel *label_5;
    QLineEdit *lineEditClass;
    QSpacerItem *verticalSpacer;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ScoreWindow)
    {
        if (ScoreWindow->objectName().isEmpty())
            ScoreWindow->setObjectName(QStringLiteral("ScoreWindow"));
        ScoreWindow->resize(632, 537);
        ScoreWindow->setStyleSheet(QStringLiteral("background-image: url(:/image/background2.png);"));
        actionAdd = new QAction(ScoreWindow);
        actionAdd->setObjectName(QStringLiteral("actionAdd"));
        actionPL = new QAction(ScoreWindow);
        actionPL->setObjectName(QStringLiteral("actionPL"));
        action = new QAction(ScoreWindow);
        action->setObjectName(QStringLiteral("action"));
        actionsql = new QAction(ScoreWindow);
        actionsql->setObjectName(QStringLiteral("actionsql"));
        centralWidget = new QWidget(ScoreWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        horizontalLayout->addWidget(textEdit);

        verticalLayout_4 = new QWidget(centralWidget);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setMinimumSize(QSize(300, 0));
        verticalLayout_4->setMaximumSize(QSize(300, 16777215));
        verticalLayout_3 = new QVBoxLayout(verticalLayout_4);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(2, 0, 0, 0);
        groupBox = new QGroupBox(verticalLayout_4);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        groupBox->setFlat(false);
        groupBox->setCheckable(false);
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        splitter_7 = new QSplitter(groupBox);
        splitter_7->setObjectName(QStringLiteral("splitter_7"));
        splitter_7->setOrientation(Qt::Horizontal);
        radioStName = new QRadioButton(splitter_7);
        radioStName->setObjectName(QStringLiteral("radioStName"));
        splitter_7->addWidget(radioStName);
        radioStNumber = new QRadioButton(splitter_7);
        radioStNumber->setObjectName(QStringLiteral("radioStNumber"));
        splitter_7->addWidget(radioStNumber);

        verticalLayout_2->addWidget(splitter_7);

        splitter_2 = new QSplitter(groupBox);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setOrientation(Qt::Horizontal);
        label = new QLabel(splitter_2);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(55, 0));
        label->setMaximumSize(QSize(55, 16777215));
        splitter_2->addWidget(label);
        edtInput = new QLineEdit(splitter_2);
        edtInput->setObjectName(QStringLiteral("edtInput"));
        splitter_2->addWidget(edtInput);

        verticalLayout_2->addWidget(splitter_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        btnQuery = new QPushButton(groupBox);
        btnQuery->setObjectName(QStringLiteral("btnQuery"));
        btnQuery->setEnabled(true);
        btnQuery->setMinimumSize(QSize(100, 0));
        btnQuery->setMaximumSize(QSize(66, 16777215));

        horizontalLayout_2->addWidget(btnQuery);


        verticalLayout_2->addLayout(horizontalLayout_2);


        verticalLayout_3->addWidget(groupBox);

        groupBox_2 = new QGroupBox(verticalLayout_4);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        splitter_4 = new QSplitter(groupBox_2);
        splitter_4->setObjectName(QStringLiteral("splitter_4"));
        splitter_4->setOrientation(Qt::Horizontal);
        label_2 = new QLabel(splitter_4);
        label_2->setObjectName(QStringLiteral("label_2"));
        splitter_4->addWidget(label_2);
        lineEditID = new QLineEdit(splitter_4);
        lineEditID->setObjectName(QStringLiteral("lineEditID"));
        splitter_4->addWidget(lineEditID);

        verticalLayout->addWidget(splitter_4);

        splitter_5 = new QSplitter(groupBox_2);
        splitter_5->setObjectName(QStringLiteral("splitter_5"));
        splitter_5->setOrientation(Qt::Horizontal);
        label_3 = new QLabel(splitter_5);
        label_3->setObjectName(QStringLiteral("label_3"));
        splitter_5->addWidget(label_3);
        lineEditName = new QLineEdit(splitter_5);
        lineEditName->setObjectName(QStringLiteral("lineEditName"));
        splitter_5->addWidget(lineEditName);

        verticalLayout->addWidget(splitter_5);

        splitter_6 = new QSplitter(groupBox_2);
        splitter_6->setObjectName(QStringLiteral("splitter_6"));
        splitter_6->setOrientation(Qt::Horizontal);
        label_4 = new QLabel(splitter_6);
        label_4->setObjectName(QStringLiteral("label_4"));
        splitter_6->addWidget(label_4);
        lineEditMajor = new QLineEdit(splitter_6);
        lineEditMajor->setObjectName(QStringLiteral("lineEditMajor"));
        splitter_6->addWidget(lineEditMajor);

        verticalLayout->addWidget(splitter_6);

        splitter_3 = new QSplitter(groupBox_2);
        splitter_3->setObjectName(QStringLiteral("splitter_3"));
        splitter_3->setOrientation(Qt::Horizontal);
        label_5 = new QLabel(splitter_3);
        label_5->setObjectName(QStringLiteral("label_5"));
        splitter_3->addWidget(label_5);
        lineEditClass = new QLineEdit(splitter_3);
        lineEditClass->setObjectName(QStringLiteral("lineEditClass"));
        splitter_3->addWidget(lineEditClass);

        verticalLayout->addWidget(splitter_3);


        verticalLayout_3->addWidget(groupBox_2);

        verticalSpacer = new QSpacerItem(17, 48, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        horizontalLayout->addWidget(verticalLayout_4);

        ScoreWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ScoreWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 632, 21));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        ScoreWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ScoreWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ScoreWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ScoreWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ScoreWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(actionAdd);
        menu->addAction(actionPL);
        menu->addAction(action);

        retranslateUi(ScoreWindow);

        QMetaObject::connectSlotsByName(ScoreWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ScoreWindow)
    {
        ScoreWindow->setWindowTitle(QApplication::translate("ScoreWindow", "ScoreWindow", Q_NULLPTR));
        actionAdd->setText(QApplication::translate("ScoreWindow", "\346\267\273\345\212\240\344\270\200\346\235\241\350\256\260\345\275\225", Q_NULLPTR));
        actionPL->setText(QApplication::translate("ScoreWindow", "\346\211\271\351\207\217\345\257\274\345\205\245\346\225\260\346\215\256", Q_NULLPTR));
        action->setText(QApplication::translate("ScoreWindow", "\345\257\274\345\207\272\346\226\207\344\273\266\350\207\263.db", Q_NULLPTR));
        actionsql->setText(QApplication::translate("ScoreWindow", "\345\257\274\345\207\272\350\207\263.sql", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("ScoreWindow", "\346\237\245\350\257\242\351\200\211\351\241\271", Q_NULLPTR));
        radioStName->setText(QApplication::translate("ScoreWindow", "\345\247\223\345\220\215", Q_NULLPTR));
        radioStNumber->setText(QApplication::translate("ScoreWindow", "\345\255\246\345\217\267", Q_NULLPTR));
        label->setText(QApplication::translate("ScoreWindow", "\350\276\223\345\205\245\357\274\232", Q_NULLPTR));
        btnQuery->setText(QApplication::translate("ScoreWindow", "\345\274\200\345\247\213\346\237\245\350\257\242", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("ScoreWindow", "\350\257\246\347\273\206\344\277\241\346\201\257", Q_NULLPTR));
        label_2->setText(QApplication::translate("ScoreWindow", "\345\255\246\345\217\267\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("ScoreWindow", "\345\247\223\345\220\215\357\274\232", Q_NULLPTR));
        label_4->setText(QApplication::translate("ScoreWindow", "\344\270\223\344\270\232\357\274\232", Q_NULLPTR));
        label_5->setText(QApplication::translate("ScoreWindow", "\345\271\264\347\272\247\357\274\232", Q_NULLPTR));
        menu->setTitle(QApplication::translate("ScoreWindow", "\346\226\207\344\273\266", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ScoreWindow: public Ui_ScoreWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCOREWINDOW_H
