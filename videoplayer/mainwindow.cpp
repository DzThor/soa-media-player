#include "mainwindow.h"
#include "ui_mainwindow.h"

bool pulsed=true;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->Play_Pause_Button->setIcon(QIcon("../videoplayer/images/play.png"));
    ui->Stop_Button->setIcon(QIcon("../videoplayer/images/stop.png"));
    ui->Webcam_Button->setIcon(QIcon("../videoplayer/images/webcam.png"));
    ui->Rewind_Button->setIcon(QIcon("../videoplayer/images/rewind.png"));
    ui->Forward_Button->setIcon(QIcon("../videoplayer/images/forward.png"));
    ui->Mute_radioButton->setIcon(QIcon("../videoplayer/images/volume-off-indicator.png"));

    camera = new QCamera(this);
    mediaplayer = new QMediaPlayer(this);

    ui->Rewind_Button->setDisabled(true);
    ui->Forward_Button->setDisabled(true);
    ui->Stop_Button->setDisabled(true);
    ui->horizontalSlider->setHidden(true);


    ui->Rewind_Button->setAutoRepeatInterval(100);
    ui->Forward_Button->setAutoRepeatInterval(100);


    connect(mediaplayer, &QMediaPlayer::durationChanged, ui->horizontalSlider, &QSlider::setMaximum);
    connect(mediaplayer,&QMediaPlayer::positionChanged,ui->horizontalSlider, &QSlider::setValue);
    connect(ui->horizontalSlider, &QSlider::sliderMoved, mediaplayer, &QMediaPlayer::setPosition);
    connect(ui->actionCargar_video, &QAction::triggered, this, &MainWindow::on_Play_Pause_Button_clicked);
    connect(ui->actionIniciar_Webcam, &QAction::triggered, this, &MainWindow::on_Webcam_Button_clicked);
    connect(this, &MainWindow::hideBar, ui->horizontalSlider, &QSlider::hide);
    connect(this, &MainWindow::showBar, ui->horizontalSlider, &QSlider::show);



}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::getMaximized()
{
    return maximized;
}

void MainWindow::setMaximized(bool value)
{
    maximized = value;
}

Qt::WindowState MainWindow::getNormal()
{
    return normal;
}

void MainWindow::on_Webcam_Button_clicked()
{
    if(camera->status() == QCamera::ActiveStatus){
        camera->stop();
    }else{

        //if(mediaplayer->state() == QMediaPlayer::PlayingState){
            ui->Play_Pause_Button->setIcon(QIcon("../videoplayer/images/play.png"));
            ui->Rewind_Button->setDisabled(true);
            ui->Forward_Button->setDisabled(true);
            ui->Stop_Button->setDisabled(true);
            mediaplayer->stop();
            emit hideBar();
        //}

        camera->setViewfinder(ui->widget);
        camera->start();
    }
}


