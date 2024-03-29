#include <QMessageBox>
#include <QStatusBar>
#include <QLineEdit>
#include <QLabel>
#include <QFileDialog>
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "option_dialog.h"
#include <QCheckBox>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {

    ui->setupUi(this);
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

	QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "C:\\", tr("STL Files(*.stl);;Text Files(*.txt)"));

	emit statusUpdateMessage(QString("Open File action triggered"), 0);

	QFile file(fileName);
	if (file.open(QIODevice::ReadOnly)) {

		emit statusUpdateMessage(QString("File has opened"), 0);

	}
	else {

		emit statusUpdateMessage(QString("Failed to open file"), 0);

	}

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

