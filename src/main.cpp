#include <iostream>
#include "include/tar.h"
#include "include/untar.h"
#include <cstring>
using namespace std;
int main(int argc, char **argv)
{
    if (argc < 2) {
        cout << "Usage: <Target> tar or untar" << endl;
    }
    if (strcmp(argv[1], "tar") == 0) {
        tar::Tar tar("../output/123.me");
        tar.Add("../resource/76gr7e.jpg");
        tar.Add("../resource/0jpzrq.png");
        tar.Save();
    } else if (strcmp(argv[1], "untar") == 0) {
        untar::Untar untar("../output/123.me");
        untar.Save();
    }
    return 0;
}