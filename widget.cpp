#include "widget.h"
#include "ui_widget.h"
#include "sha256.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("SHA256");
        std::string str;
        ui->label->setText(QString::fromStdString(sha256::hash256_hex_string(str)));
        connect(ui->textEdit,&QTextEdit::textChanged,[=](){
            QString qstr=ui->textEdit->toPlainText();
            std::string str=qstr.toStdString();
            ui->label->setText(QString::fromStdString(sha256::hash256_hex_string(str)));
        });
}

Widget::~Widget()
{
    delete ui;
}

