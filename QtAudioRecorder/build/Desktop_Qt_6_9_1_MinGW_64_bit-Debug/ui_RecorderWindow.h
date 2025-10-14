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
    QLabel *outputLabel;
    QFrame *frame;
    QPushButton *startAudioButton;
    QPushButton *stopAudioButton;
    QPushButton *addAudioRecordButton;
    QLabel *durationLabel;
    QComboBox *outputComboBox;
    QComboBox *inputComboBox;
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
        audioRecordList->setStyleSheet(QString::fromUtf8("QListWidget \n"
"{\n"
"	outline: 0;\n"
"    background: transparent;\n"
"}\n"
"\n"
"QListWidget::item \n"
"{\n"
"	border: none;\n"
"    background: transparent;\n"
"    padding: 0px;\n"
"    margin: 0px;\n"
"}\n"
"\n"
"QListWidget::item:selected \n"
"{\n"
"	background: transparent;\n"
"	border: none;\n"
"}\n"
"\n"
"QListWidget::item:hover \n"
"{\n"
"	background: transparent;\n"
"}\n"
"\n"
"QPushButton \n"
"{\n"
"    border: none;\n"
"    padding: 4px;\n"
"}\n"
"\n"
"QScrollBar:vertical \n"
"{\n"
"	border: none;\n"
"    background: #f5f5f5;\n"
"    width: 10px;\n"
"    margin: 0px 0px 0px 0px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical \n"
"{\n"
"	background: #c1c1c1;\n"
"    min-height: 20px;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical:hover \n"
"{\n"
"	background: #a8a8a8;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical:pressed\n"
"{\n"
"	background: #787878;\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical \n"
"{\n"
"	border: none;\n"
"    background: none;\n"
"    height: 0px;\n"
"    subc"
                        "ontrol-position: bottom;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::sub-line:vertical \n"
"{\n"
"	border: none;\n"
"	background: none;\n"
"	height: 0px;\n"
"	subcontrol-position: top;\n"
"	subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical \n"
"{\n"
"	background: none;\n"
"}\n"
"\n"
"QScrollBar:horizontal \n"
"{\n"
"	border: none;\n"
"    background: #f5f5f5;\n"
"    height: 10px;\n"
"    margin: 0px 0px 0px 0px;\n"
"}\n"
"\n"
"QScrollBar::handle:horizontal \n"
"{\n"
"    background: #c1c1c1;\n"
"    min-width: 20px;\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QScrollBar::handle:horizontal:hover \n"
"{\n"
"	background: #a8a8a8;\n"
"}\n"
"\n"
"QScrollBar::handle:horizontal:pressed \n"
"{\n"
"	background: #787878;\n"
"}\n"
"\n"
"QScrollBar::add-line:horizontal \n"
"{\n"
"    border: none;\n"
"    background: none;\n"
"    width: 0px;\n"
"    subcontrol-position: right;\n"
"	subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::sub-line:horizontal"
                        " \n"
"{\n"
"    border: none;\n"
"    background: none;\n"
"    width: 0px;\n"
"    subcontrol-position: left;\n"
"	subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::add-page:horizontal, QScrollBar::sub-page:horizontal\n"
"{\n"
"	background: none;\n"
"}"));
        inputLabel = new QLabel(centralwidget);
        inputLabel->setObjectName("inputLabel");
        inputLabel->setGeometry(QRect(10, 10, 191, 21));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(14);
        font.setBold(true);
        inputLabel->setFont(font);
        inputLabel->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	color: black;\n"
"}"));
        outputLabel = new QLabel(centralwidget);
        outputLabel->setObjectName("outputLabel");
        outputLabel->setGeometry(QRect(10, 50, 201, 21));
        outputLabel->setFont(font);
        outputLabel->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	color: black;\n"
"}"));
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(455, 500, 331, 51));
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
        startAudioButton->setGeometry(QRect(280, 1, 48, 48));
        startAudioButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        startAudioButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background-color: rgb(218, 218, 218);\n"
