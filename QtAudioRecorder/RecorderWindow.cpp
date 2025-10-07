#include "RecorderWindow.h"
#include "ui_RecorderWindow.h"

RecorderWindow::RecorderWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::RecorderWindow)
{
    ui->setupUi(this);
}

RecorderWindow::~RecorderWindow()
{
    delete ui;
}
