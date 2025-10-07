#ifndef RECORDERWINDOW_H
#define RECORDERWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class RecorderWindow;
}
QT_END_NAMESPACE

class RecorderWindow : public QMainWindow
{
    Q_OBJECT

public:
    RecorderWindow(QWidget *parent = nullptr);
    ~RecorderWindow();

private:
    Ui::RecorderWindow *ui;
};
#endif // RECORDERWINDOW_H
