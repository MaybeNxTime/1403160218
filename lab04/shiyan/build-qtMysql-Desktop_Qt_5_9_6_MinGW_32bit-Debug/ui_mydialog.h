/********************************************************************************
** Form generated from reading UI file 'mydialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYDIALOG_H
#define UI_MYDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_MYDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *edtName;
    QLabel *label_2;
    QLineEdit *edtID;
    QLabel *label_3;
    QComboBox *cbMajor;
    QLabel *label_4;
    QComboBox *cbClass;
    QLabel *label_9;
    QComboBox *cbYear;
    QLabel *label_10;
    QLineEdit *edtPhone;
    QLabel *label1;
    QLineEdit *score1;
    QLabel *label2;
    QLineEdit *score2;
    QLabel *label3;
    QComboBox *cbscore1;
    QLabel *label4;
    QComboBox *cbscore2;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *MYDialog)
    {
        if (MYDialog->objectName().isEmpty())
            MYDialog->setObjectName(QStringLiteral("MYDialog"));
        MYDialog->resize(271, 332);
        MYDialog->setStyleSheet(QStringLiteral("background-image: url(:/image/background2.png);"));
        verticalLayout = new QVBoxLayout(MYDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(MYDialog);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        edtName = new QLineEdit(MYDialog);
        edtName->setObjectName(QStringLiteral("edtName"));

        gridLayout->addWidget(edtName, 0, 1, 1, 1);

        label_2 = new QLabel(MYDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        edtID = new QLineEdit(MYDialog);
        edtID->setObjectName(QStringLiteral("edtID"));

        gridLayout->addWidget(edtID, 1, 1, 1, 1);

        label_3 = new QLabel(MYDialog);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        cbMajor = new QComboBox(MYDialog);
        cbMajor->setObjectName(QStringLiteral("cbMajor"));

        gridLayout->addWidget(cbMajor, 2, 1, 1, 1);

        label_4 = new QLabel(MYDialog);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        cbClass = new QComboBox(MYDialog);
        cbClass->setObjectName(QStringLiteral("cbClass"));

        gridLayout->addWidget(cbClass, 3, 1, 1, 1);

        label_9 = new QLabel(MYDialog);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout->addWidget(label_9, 4, 0, 1, 1);

        cbYear = new QComboBox(MYDialog);
        cbYear->setObjectName(QStringLiteral("cbYear"));

        gridLayout->addWidget(cbYear, 4, 1, 1, 1);

        label_10 = new QLabel(MYDialog);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout->addWidget(label_10, 5, 0, 1, 1);

        edtPhone = new QLineEdit(MYDialog);
        edtPhone->setObjectName(QStringLiteral("edtPhone"));

        gridLayout->addWidget(edtPhone, 5, 1, 1, 1);

        label1 = new QLabel(MYDialog);
        label1->setObjectName(QStringLiteral("label1"));

        gridLayout->addWidget(label1, 6, 0, 1, 1);

        score1 = new QLineEdit(MYDialog);
        score1->setObjectName(QStringLiteral("score1"));

        gridLayout->addWidget(score1, 6, 1, 1, 1);

        label2 = new QLabel(MYDialog);
        label2->setObjectName(QStringLiteral("label2"));

        gridLayout->addWidget(label2, 7, 0, 1, 1);

        score2 = new QLineEdit(MYDialog);
        score2->setObjectName(QStringLiteral("score2"));

        gridLayout->addWidget(score2, 7, 1, 1, 1);

        label3 = new QLabel(MYDialog);
        label3->setObjectName(QStringLiteral("label3"));

        gridLayout->addWidget(label3, 8, 0, 1, 1);

        cbscore1 = new QComboBox(MYDialog);
        cbscore1->setObjectName(QStringLiteral("cbscore1"));

        gridLayout->addWidget(cbscore1, 8, 1, 1, 1);

        label4 = new QLabel(MYDialog);
        label4->setObjectName(QStringLiteral("label4"));

        gridLayout->addWidget(label4, 9, 0, 1, 1);

        cbscore2 = new QComboBox(MYDialog);
        cbscore2->setObjectName(QStringLiteral("cbscore2"));

        gridLayout->addWidget(cbscore2, 9, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        buttonBox = new QDialogButtonBox(MYDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(MYDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), MYDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), MYDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(MYDialog);
    } // setupUi

    void retranslateUi(QDialog *MYDialog)
    {
        MYDialog->setWindowTitle(QApplication::translate("MYDialog", "\346\267\273\345\212\240\344\270\200\346\235\241\350\256\260\345\275\225", Q_NULLPTR));
        label->setText(QApplication::translate("MYDialog", "\345\247\223\345\220\215", Q_NULLPTR));
        label_2->setText(QApplication::translate("MYDialog", "\345\255\246\345\217\267", Q_NULLPTR));
        label_3->setText(QApplication::translate("MYDialog", "\344\270\223\344\270\232", Q_NULLPTR));
        cbMajor->clear();
        cbMajor->insertItems(0, QStringList()
         << QApplication::translate("MYDialog", "\351\200\232\344\277\241\345\267\245\347\250\213", Q_NULLPTR)
        );
        label_4->setText(QApplication::translate("MYDialog", "\347\217\255\347\272\247", Q_NULLPTR));
        label_9->setText(QApplication::translate("MYDialog", "\345\205\245\345\255\246\345\271\264\344\273\275", Q_NULLPTR));
        cbYear->clear();
        cbYear->insertItems(0, QStringList()
         << QApplication::translate("MYDialog", "2015", Q_NULLPTR)
         << QApplication::translate("MYDialog", "2016", Q_NULLPTR)
         << QApplication::translate("MYDialog", "2017", Q_NULLPTR)
         << QApplication::translate("MYDialog", "2018", Q_NULLPTR)
        );
        label_10->setText(QApplication::translate("MYDialog", "\350\201\224\347\263\273\347\224\265\350\257\235", Q_NULLPTR));
        label1->setText(QApplication::translate("MYDialog", "\351\200\232\344\277\241\345\216\237\347\220\206", Q_NULLPTR));
        label2->setText(QApplication::translate("MYDialog", "\345\276\256\346\263\242\346\212\200\346\234\257\344\270\216\345\244\251\347\272\277", Q_NULLPTR));
        label3->setText(QApplication::translate("MYDialog", "\345\265\214\345\205\245\345\274\217\347\263\273\347\273\237\350\256\276\350\256\241", Q_NULLPTR));
        cbscore1->clear();
        cbscore1->insertItems(0, QStringList()
         << QApplication::translate("MYDialog", "A", Q_NULLPTR)
         << QApplication::translate("MYDialog", "B", Q_NULLPTR)
         << QApplication::translate("MYDialog", "C", Q_NULLPTR)
         << QApplication::translate("MYDialog", "D", Q_NULLPTR)
         << QApplication::translate("MYDialog", "E", Q_NULLPTR)
        );
        label4->setText(QApplication::translate("MYDialog", "\347\247\221\346\212\200\350\213\261\350\257\255", Q_NULLPTR));
        cbscore2->clear();
        cbscore2->insertItems(0, QStringList()
         << QApplication::translate("MYDialog", "A", Q_NULLPTR)
         << QApplication::translate("MYDialog", "B", Q_NULLPTR)
         << QApplication::translate("MYDialog", "C", Q_NULLPTR)
         << QApplication::translate("MYDialog", "D", Q_NULLPTR)
         << QApplication::translate("MYDialog", "E", Q_NULLPTR)
        );
    } // retranslateUi

};

namespace Ui {
    class MYDialog: public Ui_MYDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYDIALOG_H
