#ifndef PAIGOSERVERNOBLOCKING_H
#define PAIGOSERVERNOBLOCKING_H

#include <QObject>

class QThread;

class PaigoServerNoBlocking : public QObject
{
    Q_OBJECT
public:
    explicit PaigoServerNoBlocking(QObject *parent = 0);
    void start_task();
    void post(int event_id);

signals:
    void message(int event_id);
    void task_finished();

public slots:
    void whenPostMessage(int event_id);

private:
    QThread * _thread;
};

#endif // PAIGOSERVERNOBLOCKING_H
