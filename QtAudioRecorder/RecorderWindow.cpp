#include "RecorderWindow.h"
#include "ui_RecorderWindow.h"

RecorderWindow::RecorderWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::RecorderWindow)
{
    ui->setupUi(this);

    ui->stopAudioButton->setVisible(false);
    ui->addAudioRecordButton->setVisible(false);

    inputAudioDevice    = GetInputAudioDevice();
    outputAudioDevice   = GetOutputAudioDevice();

    AddDevicesToComboBox();
}

RecorderWindow::~RecorderWindow()
{
    delete ui;
}

void RecorderWindow::on_startAudioButton_clicked()
{
    ui->stopAudioButton->setVisible(true);
    ui->addAudioRecordButton->setVisible(true);
    ui->startAudioButton->setVisible(false);
}


void RecorderWindow::on_stopAudioButton_clicked()
{
    ui->stopAudioButton->setVisible(false);
    ui->addAudioRecordButton->setVisible(false);
    ui->startAudioButton->setVisible(true);
}


void RecorderWindow::on_addAudioRecordButton_clicked()
{

}

QList <QAudioDevice> RecorderWindow::GetInputAudioDevice()
{
    QMediaDevices devices;
    return devices.audioInputs();
}

QList <QAudioDevice> RecorderWindow::GetOutputAudioDevice()
{
    QMediaDevices devices;
    return devices.audioOutputs();
}

void RecorderWindow::AddDevicesToComboBox()
{
    for (const QAudioDevice inputDevice : inputAudioDevice)
    {
        ui->inputComboBox->addItem(inputDevice.description());
    }
    for (const QAudioDevice outputDevice : outputAudioDevice)
    {
        ui->outputComboBox->addItem(outputDevice.description());
    }
}
