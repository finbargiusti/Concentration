#ifndef HOSTSFILE_H
#define HOSTSFILE_H
#include <set>
#include <vector>
#include <string>
using namespace std;


class HostsFile
{
    #if (defined (_WIN32) || defined (_WIN64))
        std::string path = "c:/Windows/System32/Drivers/etc/Hosts";
    #else
        std::string path = "/home/finbargiusti/hosts";
    #endif
    std::vector<std::string> lines;

public:
    HostsFile();
    bool check(string);
    void add();
    std::vector<std::string> injectGenerator();
    void cancel();
    void sync();
};

#endif // HOSTSFILE_H
