#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ModelPart.h"
#include "ModelPartList.h"
#include "qfiledialog.h"
#include "option_dialog.h"

QT_BEGIN_NAMESPACE
namespace Ui {
    
    class MainWindow;

}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {

    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void handleButton();
    void handleButton_2();
    void handleTreeClicked();
    void on_actionOpen_File_triggered();

signals:
    void statusUpdateMessage(const QString& message, int timeout);

private slots:
    void on_actionItem_Options_triggered();

private:
    Ui::MainWindow *ui;
	ModelPartList* partList;

};

#endif // MAINWINDOW_H
