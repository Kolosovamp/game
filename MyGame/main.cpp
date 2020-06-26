//#include "mainwindow.h"
#include "gamefacade.h"
#include <QApplication>

using namespace std;

int main(int argc, char *argv[])
{
    srand(time(NULL));
    QApplication a(argc, argv);
    srand(time(NULL));
    //MainWindow w;
    //w.show();
    GameFacade game;
    game.startGame();


    return a.exec();
}
