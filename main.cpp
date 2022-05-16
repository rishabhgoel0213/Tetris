#include <QApplication>
#include <QPushButton>
#include "Game.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Game g;
    g.show();
    g.begin();
    return QApplication::exec();
}
