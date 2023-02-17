#ifndef OPTION_DIALOG_H
#define OPTION_DIALOG_H

#include <QDialog>
#include <QLineEdit>

namespace Ui {
class Option_Dialog;
}

class Option_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Option_Dialog(QWidget *parent = nullptr);
    ~Option_Dialog();

    QString getText();

private:
    Ui::Option_Dialog *ui;
};

#endif // OPTION_DIALOG_H