void MainWindow::on_Play_Pause_Button_clicked()
{
    if(QObject::sender() == ui->Play_Pause_Button){
        if(camera->status()==QCamera::ActiveStatus || mediaplayer->state()==QMediaPlayer::StoppedState){

            QString videoname = QFileDialog::getOpenFileName(this, tr("Open File"), "../videoplayer/videos",tr("Video(*.mp4)"));
            if(videoname != NULL){
                mediaplayer->setMedia(QUrl::fromLocalFile(videoname));
                mediaplayer->setVideoOutput(ui->widget);

                ui->Rewind_Button->setEnabled(true);
                ui->Forward_Button->setEnabled(true);
                ui->Stop_Button->setEnabled(true);
                emit showBar();
                ui->Webcam_Button->setDisabled(true);
                ui->Play_Pause_Button->setIcon(QIcon("../videoplayer/images/pause.png"));
                mediaplayer->play();
        }

        }else if(mediaplayer->state()==QMediaPlayer::PlayingState){


            ui->Play_Pause_Button->setIcon(QIcon("../videoplayer/images/play.png"));
            ui->Rewind_Button->setDisabled(false);
            ui->Forward_Button->setDisabled(false);
            ui->Stop_Button->setDisabled(false);
            emit showBar();

            mediaplayer->pause();
            mediaplayer->setPlaybackRate(1);

        }else if(mediaplayer->state() == QMediaPlayer::PausedState){
            ui->Play_Pause_Button->setIcon(QIcon("../videoplayer/images/pause.png"));
            ui->actionCargar_video->setEnabled(true);
            emit showBar();
            mediaplayer->play();
        }else{

            ui->Rewind_Button->setEnabled(true);
            ui->Forward_Button->setEnabled(true);
            ui->Stop_Button->setEnabled(true);
            ui->Play_Pause_Button->setIcon(QIcon("../videoplayer/images/pause.png"));
            emit showBar();

            mediaplayer->play();
        }
    }else{
        QString videoname = QFileDialog::getOpenFileName(this, tr("Open File"), "../videoplayer/videos",tr("Video(*.mp4)"));
        if(videoname != NULL){
            mediaplayer->setMedia(QUrl::fromLocalFile(videoname));
            mediaplayer->setVideoOutput(ui->widget);

            ui->Rewind_Button->setEnabled(true);
            ui->Forward_Button->setEnabled(true);
            ui->Stop_Button->setEnabled(true);
            emit showBar();
            ui->Webcam_Button->setDisabled(true);
            ui->Play_Pause_Button->setIcon(QIcon("../videoplayer/images/pause.png"));
            mediaplayer->play();
        }
    }

}


void MainWindow::on_Stop_Button_clicked()
{
    if(camera->status()==QCamera::ActiveStatus)
        camera->stop();

     mediaplayer->stop();
     emit hideBar();
     ui->Play_Pause_Button->setIcon(QIcon("../videoplayer/images/play.png"));
     ui->Rewind_Button->setDisabled(true);
     ui->Forward_Button->setDisabled(true);
     ui->Stop_Button->setDisabled(true);



}

void MainWindow::on_Forward_Button_clicked()
{
    mediaplayer->setPosition(mediaplayer->position() + (mediaplayer->duration()/10));
}

void MainWindow::on_Rewind_Button_clicked()
{
    mediaplayer->setPosition(mediaplayer->position() - (mediaplayer->duration()/10));

}



void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton){
        if(ui->Stop_Button->isEnabled() == true){
            if(mediaplayer->state() == QMediaPlayer::PlayingState){
                mediaplayer->pause();
                ui->Play_Pause_Button->setIcon(QIcon("../videoplayer/images/play.png"));
            }else{
                mediaplayer->play();
                ui->Play_Pause_Button->setIcon(QIcon("../videoplayer/images/pause.png"));
            }
        }
    }else if(event->button()==Qt::RightButton){
        if(getMaximized() == false){
            this->setWindowState(getNormal());
            setMaximized(true);
        }else{
            this->setWindowState(Qt::WindowFullScreen);
            setMaximized(false);
        }
        //ui->widget->setFullScreen(!ui->widget->isFullScreen());

        //ui->widget->paintEvent();
    }
}

void MainWindow::on_Mute_radioButton_clicked()
{
    if(pulsed){
        pulsed=false;
        mediaplayer->setMuted(true);
    }else{
        pulsed=true;
        mediaplayer->setMuted(false);
    }
}

void MainWindow::on_Rewind_Button_pressed()
{
    ui->Rewind_Button->setAutoRepeat(true);
    mediaplayer->setPosition(mediaplayer->position() - (mediaplayer->duration()/30));
}

void MainWindow::on_Forward_Button_pressed()
{
    ui->Rewind_Button->setAutoRepeat(true);
    mediaplayer->setPosition(mediaplayer->position() + (mediaplayer->duration()/30));
}


void MainWindow::on_actionSalir_triggered()
{
    this->close();
}

