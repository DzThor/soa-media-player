#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCamera>
#include <QMediaPlayer>
#include <QFileDialog>
#include <QMouseEvent>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    bool getMaximized();
    void setMaximized(bool value);
    Qt::WindowState getNormal();

private slots:
    void on_Webcam_Button_clicked();

    void on_Play_Pause_Button_clicked();

    void on_Stop_Button_clicked();

    void on_Forward_Button_clicked();

    void on_Rewind_Button_clicked();

    void mousePressEvent(QMouseEvent *event);

    void on_Mute_radioButton_clicked();

    void on_Rewind_Button_pressed();

    void on_Forward_Button_pressed();

    void on_actionSalir_triggered();

private:
    Ui::MainWindow *ui;
    QCamera* camera;
    QMediaPlayer* mediaplayer;
    bool maximized;
    Qt::WindowState normal;

    void isExpanded();


signals:
    void hideBar();
    void showBar();

};

#endif // MAINWINDOW_H
