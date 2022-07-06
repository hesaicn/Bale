#ifndef __TAR__
#define __TAR__

#include <string>
#include <vector>
#include <fstream>
#include "constants.h"

using namespace std;
class Tar
{
public:
    void Add(const string& path);
    void Save();

    Tar(const string& path);
    ~Tar() = default;
private:
    vector<string> files_ = {};
    string path_ = {};
};
#endif