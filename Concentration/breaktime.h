#ifndef BREAKTIME_H
#define BREAKTIME_H

#include <QTimer>

class BreakTime : public QObject
{
    Q_OBJECT
public:
    BreakTime();
public Q_SLOTS:
    void restore();
};

#endif // BREAKTIME_H
