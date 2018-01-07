#include <QApplication>
#include "hexgame.h"

HexGame* game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    game = new HexGame();
    game->show();
    game->DisplayMenu();

    return a.exec();
}
