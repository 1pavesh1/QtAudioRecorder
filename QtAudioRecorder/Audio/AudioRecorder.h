#ifndef AUDIORECORDER_H
#define AUDIORECORDER_H

#include <QAudioDevice>
#include <QAudioInput>
#include <QAudioSource>
#include <QMediaRecorder>
#include <QMediaFormat>
#include <QMediaCaptureSession>
#include <QMediaDevices>
#include <QAudioBufferInput>
#include <QByteArray>
#include <QBuffer>
#include <QIODevice>
#include <QUrl>
#include <QDir>
#include <QTimer>
#include "Models/RecordModel.h"

class AudioRecorder : public QObject
{
    Q_OBJECT

private:
    QMediaCaptureSession    *captureSession;
    QMediaRecorder          *mediaRecorder;
    QAudioInput             *audioInput;
    RecordModel             recordModel;
    QMediaFormat            mediaFormat;

    void SaveData() {
        QByteArray  audioData;
        QFile       file(QDir::currentPath() + "/tempRecord.wav");

        if (!file.open(QIODevice::ReadOnly)) {
            qDebug() << "Файл не открыт для чтения";
        }

        qDebug() << audioData.size();

        audioData = file.readAll();

        file.remove();

        qDebug() << audioData.size();

        recordModel.SetRecordData(audioData);
        recordModel.SetTimeRecord(mediaRecorder->duration() / 1000);
    }

    void SetFormat() {
        captureSession->setRecorder(mediaRecorder);

        mediaFormat.setFileFormat(QMediaFormat::Wave);
        mediaFormat.setAudioCodec(QMediaFormat::AudioCodec::Wave);
        mediaRecorder->setMediaFormat(mediaFormat);
        mediaRecorder->setQuality(QMediaRecorder::HighQuality);
        mediaRecorder->setAudioSampleRate(44100);
        mediaRecorder->setAudioBitRate(128000);

        mediaRecorder->setOutputLocation(QUrl::fromLocalFile(QDir::currentPath() + "/tempRecord"));
    }

public:
    AudioRecorder(QObject *parent = nullptr) : QObject(parent) {
        mediaRecorder = new QMediaRecorder(this);
        captureSession = new QMediaCaptureSession(this);

        SetFormat();
    }

    ~AudioRecorder() {

    }

    void StartRecord() {
        mediaRecorder->record();
    }

    void StopRecord() {
        if (mediaRecorder->recorderState() == QMediaRecorder::RecordingState) {
            mediaRecorder->stop();
            QTimer::singleShot(2000, this, &AudioRecorder::SaveData);
        }
    }

    void SetInputDevice(const QAudioDevice &inputDevice) {
        audioInput = new QAudioInput(inputDevice, this);
        captureSession->setAudioInput(audioInput);
    }

    RecordModel GetRecord() const {
        return recordModel;
    }

    QMediaRecorder* GetMediaRecorder() const {
        return mediaRecorder;
    }
};

#endif // AUDIORECORDER_H
