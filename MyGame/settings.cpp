#include "settings.h"
#include "ui_settings.h"
#include <iostream>

Settings::Settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);
    ui->boardWidth->setMinimum(minW);
    ui->boardWidth->setMaximum(maxW);
    ui->boardHeight->setMinimum(minH);
    ui->boardHeight->setMaximum(maxH);
}

Settings::~Settings()
{
    delete ui;
}
