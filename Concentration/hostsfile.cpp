#include "hostsfile.h"
#include <QCoreApplication>
#include <QtCore>
#include <QSettings>
#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>

QSettings sett;

HostsFile::HostsFile()
{
    string line;
    ifstream file(path.c_str());
    while (getline(file, line)){
        lines.push_back(line);
    }

}

vector<string> HostsFile::injectGenerator(){
    vector<string> injectlist;
    QStringList rnoutput;
    rnoutput = sett.value("Sites").value<QString>().split(",");
    for(int i = 0; i < rnoutput.size(); ++i){
        if(rnoutput[i] != ""){
            injectlist.push_back("127.0.0.1	" + rnoutput[i].toStdString());
        }
    }
    return injectlist;
}

void HostsFile::add()
{
    lines = injectGenerator();
}

void HostsFile::cancel()
{
    lines.clear();
}

bool HostsFile::check(string host)
{
    return true;
}

void HostsFile::sync(){
    string hoststr;
    ofstream file(path.c_str());
    for (int i; i < lines.size(); ++i)
    {
        hoststr += (lines[i] + "\n");
    }
    file << hoststr;
}
