/********************************************************************************
** Form generated from reading UI file 'option_dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTION_DIALOG_H
#define UI_OPTION_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Option_Dialog
{
public:
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QCheckBox *checkBox;
    QLineEdit *lineEdit;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QLabel *label;
    QLabel *label_2;
    QVBoxLayout *verticalLayout;
    QSlider *horizontalSlider_3;
    QSlider *horizontalSlider_2;
    QSlider *horizontalSlider;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Option_Dialog)
    {
        if (Option_Dialog->objectName().isEmpty())
            Option_Dialog->setObjectName("Option_Dialog");
        Option_Dialog->resize(727, 386);
        verticalLayout_5 = new QVBoxLayout(Option_Dialog);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        checkBox = new QCheckBox(Option_Dialog);
        checkBox->setObjectName("checkBox");

        horizontalLayout->addWidget(checkBox);

        lineEdit = new QLineEdit(Option_Dialog);
        lineEdit->setObjectName("lineEdit");
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy);
        lineEdit->setMinimumSize(QSize(300, 0));

        horizontalLayout->addWidget(lineEdit);


        horizontalLayout_2->addLayout(horizontalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_3 = new QLabel(Option_Dialog);
        label_3->setObjectName("label_3");

        verticalLayout_2->addWidget(label_3);

        label = new QLabel(Option_Dialog);
        label->setObjectName("label");

        verticalLayout_2->addWidget(label);

        label_2 = new QLabel(Option_Dialog);
        label_2->setObjectName("label_2");

        verticalLayout_2->addWidget(label_2);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalSlider_3 = new QSlider(Option_Dialog);
        horizontalSlider_3->setObjectName("horizontalSlider_3");
        horizontalSlider_3->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(horizontalSlider_3);

        horizontalSlider_2 = new QSlider(Option_Dialog);
        horizontalSlider_2->setObjectName("horizontalSlider_2");
        horizontalSlider_2->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(horizontalSlider_2);

        horizontalSlider = new QSlider(Option_Dialog);
        horizontalSlider->setObjectName("horizontalSlider");
        horizontalSlider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(horizontalSlider);


        horizontalLayout_2->addLayout(verticalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_4 = new QLabel(Option_Dialog);
        label_4->setObjectName("label_4");

        verticalLayout_3->addWidget(label_4);

        label_5 = new QLabel(Option_Dialog);
        label_5->setObjectName("label_5");

        verticalLayout_3->addWidget(label_5);

        label_6 = new QLabel(Option_Dialog);
        label_6->setObjectName("label_6");

        verticalLayout_3->addWidget(label_6);


        horizontalLayout_2->addLayout(verticalLayout_3);


        verticalLayout_4->addLayout(horizontalLayout_2);


        verticalLayout_5->addLayout(verticalLayout_4);

        buttonBox = new QDialogButtonBox(Option_Dialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_5->addWidget(buttonBox);


        retranslateUi(Option_Dialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, Option_Dialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, Option_Dialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(Option_Dialog);
    } // setupUi

    void retranslateUi(QDialog *Option_Dialog)
    {
        Option_Dialog->setWindowTitle(QCoreApplication::translate("Option_Dialog", "Dialog", nullptr));
        checkBox->setText(QCoreApplication::translate("Option_Dialog", "Visible", nullptr));
        label_3->setText(QCoreApplication::translate("Option_Dialog", "Red", nullptr));
        label->setText(QCoreApplication::translate("Option_Dialog", "Green", nullptr));
        label_2->setText(QCoreApplication::translate("Option_Dialog", "Blue", nullptr));
        label_4->setText(QString());
        label_5->setText(QString());
        label_6->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Option_Dialog: public Ui_Option_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTION_DIALOG_H
