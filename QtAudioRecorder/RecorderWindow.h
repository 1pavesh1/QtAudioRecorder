#ifndef RECORDERWINDOW_H
#define RECORDERWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QMediaDevices>
#include "Models/RecordModel.h"
#include "Audio/AudioRecorder.h"

QT_BEGIN_NAMESPACE
namespace Ui { class RecorderWindow; }
QT_END_NAMESPACE

class RecorderWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::RecorderWindow      *ui;

    QList <QAudioDevice>    inputAudioDevice;
    QList <QAudioDevice>    outputAudioDevice;

    QList <RecordModel>     recordList;

    AudioRecorder           audioRecorder;

    void AddRecordToList(const RecordModel &recordModel);
    void AddDevicesToComboBox();

private slots:
    void on_startAudioButton_clicked();
    void on_stopAudioButton_clicked();
    void on_addAudioRecordButton_clicked();
    void on_inputComboBox_currentIndexChanged(int index);
    void on_outputComboBox_currentIndexChanged(int index);
    void updateDuration(qint64 duration);

public:
    RecorderWindow(QWidget *parent = nullptr);
    ~RecorderWindow();
};

#endif // RECORDERWINDOW_H
