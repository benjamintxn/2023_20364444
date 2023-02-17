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
    QString getFileName();

public slots:
    void handleSlider_R();
    void handleSlider_G();
    void handleSlider_B();
    int get_rValue();
    int get_gValue();
    int get_bValue();
    bool isVisible();
    

signals: 
    void statusUpdateMessage_R(const QString& message, int timeout);
    void statusUpdateMessage_G(const QString& message, int timeout);
    void statusUpdateMessage_B(const QString& message, int timeout);

private:
    Ui::Option_Dialog *ui;
};

#endif // OPTION_DIALOG_H
