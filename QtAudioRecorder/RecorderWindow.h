#ifndef RECORDERWINDOW_H
#define RECORDERWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QAudioDevice>
#include <QMediaDevices>
#include <QAudioInput>
#include <QAudioOutput>
#include <QMediaCaptureSession>
#include <QAudioBuffer>
#include <QMediaRecorder>
#include <QMediaFormat>
#include <QBuffer>
#include "Models/RecordModel.h"
#include "Audio/AudioRecorder.h"

QT_BEGIN_NAMESPACE
namespace Ui { class RecorderWindow; }
QT_END_NAMESPACE

class RecorderWindow : public QMainWindow
{
    Q_OBJECT

public:
    RecorderWindow(QWidget *parent = nullptr);
    ~RecorderWindow();

private slots:
    void on_startAudioButton_clicked();
    void on_stopAudioButton_clicked();
    void on_addAudioRecordButton_clicked();
    void updateDuration(qint64 duration);
    void on_inputComboBox_currentIndexChanged(int index);
    void on_outputComboBox_currentIndexChanged(int index);

private:
    Ui::RecorderWindow      *ui;

    QList <QAudioDevice>    inputAudioDevice;
    QList <QAudioDevice>    outputAudioDevice;

    QList <RecordModel>     recordList;

    AudioRecorder           audioRecorder;

    void AddDevicesToComboBox();
};

#endif // RECORDERWINDOW_H
