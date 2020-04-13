#include "chessgame.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ChessGame w;
    w.show();
    return a.exec();
}

