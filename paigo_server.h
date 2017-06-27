#ifndef PAIGOSERVER_H
#define PAIGOSERVER_H

#include <QObject>

class PaigoServer : public QObject
{
    Q_OBJECT
public:
    explicit PaigoServer(QObject *parent = 0);
    void start_task();
    void post(int event_id);

signals:
    void message(int event_id);

public slots:
    void onPostMessage(int event_id);



};

#endif // PAIGOSERVER_H
