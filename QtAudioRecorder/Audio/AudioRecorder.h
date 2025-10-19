#ifndef AUDIORECORDER_H
#define AUDIORECORDER_H

#include <QAudioDevice>
#include <QAudioInput>
#include <QMediaRecorder>
#include <QMediaFormat>
#include <QMediaCaptureSession>
#include <QByteArray>
#include <QUrl>
#include <QDir>
#include <QThread>
#include "Models/RecordModel.h"

class AudioRecorder : public QObject
{
    Q_OBJECT

private:
    QMediaCaptureSession    *captureSession;
    QMediaRecorder          *mediaRecorder;
    QAudioInput             *audioInput;

    void SetFormat() {
        QMediaFormat mediaFormat;

        captureSession->setRecorder(mediaRecorder);

        mediaFormat.setFileFormat(QMediaFormat::Wave);
        mediaFormat.setAudioCodec(QMediaFormat::AudioCodec::Wave);
        mediaRecorder->setMediaFormat(mediaFormat);
        mediaRecorder->setQuality(QMediaRecorder::HighQuality);
        mediaRecorder->setAudioSampleRate(44100);
        mediaRecorder->setAudioBitRate(128000);

        mediaRecorder->setOutputLocation(QUrl::fromLocalFile(QDir::currentPath() + "/tempRecord"));
    }

    QByteArray GetRecordData() {
        QByteArray  audioData;
        QFile       file(QDir::currentPath() + "/tempRecord.wav");

        if (!file.open(QIODevice::ReadOnly)) {
            qDebug() << "Файл не открыт для чтения";
        }

        QThread::msleep(500);

        audioData = file.readAll();

        file.remove();

        return audioData;
    }

public:
    AudioRecorder(QObject *parent = nullptr) : QObject(parent) {
        mediaRecorder = new QMediaRecorder(this);
        captureSession = new QMediaCaptureSession(this);

        SetFormat();
    }

    ~AudioRecorder() {
        delete audioInput;
        delete mediaRecorder;
        delete captureSession;
    }

    void StartRecord() {
        mediaRecorder->record();
    }

    void StopRecord() {
        if (mediaRecorder->recorderState() == QMediaRecorder::RecordingState) {
            mediaRecorder->stop();
        }
    }

    void SetInputDevice(const QAudioDevice &inputDevice) {
        audioInput = new QAudioInput(inputDevice, this);
        captureSession->setAudioInput(audioInput);
    }

    RecordModel GetRecord() {
        RecordModel recordModel(GetRecordData(),
                                mediaRecorder->duration());
        return recordModel;
    }

    QMediaRecorder* GetMediaRecorder() const {
        return mediaRecorder;
    }
};

#endif // AUDIORECORDER_H
