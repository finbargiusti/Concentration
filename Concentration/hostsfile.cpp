#include "hostsfile.h"
#include <QCoreApplication>
#include <QtCore>
#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>

HostsFile::HostsFile()
{
    string line;
    ifstream file("/etc/hosts");
    while (getline(file, line)){
        lines.insert(line);
    }

}

void HostsFile::add(string host)
{
    lines.insert(host);
}

void HostsFile::cancel(string host)
{
    cout << host;
    lines.erase(host);
}

bool HostsFile::check(string host)
{
    if (lines.count("127.0.0.1	" + host) == 1) {
        return false;
    } else {
        return true;
    }
}

void HostsFile::sync(){
    string hoststr;
    ofstream file;
    file.open("/etc/hosts");
    for (string line : lines) {
        hoststr += (line + "\n");
    }
    file << hoststr;
}