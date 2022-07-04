#ifndef __UNTAR__
#define __UNTAR__

#include <string>
#include <fstream>
using namespace std;
class Untar
{
public:
    void Save();

    Untar(const string& file);
    ~Untar() = default;
private:
    string file_ = {};
};