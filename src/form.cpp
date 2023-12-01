#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);

    connect(ui->pushButton, SIGNAL(clicked()),
            this, SLOT(start()));
}

Form::~Form()
{
    delete ui;
}

void Form::start() {
    QString str = ui->str->text();
    QString sub_str = ui->sub_str->text();

    // Поиск подстроки в строке
    int index = str.indexOf(sub_str);
    if (index != -1) {
        ui->result->setText("Подстрока найдена на позиции " + QString::number(index));
    } else {
        ui->result->setText("Подстрока не найдена");
    }
}
