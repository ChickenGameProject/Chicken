#include <QApplication>
#include "game.h"
#include "player.h"
#include "ship_level_1.h"

Game * game;
Player * ship1;
int Fire;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    game = new Game();
    game->show();
    game->displayMenu();
    return a.exec();
}
