#include <QMessageBox>
#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {

    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::released, this, &MainWindow::handleButton);
    connect(this, &MainWindow::statusUpdateMessage, ui->statusbar, &QStatusBar::showMessage);

}

MainWindow::~MainWindow() {

    delete ui;

}

void MainWindow::handleButton() {

    emit statusUpdateMessage(QString("Add button was clicked"), 0);

}

