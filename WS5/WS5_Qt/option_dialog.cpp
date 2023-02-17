#include <QLineEdit>
#include "option_dialog.h"
#include "ui_option_dialog.h"


Option_Dialog::Option_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Option_Dialog)
{
    ui->setupUi(this);
}

Option_Dialog::~Option_Dialog()
{
    delete ui;
}

QString Option_Dialog::getText() {

    return ui->lineEdit->text();

}