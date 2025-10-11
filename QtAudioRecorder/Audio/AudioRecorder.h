#ifndef AUDIORECORDER_H
#define AUDIORECORDER_H

#include <QAudioDevice>
#include <QAudioInput>
#include <QAudioOutput>
#include <QAudioSource>
#include <QMediaRecorder>
#include <QMediaFormat>
#include <QMediaCaptureSession>
#include <QMediaDevices>
#include <QByteArray>
#include <QBuffer>
#include <QIODevice>

class AudioRecorder : public QObject
{
    Q_OBJECT

private:
    QMediaRecorder          *audioRecorder;
    QMediaCaptureSession    *captureSession;
    QAudioSource            *audioSource;
    QBuffer                 *audioBuffer;
    QAudioDevice            audioInput;
    QAudioDevice            audioOutput;
    QAudioFormat            format;
    QByteArray              audioData;

public:
    AudioRecorder(QObject *parent = nullptr) : QObject(parent)
    {
        captureSession  = new QMediaCaptureSession();
        audioRecorder   = new QMediaRecorder();
        audioBuffer     = new QBuffer();

        audioBuffer->open(QIODevice::ReadWrite);
    }

    ~AudioRecorder()
    {
        if (audioBuffer) {
            audioBuffer->close();
            delete audioBuffer;
        }
    }

    void StartRecord()
    {
        audioData.clear();
        audioBuffer->buffer().clear();
        audioBuffer->seek(0);

        format.setSampleRate(44100);
        format.setChannelCount(1);
        format.setSampleFormat(QAudioFormat::Int16);

        audioSource = new QAudioSource(audioInput, format, this);

        audioSource->start(audioBuffer);
    }

    void StopRecord()
    {
        if (audioSource)
        {
            audioSource->stop();
            audioData = audioBuffer->buffer();
            delete audioSource;
        }
    }

    void SetInputDevice(const QAudioDevice &inputDevice)
    {
        audioInput = inputDevice;
    }

    void SetOutputDevice(const QAudioDevice &outputDevice)
    {
        audioOutput = outputDevice;
    }

    QByteArray GetAudioData()
    {
        return audioData;
    }

    qint64 GetDuration()
    {
        return audioRecorder->duration();
    }
};

#endif // AUDIORECORDER_H
