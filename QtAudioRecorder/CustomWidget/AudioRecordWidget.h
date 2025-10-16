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

    void InitializationInterface() override {
        this->setContentsMargins(10, 8, 10, 8);

        mainLayout = new QVBoxLayout(this);

        QHBoxLayout *mediaLayout = new QHBoxLayout(this);

        QVBoxLayout *sliderLayout = new QVBoxLayout(this);
        sliderLayout->setContentsMargins(0, 12, 0, 0);

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

        sliderLayout->addWidget(timeSlider);
        sliderLayout->addWidget(timeLabel);

        mediaLayout->addWidget(playButton);
        mediaLayout->addLayout(sliderLayout);

        mainLayout->addLayout(mediaLayout);

        setLayout(mainLayout);
    }

    void SetupQCC() override {
        setStyleSheet(R"(
            AudioRecordWidget
            {
                background-color: transparent;
                border-radius: 18px;
            }
            AudioRecordWidget:hover
            {
                background-color: transparent;
            }
            QLabel#timeLabel
            {
                font-size: 12px;
                color: black;
                background: transparent;
            }
            QSlider::groove:horizontal
            {
                background: #e0e0e0;
                height: 6px;
                border-radius: 3px;
                background: transparent;
            }
            QSlider::handle:horizontal
            {
                width: 16px;
                height: 16px;
                margin: -5px 0;
                background: rgb(103, 194, 255);
                border: 2px;
                border-radius: 8px;
            }
            QSlider::sub-page:horizontal
            {
                background: rgb(103, 194, 255);
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
                background: transparent;
            }
            #headerWidget
            {
                background: transparent;
            }
        )");
    }

    void paintEvent(QPaintEvent *event) override {
        QStyleOption opt;
        opt.initFrom(this);
        QPainter p(this);
        p.setRenderHint(QPainter::Antialiasing);
        p.setBrush(QBrush(QColor(218, 218, 218)));
        p.setPen(Qt::NoPen);
        QRect roundedRect = rect().adjusted(10, 15, -10, -15);
        p.drawRoundedRect(roundedRect, 18, 18);
        style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
        QWidget::paintEvent(event);
    }

    void LoadContent() override {
        player          = new QMediaPlayer(this);

        player->setAudioOutput(&audioOutput);

        buffer = new QBuffer();
        buffer->setData(recordModel.GetRecordData());
        if (buffer && !buffer->isOpen()) {
            buffer->open(QIODevice::ReadOnly);
        }

        player->setSourceDevice(buffer);

        setMouseTracking(true);

        ConnectSlots();
    }

    void ConnectSlots() override {
        connect(playButton, &QPushButton::clicked, this, &AudioRecordWidget::PlayButton);
        connect(timeSlider, &QSlider::sliderMoved, this, [this](qint32 value) { TimeSlider(value); });
        connect(player, &QMediaPlayer::durationChanged, this, &AudioRecordWidget::DurationChanged);
        connect(player, &QMediaPlayer::positionChanged, this, &AudioRecordWidget::PositionChanged);
    }

    void UpdateDuration(const qint64 &duration) override {
        if (duration || mediaDuration) {
            QTime currentTime((duration / 3600) % 60, (duration / 60) % 60, duration % 60, (duration * 1000) % 1000);
            QString format = "";
            if (mediaDuration > 3600)
                format = "hh:mm:ss";
            else
                format = "mm:ss";
            timeLabel->setText(currentTime.toString(format));
        }
    }

    void DurationChanged(const qint64 &duration) override {
        mediaDuration = duration / 1000;
        timeSlider->setMaximum(mediaDuration);
    }

    void PositionChanged(const qint64 &position) override {
        if (player->duration() == position) {
            playButton->setIcon(QIcon(":/IMG/IMG/UpdatePin50x50.png"));
        }
        if (!timeSlider->isSliderDown()) {
            timeSlider->setValue(position / 1000);
        }
        UpdateDuration(position / 1000);
    }

    void PlayButton() override {
        if (isPause) {
            isPause = false;
            player->play();
            playButton->setIcon(QIcon(":/IMG/IMG/PausePin48x48.png"));
        }
        else {
            isPause = true;
            player->pause();
            playButton->setIcon(QIcon(":/IMG/IMG/PlayPin48x48.png"));
        }
    }

    void TimeSlider(const qint64 &value) override {
        player->setPosition(value * 1000);
    }

public:
    AudioRecordWidget(const RecordModel &recordModel, const QAudioDevice *audioOutput, QWidget *parent = nullptr)
        : QWidget(parent), recordModel(recordModel), audioOutput(*audioOutput) {
        SetupQCC();
        InitializationInterface();
        LoadContent();
    }

    ~AudioRecordWidget() {
        if (player)
            player->stop();
        if (buffer) {
            buffer->close();
            delete buffer;
        }
    }

    void SetOutputDevice(const QAudioDevice &outputDevice) {
        audioOutput.setDevice(outputDevice);
        player->setAudioOutput(&audioOutput);
    }
};

#endif // AUDIORECORDWIDGET_H
