#include <QLineEdit>
#include <QAbstractSlider>
#include "option_dialog.h"
#include "ui_option_dialog.h"
#include <QCheckBox>


Option_Dialog::Option_Dialog(QWidget* parent) :
    QDialog(parent),
    ui(new Ui::Option_Dialog) {

    ui->setupUi(this);
    connect(ui->horizontalSlider_3, &QSlider::sliderReleased, this, &Option_Dialog::handleSlider_R);
    connect(ui->horizontalSlider_2, &QSlider::sliderReleased, this, &Option_Dialog::handleSlider_G);
    connect(ui->horizontalSlider, &QSlider::sliderReleased, this, &Option_Dialog::handleSlider_B);
    connect(this, &Option_Dialog::statusUpdateMessage_R, ui->label_4, &QLabel::setText);
    connect(this, &Option_Dialog::statusUpdateMessage_G, ui->label_5, &QLabel::setText);
    connect(this, &Option_Dialog::statusUpdateMessage_B, ui->label_6, &QLabel::setText);

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

QString Option_Dialog::getFileName() {

    return ui->lineEdit->text();

}

Option_Dialog::~Option_Dialog()
{
    delete ui;
}

QString Option_Dialog::getText() {

    return ui->lineEdit->text();

}

bool Option_Dialog::isVisible() {

    return ui->checkBox->checkState();
}
