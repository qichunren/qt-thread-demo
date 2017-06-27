#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "paigo_server.h"
#include "paigo_server_no_blocking.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    _paigo_server(NULL),
    i(0),
    seconds(0)
{    
    ui->setupUi(this);
    connect(&tick_timer, SIGNAL(timeout()), this, SLOT(tick()));
    tick_timer.start(1000);

#ifdef USE_NOBLOCKING_SERVER
    PaigoServerNoBlocking * paigo_server = new PaigoServerNoBlocking;
#else
    PaigoServer * paigo_server = new PaigoServer;
#endif
    set_paigo_server(paigo_server);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::tick()
{
    ui->label_seconds->setText(QString::number(++seconds));
}

#ifdef USE_NOBLOCKING_SERVER
void MainWindow::set_paigo_server(PaigoServerNoBlocking * paigo_server)
{
    _paigo_server = paigo_server;
    connect(_paigo_server, SIGNAL(task_finished()), this, SLOT(when_task_finished()));
    qDebug() << "MainWindow set paigo_server";
}
#else
void MainWindow::set_paigo_server(PaigoServer * paigo_server)
{
    _paigo_server = paigo_server;
    qDebug() << "MainWindow set paigo_server";
}
#endif

void MainWindow::when_task_finished()
{
    ui->btn_do_long_task->setDisabled(false);
}

void MainWindow::start_run_server()
{
    if(_paigo_server != NULL)
    {
        qDebug() << "MainWindow start run paigo_server";
        _paigo_server->start_task();
        ui->btn_do_long_task->setDisabled(true);
    }
}

void MainWindow::on_btn_add_clicked()
{
    ui->label->setText(QString::number(++i));
}

void MainWindow::on_btn_do_long_task_clicked()
{
    qDebug() << "Btn do long task";
    start_run_server();
}
