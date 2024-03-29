#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "VRRenderThread.h"
#include <QMainWindow>
#include "ModelPart.h"
#include "ModelPartList.h"
#include "qfiledialog.h"
#include "option_dialog.h"
#include <vtkSmartPointer.h>
#include <vtkRenderer.h>
#include <vtkGenericOpenGLRenderWindow.h>

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
    void updateRender();
    void updateRenderFromTree(const QModelIndex& index);

signals:
    void statusUpdateMessage(const QString& message, int timeout);

private slots:
    void on_actionItem_Options_triggered();

private:
    Ui::MainWindow *ui;
	ModelPartList* partList;

    vtkSmartPointer<vtkRenderer> renderer;
    vtkSmartPointer<vtkGenericOpenGLRenderWindow> renderWindow;

};

#endif // MAINWINDOW_H
