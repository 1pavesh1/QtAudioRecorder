#include "RecorderWindow.h"
#include "ui_RecorderWindow.h"

#include <QDebug>

RecorderWindow::RecorderWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::RecorderWindow)
{
    ui->setupUi(this);

    captureSession  = new QMediaCaptureSession(this);
    audioRecorder   = new QMediaRecorder(this);
    audioInput      = new QAudioInput(this);
    audioOutput     = new QAudioOutput(this);

    buffer = new QBuffer(&audioBuffer);

    captureSession->setAudioInput(audioInput);
    captureSession->setRecorder(audioRecorder);

    connect(audioRecorder, &QMediaRecorder::durationChanged, this, &RecorderWindow::updateDuration);

    QMediaFormat format;
    format.setFileFormat(QMediaFormat::Wave);
    format.setAudioCodec(QMediaFormat::AudioCodec::Wave);
    audioRecorder->setMediaFormat(format);
    audioRecorder->setAudioSampleRate(44100);
    audioRecorder->setAudioBitRate(128000);
    audioRecorder->setQuality(QMediaRecorder::HighQuality);
    audioRecorder->setEncodingMode(QMediaRecorder::ConstantQualityEncoding);

    ui->stopAudioButton->setVisible(false);
    ui->addAudioRecordButton->setVisible(false);
    ui->durationLabel->setVisible(false);

    inputAudioDevice = QMediaDevices::audioInputs();
    outputAudioDevice = QMediaDevices::audioOutputs();

    AddDevicesToComboBox();
}

RecorderWindow::~RecorderWindow()
{
    delete ui;
}

void RecorderWindow::on_startAudioButton_clicked()
{
    audioRecorder->record();

    ui->stopAudioButton->setVisible(true);
    ui->addAudioRecordButton->setVisible(true);
    ui->durationLabel->setVisible(true);
    ui->startAudioButton->setVisible(false);
}

void RecorderWindow::updateDuration(qint64 duration)
{
    if (audioRecorder->error() != QMediaRecorder::NoError) return;

    qint64 time = duration / 1000;

    ui->durationLabel->setText(QString("%1:%2")
                                   .arg(time / 60, 2, 10, QLatin1Char('0'))
                                   .arg(time % 60, 2, 10, QLatin1Char('0')));
}

void RecorderWindow::on_stopAudioButton_clicked()
{
    audioRecorder->stop();

    ui->stopAudioButton->setVisible(false);
    ui->addAudioRecordButton->setVisible(false);
    ui->durationLabel->setVisible(false);
    ui->startAudioButton->setVisible(true);
}

void RecorderWindow::on_addAudioRecordButton_clicked()
{
    audioRecorder->stop();

    ui->stopAudioButton->setVisible(false);
    ui->addAudioRecordButton->setVisible(false);
    ui->durationLabel->setVisible(false);
    ui->startAudioButton->setVisible(true);

    RecordModel recordModel;

    // recordModel.SetRecordData(audioRecorder->metaData());
    recordModel.SetTimeRecord(audioRecorder->duration() / 1000);

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
    audioInput->setDevice(inputAudioDevice[index]);
}

void RecorderWindow::on_outputComboBox_currentIndexChanged(int index)
{
    audioOutput->setDevice(outputAudioDevice[index]);
}

