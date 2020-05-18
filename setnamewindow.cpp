#include "setnamewindow.h"

SetNameWindow::SetNameWindow(QWidget* parent)
    : QDialog(parent)
{
    setWindowTitle(tr("Введите название"));
    resize(400, 50);
    nameLineEdit = new QLineEdit();
    acceptButton = new QPushButton(tr("Готово"));
    horizontalLayout = new QHBoxLayout(this);
    horizontalLayout->addWidget(nameLineEdit);
    horizontalLayout->addWidget(acceptButton);

    connect(acceptButton, SIGNAL(clicked()), SLOT(on_acceptButton_clicked()));
    connect(this, SIGNAL(sendName(QString)), parent, SLOT(recieveName(QString)));
}

void SetNameWindow::on_acceptButton_clicked()
{
    emit sendName(nameLineEdit->text());
}

SetNameWindow::~SetNameWindow()
{
    delete nameLineEdit;
    delete acceptButton;
    delete horizontalLayout;
}
