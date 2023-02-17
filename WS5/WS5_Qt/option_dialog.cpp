#include <QLineEdit>
#include <QAbstractSlider>
#include "option_dialog.h"
#include "ui_option_dialog.h"


Option_Dialog::Option_Dialog(QWidget* parent) :
    QDialog(parent),
    ui(new Ui::Option_Dialog) {

    ui->setupUi(this);
    connect(ui->horizontalSlider_3, &QSlider::sliderReleased, this, &Option_Dialog::handleSlider_R);
    connect(ui->horizontalSlider_2, &QSlider::sliderReleased, this, &Option_Dialog::handleSlider_G);
    connect(ui->horizontalSlider, &QSlider::sliderReleased, this, &Option_Dialog::handleSlider_B);

}

void Option_Dialog::handleSlider_R() {

    if (&QAbstractSlider::isSliderDown) {

        int rValue = get_rValue();
        emit statusUpdateMessage_R(QString("Red is: %1").arg(rValue), 0);

    }

}

int Option_Dialog::get_rValue() {

    return ui->horizontalSlider_2->value();

}

void Option_Dialog::handleSlider_G() {

    if (&QAbstractSlider::isSliderDown) {

        int gValue = get_gValue();
        emit statusUpdateMessage_G(QString("Green is: %1").arg(gValue), 0);

    }

}

int Option_Dialog::get_gValue() {

    return ui->horizontalSlider->value();

}

void Option_Dialog::handleSlider_B() {

    if (&QAbstractSlider::isSliderDown) {

        int bValue = get_bValue();
        emit statusUpdateMessage_B(QString("Blue is: %1").arg(bValue), 0);

    }

}

int Option_Dialog::get_bValue() {

    return ui->horizontalSlider_3->value();

}

Option_Dialog::~Option_Dialog()
{
    delete ui;
}

QString Option_Dialog::getText() {

    return ui->lineEdit->text();

}