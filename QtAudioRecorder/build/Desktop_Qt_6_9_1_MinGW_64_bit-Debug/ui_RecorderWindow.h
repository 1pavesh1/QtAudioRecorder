/********************************************************************************
** Form generated from reading UI file 'RecorderWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECORDERWINDOW_H
#define UI_RECORDERWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RecorderWindow
{
public:
    QWidget *centralwidget;
    QListWidget *audioRecordList;
    QLabel *inputLabel;
    QComboBox *inputComboBox;
    QComboBox *outputComboBox;
    QLabel *outputLabel;
    QFrame *frame;
    QPushButton *startAudioButton;
    QPushButton *stopAudioButton;
    QPushButton *addAudioRecordButton;
    QLabel *timeAudioRecordLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *RecorderWindow)
    {
        if (RecorderWindow->objectName().isEmpty())
            RecorderWindow->setObjectName("RecorderWindow");
        RecorderWindow->resize(800, 600);
        RecorderWindow->setStyleSheet(QString::fromUtf8("background-color: white;"));
        centralwidget = new QWidget(RecorderWindow);
        centralwidget->setObjectName("centralwidget");
        audioRecordList = new QListWidget(centralwidget);
        audioRecordList->setObjectName("audioRecordList");
        audioRecordList->setGeometry(QRect(20, 80, 431, 471));
        audioRecordList->setStyleSheet(QString::fromUtf8("QListWidget\n"
"{\n"
"\n"
"}"));
        inputLabel = new QLabel(centralwidget);
        inputLabel->setObjectName("inputLabel");
        inputLabel->setGeometry(QRect(20, 10, 191, 21));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(14);
        font.setBold(true);
        inputLabel->setFont(font);
        inputLabel->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	color: black;\n"
"}"));
        inputComboBox = new QComboBox(centralwidget);
        inputComboBox->setObjectName("inputComboBox");
        inputComboBox->setGeometry(QRect(222, 13, 231, 24));
        inputComboBox->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        outputComboBox = new QComboBox(centralwidget);
        outputComboBox->setObjectName("outputComboBox");
        outputComboBox->setGeometry(QRect(222, 43, 231, 24));
        outputComboBox->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        outputLabel = new QLabel(centralwidget);
        outputLabel->setObjectName("outputLabel");
        outputLabel->setGeometry(QRect(20, 45, 201, 21));
        outputLabel->setFont(font);
        outputLabel->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	color: black;\n"
"}"));
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(460, 500, 331, 51));
        frame->setStyleSheet(QString::fromUtf8("QFrame\n"
"{\n"
"	background-color: rgb(218, 218, 218);\n"
"	border-radius: 20px;\n"
"	border: none;\n"
"}"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        startAudioButton = new QPushButton(frame);
        startAudioButton->setObjectName("startAudioButton");
        startAudioButton->setGeometry(QRect(280, 0, 48, 48));
        startAudioButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        startAudioButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border-radius: 24px;\n"
"	border: none;\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/IMG/IMG/AudioMsg48x48.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        startAudioButton->setIcon(icon);
        startAudioButton->setIconSize(QSize(48, 48));
        stopAudioButton = new QPushButton(frame);
        stopAudioButton->setObjectName("stopAudioButton");
        stopAudioButton->setGeometry(QRect(0, 0, 48, 48));
        stopAudioButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        stopAudioButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border-radius: 24px;\n"
"	border: none;\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/IMG/IMG/CancelPin50x50.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        stopAudioButton->setIcon(icon1);
        stopAudioButton->setIconSize(QSize(48, 48));
        addAudioRecordButton = new QPushButton(frame);
        addAudioRecordButton->setObjectName("addAudioRecordButton");
        addAudioRecordButton->setGeometry(QRect(280, 0, 48, 48));
        addAudioRecordButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        addAudioRecordButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border-radius: 24px;\n"
"	border: none;\n"
"}"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/IMG/IMG/SendCommentMsgPin60x60.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        addAudioRecordButton->setIcon(icon2);
        addAudioRecordButton->setIconSize(QSize(48, 48));
        timeAudioRecordLabel = new QLabel(frame);
        timeAudioRecordLabel->setObjectName("timeAudioRecordLabel");
        timeAudioRecordLabel->setGeometry(QRect(230, 5, 49, 41));
        timeAudioRecordLabel->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	color: black;\n"
"}"));
        RecorderWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(RecorderWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        RecorderWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(RecorderWindow);
        statusbar->setObjectName("statusbar");
        RecorderWindow->setStatusBar(statusbar);

        retranslateUi(RecorderWindow);

        QMetaObject::connectSlotsByName(RecorderWindow);
    } // setupUi

    void retranslateUi(QMainWindow *RecorderWindow)
    {
        RecorderWindow->setWindowTitle(QCoreApplication::translate("RecorderWindow", "\320\227\320\260\320\277\320\270\321\201\321\214 \320\260\321\203\320\264\320\270\320\276", nullptr));
        inputLabel->setText(QCoreApplication::translate("RecorderWindow", "\320\243\321\201\321\202\321\200\320\276\320\271\321\201\321\202\320\262\320\260 \320\262\320\262\320\276\320\264\320\260:", nullptr));
        outputLabel->setText(QCoreApplication::translate("RecorderWindow", "\320\243\321\201\321\202\321\200\320\276\320\271\321\201\321\202\320\262\320\260 \320\262\321\213\320\262\320\276\320\264\320\260:", nullptr));
        startAudioButton->setText(QString());
        stopAudioButton->setText(QString());
        addAudioRecordButton->setText(QString());
        timeAudioRecordLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class RecorderWindow: public Ui_RecorderWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECORDERWINDOW_H
