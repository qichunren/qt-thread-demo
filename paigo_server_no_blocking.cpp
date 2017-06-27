#include "paigo_server_no_blocking.h"
#include <QDebug>
#include <QThread>

PaigoServerNoBlocking::PaigoServerNoBlocking(QObject *parent) : QObject(parent), _thread(new QThread(0))
{
    connect(this, SIGNAL(message(int)), this, SLOT(onPostMessage(int)));
}

void PaigoServerNoBlocking::post(int ev)
{
    emit message(ev);
}

void PaigoServerNoBlocking::onPostMessage(int i)
{
    qDebug() << "Event" << i;
    if(i == 1)
    {
        qDebug() << "Start no blocking task";
        QThread::msleep(5000);
        qDebug() << "Task finished.";
        emit task_finished();
    }
}

void PaigoServerNoBlocking::start_task()
{
    moveToThread(_thread);
    _thread->start();

    post(1);
}
