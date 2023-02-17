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
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Option_Dialog
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *widget;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
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

    void setupUi(QDialog *Option_Dialog)
    {
        if (Option_Dialog->objectName().isEmpty())
            Option_Dialog->setObjectName("Option_Dialog");
        Option_Dialog->resize(727, 386);
        buttonBox = new QDialogButtonBox(Option_Dialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(270, 240, 171, 41));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        widget = new QWidget(Option_Dialog);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(10, 10, 711, 191));
        verticalLayout_4 = new QVBoxLayout(widget);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        lineEdit = new QLineEdit(widget);
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
        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");

        verticalLayout_2->addWidget(label_3);

        label = new QLabel(widget);
        label->setObjectName("label");

        verticalLayout_2->addWidget(label);

        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");

        verticalLayout_2->addWidget(label_2);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalSlider_3 = new QSlider(widget);
        horizontalSlider_3->setObjectName("horizontalSlider_3");
        horizontalSlider_3->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(horizontalSlider_3);

        horizontalSlider_2 = new QSlider(widget);
        horizontalSlider_2->setObjectName("horizontalSlider_2");
        horizontalSlider_2->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(horizontalSlider_2);

        horizontalSlider = new QSlider(widget);
        horizontalSlider->setObjectName("horizontalSlider");
        horizontalSlider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(horizontalSlider);


        horizontalLayout_2->addLayout(verticalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_4 = new QLabel(widget);
        label_4->setObjectName("label_4");

        verticalLayout_3->addWidget(label_4);

        label_5 = new QLabel(widget);
        label_5->setObjectName("label_5");

        verticalLayout_3->addWidget(label_5);

        label_6 = new QLabel(widget);
        label_6->setObjectName("label_6");

        verticalLayout_3->addWidget(label_6);


        horizontalLayout_2->addLayout(verticalLayout_3);


        verticalLayout_4->addLayout(horizontalLayout_2);


        retranslateUi(Option_Dialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, Option_Dialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, Option_Dialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(Option_Dialog);
    } // setupUi

    void retranslateUi(QDialog *Option_Dialog)
    {
        Option_Dialog->setWindowTitle(QCoreApplication::translate("Option_Dialog", "Dialog", nullptr));
        label_3->setText(QCoreApplication::translate("Option_Dialog", "Red", nullptr));
        label->setText(QCoreApplication::translate("Option_Dialog", "Green", nullptr));
        label_2->setText(QCoreApplication::translate("Option_Dialog", "Blue", nullptr));
        label_4->setText(QCoreApplication::translate("Option_Dialog", "TextLabel", nullptr));
        label_5->setText(QCoreApplication::translate("Option_Dialog", "TextLabel", nullptr));
        label_6->setText(QCoreApplication::translate("Option_Dialog", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Option_Dialog: public Ui_Option_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTION_DIALOG_H
