#ifndef CUSTOMWIDGET_H
#define CUSTOMWIDGET_H

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMenu>
#include <QLabel>
#include <QPixmap>
#include <QDateTime>
#include <QMouseEvent>
#include <QSpacerItem>
#include <QPainter>
#include <QPushButton>
#include <QStyleOption>
#include <QGridLayout>
#include <QFileDialog>
#include <QFrame>
#include <QStyle>
#include <QTemporaryFile>

class CustomWidget
{
public:
    virtual void InitializationInterface() = 0;
    virtual void SetupQCC() = 0;
    virtual void LoadContent() = 0;
};

#endif // CUSTOMWIDGET_H
