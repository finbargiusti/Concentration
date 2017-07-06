#include "breaktime.h"
#include <QTimer>
#include "hostsfile.h"

BreakTime::BreakTime()
{
    QTimer::singleShot(900000, []() {BreakTime bt; bt.restore();});
}
void BreakTime::restore()
{
    HostsFile Hsts;
    Hsts.add();
    Hsts.sync();
}
