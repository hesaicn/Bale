#ifndef __UNTAR__
#define __UNTAR__

#include <string>
#include <fstream>
namespace untar {
using namespace std;
class Untar
{
public:
    void Save() {
        ifstream ifs(file_, ios::binary);
        if (!ifs.is_open()) {
            return;
        }
        while (!ifs.eof()) {
            char fileName[256] = { 0 };
            int fileNameLen = 0;
            ifs.read((char *)&fileNameLen, sizeof(int));
            ifs.read(fileName, fileNameLen);
            unsigned long long fileSize = 0;
            ifs.read((char *)&fileSize, sizeof(unsigned long long));
            ofstream ofs(fileName, ios::binary);
            static char buffer[1024 * 1024] = {0};
            while (fileSize / (1024 * 1024) > 0) {
                ifs.read(buffer, 1024 * 1024);
                ofs.write(buffer, 1024 * 1024);
                fileSize -= 1024 * 1024;
            }
            if (fileSize > 0) {
                ifs.read(buffer, fileSize);
                ofs.write(buffer, fileSize);
            }
        }
        ifs.close();
    }

    Untar(const string& file) {
        file_ = file;
    }

    ~Untar() = default;
private:
    string file_ = {};
};
} // namespace untar
#endif