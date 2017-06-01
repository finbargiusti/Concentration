#ifndef HOSTSFILE_H
#define HOSTSFILE_H
#include <set>
#include <string>
using namespace std;


class HostsFile
{
    std::string path = "c:/Windows/System32/Drivers/etc/Hosts";
    set<string> lines;
public:
    HostsFile();
    bool check(string);
    void add(string);
    void cancel(string);
    void sync();
};

#endif // HOSTSFILE_H
