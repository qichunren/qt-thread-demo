#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

#define USE_NOBLOCKING_SERVER

namespace Ui {
class MainWindow;
}

class PaigoServer;
class PaigoServerNoBlocking;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
#ifdef USE_NOBLOCKING_SERVER
    void set_paigo_server(PaigoServerNoBlocking * paigo_server);
#else
    void set_paigo_server(PaigoServer * paigo_server);
#endif
    void start_run_server();

private slots:
    void tick();
    void when_task_finished();
    void on_btn_add_clicked();

    void on_btn_do_long_task_clicked();

private:
    Ui::MainWindow *ui;
#ifdef USE_NOBLOCKING_SERVER
    PaigoServerNoBlocking * _paigo_server;
#else
    PaigoServer * _paigo_server;
#endif
    QTimer tick_timer;
    int i;
    int seconds;
};

#endif // MAINWINDOW_H
