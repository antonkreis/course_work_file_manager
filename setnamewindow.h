#ifndef SETNAMEWINDOW_H
#define SETNAMEWINDOW_H

#include <QWidget>
#include <QDialog>
#include <QLayout>
#include <QPushButton>
#include <QLineEdit>

//#include <widget.h>

class SetNameWindow : public QDialog
{
    Q_OBJECT

    QHBoxLayout* horizontalLayout;
    QPushButton* acceptButton;
    QLineEdit* nameLineEdit;
signals:
    void sendName(QString name);
public:
    SetNameWindow(QWidget* parent);
    ~SetNameWindow();
public slots:
    void on_acceptButton_clicked();
};

#endif // SETNAMEWINDOW_H
