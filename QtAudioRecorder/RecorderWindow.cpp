#include "RecorderWindow.h"
#include "ui_RecorderWindow.h"

#include <QDebug>

RecorderWindow::RecorderWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::RecorderWindow)
{
    ui->setupUi(this);

    // connect(audioRecorder, &QMediaRecorder::durationChanged, this, &RecorderWindow::updateDuration);

    ui->stopAudioButton->setVisible(false);
    ui->addAudioRecordButton->setVisible(false);
    ui->durationLabel->setVisible(false);

    inputAudioDevice    = QMediaDevices::audioInputs();
    outputAudioDevice   = QMediaDevices::audioOutputs();

    AddDevicesToComboBox();


}

RecorderWindow::~RecorderWindow()
{
    delete ui;
}

void RecorderWindow::on_startAudioButton_clicked()
{
    audioRecorder.StartRecord();

    ui->stopAudioButton->setVisible(true);
    ui->addAudioRecordButton->setVisible(true);
    ui->durationLabel->setVisible(true);
    ui->startAudioButton->setVisible(false);
}

void RecorderWindow::updateDuration(qint64 duration)
{
    qint64 time = duration / 1000;

    ui->durationLabel->setText(QString("%1:%2")
                                   .arg(time / 60, 2, 10, QLatin1Char('0'))
                                   .arg(time % 60, 2, 10, QLatin1Char('0')));
}

void RecorderWindow::on_stopAudioButton_clicked()
{
    audioRecorder.StopRecord();

    ui->stopAudioButton->setVisible(false);
    ui->addAudioRecordButton->setVisible(false);
    ui->durationLabel->setVisible(false);
    ui->startAudioButton->setVisible(true);
}

void RecorderWindow::on_addAudioRecordButton_clicked()
{
    audioRecorder.StopRecord();

    ui->stopAudioButton->setVisible(false);
    ui->addAudioRecordButton->setVisible(false);
    ui->durationLabel->setVisible(false);
    ui->startAudioButton->setVisible(true);

    RecordModel recordModel;

    recordModel.SetRecordData(audioRecorder.GetAudioData());
    recordModel.SetTimeRecord(audioRecorder.GetDuration() / 1000);

    qDebug() << audioRecorder.GetAudioData().size();

    recordList.push_back(recordModel);
}

void RecorderWindow::AddDevicesToComboBox()
{
    for (const QAudioDevice &inputDevice : inputAudioDevice)
    {
        ui->inputComboBox->addItem(inputDevice.description());
    }
    for (const QAudioDevice &outputDevice : outputAudioDevice)
    {
        ui->outputComboBox->addItem(outputDevice.description());
    }
}

void RecorderWindow::on_inputComboBox_currentIndexChanged(int index)
{
    audioRecorder.SetInputDevice(inputAudioDevice[index]);
}

void RecorderWindow::on_outputComboBox_currentIndexChanged(int index)
{
    audioRecorder.SetOutputDevice(outputAudioDevice[index]);
}
