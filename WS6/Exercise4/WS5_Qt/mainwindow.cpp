#include <QMessageBox>
#include <QStatusBar>
#include <QLineEdit>
#include <QLabel>
#include <QFileDialog>
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "option_dialog.h"
#include <QCheckBox>
#include <vtkPolyDataMapper.h>
#include <vtkCylinderSource.h>
#include <vtkActor.h>
#include <vtkNew.h>
#include <vtkProperty.h>
#include <vtkCamera.h>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {

	ui->setupUi(this);

	/*Link a render window with the Qt widget*/
	renderWindow = vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New();
	ui->vtkWidget->setRenderWindow(renderWindow);

	/*Add a renderer*/
	renderer = vtkSmartPointer<vtkRenderer>::New();
	renderWindow->AddRenderer(renderer);

	/*Create an object and add to renderer*/
	vtkNew<vtkCylinderSource> cylinder;
	cylinder->SetResolution(8);

	vtkNew<vtkPolyDataMapper> cylinderMapper;
	cylinderMapper->SetInputConnection(cylinder->GetOutputPort());

	vtkNew<vtkActor> cylinderActor;
	cylinderActor->SetMapper(cylinderMapper);
	cylinderActor->GetProperty()->SetColor(1., 0., 0.35);
	cylinderActor->RotateX(30.0);
	cylinderActor->RotateY(-45.0);

	renderer->AddActor(cylinderActor);

	/*Reset Camera*/
	renderer->ResetCamera();
	renderer->GetActiveCamera()->Azimuth(30);
	renderer->GetActiveCamera()->Elevation(30);
	renderer->ResetCameraClippingRange();

    connect(ui->pushButton, &QPushButton::released, this, &MainWindow::handleButton);
	connect(ui->pushButton_2, &QPushButton::released, this, &MainWindow::handleButton_2);
    connect(this, &MainWindow::statusUpdateMessage, ui->statusbar, &QStatusBar::showMessage);
	connect(ui->treeView, &QTreeView::clicked, this, &MainWindow::handleTreeClicked);
	
	/* Create / allocate the ModelList */
	this -> partList = new ModelPartList("PartsList");
	
	/* Link it to the treeview in the GUI */
	ui -> treeView -> setModel (this -> partList);
	
	/* Manually create a model tree - there a much better and more flexible ways of doing this,
	e.g. with nested functions. This is just a quick example as a starting point. */
	ModelPart *rootItem = this -> partList -> getRootItem ();
	
	/* Add 3 top level items */
	for (int i = 0; i < 3; i++) {
		
		/* Create strings for both data columns */
		QString name = QString ("TopLevel %1").arg(i);
		QString visible ("true");
		
		/* Create child item */
		ModelPart *childItem = new ModelPart ({name, visible});
		
		/* Append to tree top-level */
		rootItem -> appendChild (childItem);
		
		/* Add 5 sub-items */
		for (int j = 0; j < 5; j++) {
			
			QString name = QString ("Item %1, %2").arg(i).arg(j);
			QString visible ("true");
			
			ModelPart *childChildItem = new ModelPart ({name, visible});
			
			/* Append to parent */
			childItem -> appendChild (childChildItem);
			
		}
		
	}

	ui->treeView->addAction(ui->actionItem_Options);

}

MainWindow::~MainWindow() {

    delete ui;

}

void MainWindow::handleButton() {

    emit statusUpdateMessage(QString("Add button was clicked"), 0);

}

void MainWindow::handleButton_2() {

	Option_Dialog dialog(this);
    QModelIndex index = ui->treeView->currentIndex();
    ModelPart* selectedPart = static_cast<ModelPart*>(index.internalPointer());


	if (dialog.exec() == QDialog::Accepted) {
		
        bool visible = dialog.isVisible();
        selectedPart->set(1,visible);

		emit statusUpdateMessage(dialog.getText(), 0);

	}
	else {

		emit statusUpdateMessage(QString("Dialog rejected"), 0);

	}

}

void MainWindow::handleTreeClicked() {

	// Get the index of the selected item
	QModelIndex index = ui->treeView->currentIndex();

	// Get a point to the item from the index
	ModelPart* selectedPart = static_cast<ModelPart*>(index.internalPointer());

	// In this case, we will retrieve the name string from the internal QVariant data array
	QString text = selectedPart->data(0).toString();

	emit statusUpdateMessage(QString("The selected item is: ")+text, 0);

}

void MainWindow::on_actionOpen_File_triggered() {

	emit statusUpdateMessage(QString("Open File action triggered"), 0);

	QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "C:\\", tr("STL Files(*.stl);;Text Files(*.txt)"));
	QModelIndex index = ui->treeView->currentIndex();

	QFileInfo fileInfo(fileName);
	QString visible("true");

	if (fileInfo.exists() && fileInfo.isFile() && fileInfo.suffix().toLower() == "stl") {

		QModelIndex childPartIndex = partList->appendChild(index, { fileInfo.baseName(), visible });

	}

	emit statusUpdateMessage(QString() + fileName, 0);

}

void MainWindow::on_actionItem_Options_triggered() {

	emit statusUpdateMessage(QString("The selected item is: actionItems_Options triggered"), 0);
	Option_Dialog dialog(this);

	QModelIndex index = ui->treeView->currentIndex();

	ModelPart* selectedPart = static_cast<ModelPart*>(index.internalPointer());

	QString text = selectedPart->data(0).toString();
	int R = selectedPart->getColourR();

	if (dialog.exec() == QDialog::Accepted) {

		QString user_input = dialog.getFileName();
		selectedPart->set(0, user_input);

		QString filename = selectedPart->data(0).toString();
		emit statusUpdateMessage(dialog.getText(), 0);

	}
	else {

		emit statusUpdateMessage(QString("Dialog rejected"), 0);
	}


}