"	border-radius: 24px;\n"
"	border: none;\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/IMG/IMG/AudioMsg48x48.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        startAudioButton->setIcon(icon);
        startAudioButton->setIconSize(QSize(48, 48));
        stopAudioButton = new QPushButton(frame);
        stopAudioButton->setObjectName("stopAudioButton");
        stopAudioButton->setGeometry(QRect(0, 1, 48, 48));
        stopAudioButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        stopAudioButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background-color: rgb(218, 218, 218);\n"
"	border-radius: 24px;\n"
"	border: none;\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/IMG/IMG/CancelPin50x50.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        stopAudioButton->setIcon(icon1);
        stopAudioButton->setIconSize(QSize(48, 48));
        addAudioRecordButton = new QPushButton(frame);
        addAudioRecordButton->setObjectName("addAudioRecordButton");
        addAudioRecordButton->setGeometry(QRect(280, 1, 48, 48));
        addAudioRecordButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        addAudioRecordButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background-color: rgb(218, 218, 218);\n"
"	border-radius: 24px;\n"
"	border: none;\n"
"}"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/IMG/IMG/SendCommentMsgPin60x60.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        addAudioRecordButton->setIcon(icon2);
        addAudioRecordButton->setIconSize(QSize(48, 48));
        durationLabel = new QLabel(frame);
        durationLabel->setObjectName("durationLabel");
        durationLabel->setGeometry(QRect(230, 5, 49, 41));
        durationLabel->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	color: black;\n"
"}"));
        outputComboBox = new QComboBox(centralwidget);
        outputComboBox->setObjectName("outputComboBox");
        outputComboBox->setGeometry(QRect(220, 40, 231, 40));
        outputComboBox->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        outputComboBox->setStyleSheet(QString::fromUtf8("QComboBox \n"
"{\n"
"    border: none;\n"
"    border-bottom: 2px solid #e0e0e0;\n"
"    padding: 12px 0px 8px 0px;\n"
"    background: transparent;\n"
"    color: #333;\n"
"    font-size: 16px;\n"
"}\n"
"\n"
"QComboBox:focus\n"
"{\n"
"    border-bottom-color: #3f51b5;\n"
"}\n"
"\n"
"QComboBox::drop-down \n"
"{\n"
"    border: none;\n"
"    width: 0px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    width: 0px;\n"
"	height: 0px;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView \n"
"{\n"
"    border: none;\n"
"    background: white;\n"
"    selection-background-color: #3f51b5;\n"
"    selection-color: white;\n"
"    font-size: 14px;\n"
"    padding: 8px;\n"
"    border-radius: 4px;\n"
"}"));
        inputComboBox = new QComboBox(centralwidget);
        inputComboBox->setObjectName("inputComboBox");
        inputComboBox->setGeometry(QRect(220, 0, 231, 40));
        inputComboBox->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        inputComboBox->setStyleSheet(QString::fromUtf8("QComboBox \n"
"{\n"
"    border: none;\n"
"    border-bottom: 2px solid #e0e0e0;\n"
"    padding: 12px 0px 8px 0px;\n"
"    background: transparent;\n"
"    color: #333;\n"
"    font-size: 16px;\n"
"}\n"
"\n"
"QComboBox:focus\n"
"{\n"
"    border-bottom-color: #3f51b5;\n"
"}\n"
"\n"
"QComboBox::drop-down \n"
"{\n"
"    border: none;\n"
"    width: 0px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    width: 0px;\n"
"	height: 0px;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView \n"
"{\n"
"    border: none;\n"
"    background: white;\n"
"    selection-background-color: #3f51b5;\n"
"    selection-color: white;\n"
"    font-size: 14px;\n"
"    padding: 8px;\n"
"    border-radius: 4px;\n"
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
        durationLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class RecorderWindow: public Ui_RecorderWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECORDERWINDOW_H
