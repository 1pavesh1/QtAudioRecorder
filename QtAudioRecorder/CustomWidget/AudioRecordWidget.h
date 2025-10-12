#ifndef AUDIORECORDWIDGET_H
#define AUDIORECORDWIDGET_H

#include <QWidget>
#include "AbstractClasses/CustomMediaWidget.h"
#include "AbstractClasses/CustomWidget.h"
#include "Models/RecordModel.h"

class AudioRecordWidget : public QWidget, public CustomWidget, public CustomMediaWidget
{
    Q_OBJECT
private:
    RecordModel     recordModel;
    QAudioOutput    audioOutput;
    QVBoxLayout     *mainLayout;
    QHBoxLayout     *headerLayout;

    void InitializationInterface() override
    {
        mainLayout = new QVBoxLayout(this);
        mainLayout->setContentsMargins(0, 0, 0, 0);
        mainLayout->setSpacing(8);

        timeSlider = new QSlider(Qt::Horizontal);
        timeSlider->setRange(0, 0);
        timeSlider->setFixedHeight(4);

        playButton = new QPushButton();
        playButton->setCursor(Qt::PointingHandCursor);
        playButton->setIcon(QIcon(":/IMG/IMG/PlayPin48x48.png"));
        playButton->setFixedSize(32, 32);
        playButton->setIconSize(QSize(24, 24));

        timeLabel = new QLabel("00:00");
        timeLabel->setObjectName("timeLabel");
        timeLabel->setFixedWidth(100);

        mainLayout->addWidget(playButton);
        mainLayout->addWidget(timeSlider);
        mainLayout->addWidget(timeLabel);

        setLayout(mainLayout);
    }

    void SetupQCC() override
    {
        setStyleSheet(R"(
            QLabel
            {
                color: #2a5885;
                font-size: 13px;
                background: transparent;
            }
            QLabel#fileName
            {
                font-size: 16px;
                color: black;
                background: transparent;
                padding: 5px;
            }
            QLabel#timeLabel
            {
                font-size: 12px;
                color: black;
            }
            QSlider::groove:horizontal
            {
                background: #e0e0e0;
                height: 6px;
                border-radius: 3px;
            }
            QSlider::handle:horizontal
            {
                width: 16px;
                height: 16px;
                margin: -5px 0;
                background: rgb(182, 146, 255);
                border: 2px;
                border-radius: 8px;
            }
            QSlider::sub-page:horizontal
            {
                background: rgb(182, 146, 255);
                border-radius: 3px;
            }
            QPushButton
            {
                border: none;
                padding: 8px 12px;
                min-width: 20px;
                background: transparent;
            }
            QPushButton:hover
            {
                background: transparent;
            }
            #mediaContainer
            {
                background: rgba(255, 255, 255, 180);
                border-radius: 6px;
            }
            #headerWidget
            {
                background: transparent;
            }
        )");
    }

    void LoadContent() override
    {
        player          = new QMediaPlayer(this);

        player->setAudioOutput(&audioOutput);

        buffer = new QBuffer();
        buffer->setData(recordModel.GetRecordData());
        if (buffer && !buffer->isOpen())
        {
            buffer->open(QIODevice::ReadOnly);
        }

        player->setSourceDevice(buffer);

        setMouseTracking(true);

        ConnectSlots();
    }

    void ConnectSlots() override
    {
        connect(playButton, &QPushButton::clicked, this, &AudioRecordWidget::PlayButton);
        connect(timeSlider, &QSlider::sliderMoved, this, [this](qint32 value) { TimeSlider(value); });
        connect(player, &QMediaPlayer::durationChanged, this, &AudioRecordWidget::DurationChanged);
        connect(player, &QMediaPlayer::positionChanged, this, &AudioRecordWidget::PositionChanged);
    }

    void UpdateDuration(const qint64 &duration) override
    {
        if (duration || mediaDuration)
        {
            QTime currentTime((duration / 3600) % 60, (duration / 60) % 60, duration % 60, (duration * 1000) % 1000);
            QTime totalTime((mediaDuration / 3600) % 60, (mediaDuration / 60) % 60, mediaDuration % 60, (mediaDuration * 1000) % 1000);
            QString format = "";
            if (mediaDuration > 3600)
                format = "hh:mm:ss";
            else
                format = "mm:ss";
            timeLabel->setText(currentTime.toString(format));
        }
    }

    void DurationChanged(const qint64 &duration) override
    {
        mediaDuration = duration / 1000;
        timeSlider->setMaximum(mediaDuration);
    }

    void PositionChanged(const qint64 &position) override
    {
        if (!timeSlider->isSliderDown())
            timeSlider->setValue(position / 1000);
        UpdateDuration(position / 1000);
    }

    void PlayButton() override
    {
        if (isPause)
        {
            isPause = false;
            player->play();
            playButton->setIcon(QIcon(":/IMG/IMG/PausePin48x48.png"));
        }
        else
        {
            isPause = true;
            player->pause();
            playButton->setIcon(QIcon(":/IMG/IMG/PlayPin48x48.png"));
        }
    }

    void TimeSlider(const qint64 &value) override
    {
        player->setPosition(value * 1000);
    }

public:
    AudioRecordWidget(const RecordModel &recordModel, const QAudioDevice *audioOutput, QWidget *parent = nullptr)
        : QWidget(parent), recordModel(recordModel), audioOutput(*audioOutput)
    {
        SetupQCC();
        InitializationInterface();
        LoadContent();
    }

    ~AudioRecordWidget()
    {
        if (player)
            player->stop();
        if (buffer)
        {
            buffer->close();
            delete buffer;
        }
    }
};

#endif // AUDIORECORDWIDGET_H
