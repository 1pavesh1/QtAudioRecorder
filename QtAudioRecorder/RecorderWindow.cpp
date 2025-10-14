#include "RecorderWindow.h"
#include "ui_RecorderWindow.h"

#include <QDebug>

RecorderWindow::RecorderWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::RecorderWindow)
{
    ui->setupUi(this);

    ui->stopAudioButton->setVisible(false);
    ui->addAudioRecordButton->setVisible(false);
    ui->durationLabel->setVisible(false);

    inputAudioDevice    = QMediaDevices::audioInputs();
    outputAudioDevice   = QMediaDevices::audioOutputs();

    AddDevicesToComboBox();

    audioRecorder.SetInputDevice(inputAudioDevice[ui->outputComboBox->currentIndex()]);

    connect(audioRecorder.GetMediaRecorder(), &QMediaRecorder::durationChanged, this, &RecorderWindow::updateDuration);
}

RecorderWindow::~RecorderWindow()
{
    delete ui;
}

void RecorderWindow::AddRecordToList(const RecordModel &recordModel)
{
    AudioRecordWidget   *recordWidget = new AudioRecordWidget(recordModel, &outputAudioDevice[ui->outputComboBox->currentIndex()]);
    QListWidgetItem     *item         = new QListWidgetItem();

    item->setSizeHint(recordWidget->sizeHint());

    ui->audioRecordList->addItem(item);
    ui->audioRecordList->setItemWidget(item, recordWidget);
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
    ui->durationLabel->setText(QString("%1:%2")
                                   .arg((duration / 1000) / 60, 2, 10, QLatin1Char('0'))
                                   .arg((duration / 1000) % 60, 2, 10, QLatin1Char('0')));
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

    AddRecordToList(audioRecorder.GetRecord());
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
    for (qint16 i = 0; i < ui->audioRecordList->count(); ++i) {
        AudioRecordWidget *audioWidget = qobject_cast<AudioRecordWidget*>(ui->audioRecordList->itemWidget(ui->audioRecordList->item(i)));
        audioWidget->SetOutputDevice(outputAudioDevice[index]);
    }
}
