#ifndef __TAR__
#define __TAR__

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

namespace tar {
using namespace std;
class Tar
{
public:
    void Add(const string& path) {
        files_.push_back(path);
    }
    void Save() {
        ofstream ofs(path_, ios::binary);
        ifstream ifs;
        if (files_.size() == 0) {
            return;
        }
        for (const string& file : files_) {
            ifs.open(file);
            ifs.seekg(0, ios::end);
            unsigned long long len = ifs.tellg();
            ifs.seekg(0, ios::beg);
            string filename;
            filename = file.rfind("/") != string::npos ? file.substr(file.rfind("/") + 1) : file;
            int dirlen = filename.size() + 1;
            ofs.write((char *)&dirlen, sizeof(int));
            ofs.write(filename.c_str(), filename.size() + 1);
            ofs.write((char *)&len, sizeof(unsigned long long));
            if (ifs) {
                static char buffer[1024 * 1024] = {0};
                while (len / (1024 * 1024) > 0) {
                    ifs.read(buffer, 1024 * 1024);
                    ofs.write(buffer, 1024 * 1024);
                    len -= 1024 * 1024;
                }
                if (len > 0) {
                    ifs.read(buffer,len);
                    ofs.write(buffer, len);
                }
            }
            ifs.close();
        }
        ofs.clear();
    }

    Tar(const string& path) {
        path_ = path;
    }

    ~Tar() = default;
private:
    vector<string> files_ = {};
    string path_ = {};
};
} // namespace tar
#endif