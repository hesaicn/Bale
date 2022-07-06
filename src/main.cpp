#include <iostream>
#include "../include/tar.h"
#include "../include/untar.h"
#include "../include/constants.h"
#include <cstring>
using namespace std;
int main(int argc, char **argv)
{
    if (argc < 2) {
        cout << "Usage: <Target> tar or untar" << endl;
        return -1;
    }
    if (strcmp(argv[1], "tar") == 0) {
        Tar tar(ROOT_PATH + string("output/123.me"));
        tar.Add(ROOT_PATH + string("resource/76gr7e.jpg"));
        tar.Add(ROOT_PATH + string("resource/0jpzrq.png"));
        tar.Save();
    } else if (strcmp(argv[1], "untar") == 0) {
        Untar untar(ROOT_PATH + string("output/123.me"));
        untar.Save();
    }
    return 0;
}