#ifndef RECORDERWINDOW_H
#define RECORDERWINDOW_H

#include <QMainWindow>
#include <QAudioDevice>
#include <QMediaDevices>
#include <QAudioInput>
#include <QAudioOutput>

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

private:
    Ui::RecorderWindow *ui;

    QList <QAudioDevice> inputAudioDevice;
    QList <QAudioDevice> outputAudioDevice;

    QList <QAudioDevice> GetInputAudioDevice();
    QList <QAudioDevice> GetOutputAudioDevice();

    void AddDevicesToComboBox();
};

#endif // RECORDERWINDOW_H
