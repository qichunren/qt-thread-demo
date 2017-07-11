#include "paigo_server.h"
#include <QDebug>
#include <QThread>

PaigoServer::PaigoServer(QObject *parent) : QObject(parent)
{
    connect(this, SIGNAL(message(int)), this, SLOT(whenPostMessage(int)));
}


void PaigoServer::post(int ev)
{
    emit message(ev);
}

void PaigoServer::whenPostMessage(int i)
{
    qDebug() << "Event" << i;
    if(i == 1)
    {
        qDebug() << "Start blocking task";
        QThread::msleep(5000);
        qDebug() << "Task finished.";
    }
}

void PaigoServer::start_task()
{

    post(1);
}

