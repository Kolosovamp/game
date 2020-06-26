#ifndef GAMEFACADE_H
#define GAMEFACADE_H

#include <iostream>
#include "gameboard.h"
#include "mainwindow.h"
#include "command.h"


class GameFacade{

    bool isStarted;
    GameBoard* board;
    MainWindow* window;//gui
    bool specialSettings;
    CommandHistory *history;

public:
    GameFacade() : isStarted(false), board(nullptr), window(nullptr), specialSettings(false), history(nullptr){}

    void startGame(){

        isStarted = true;
        if(specialSettings){
            makeBoard(5, 5);
        }
        else{
            makeStandartBoard();
        }

        window = new MainWindow;
        window->setLandscapeMap(board->getLandscapeMap());
        window->show();

        DefenderFactory defenderFactory;
        AttackerFactory attackerFactory;

        IUnit *unit1 = defenderFactory.createCleric(2,3);
        IUnit *unit3 = attackerFactory.createDwarf(4, 4);

        board->printField();
        std::cout<<std::endl;

        board->setUnit(unit1);
        board->setUnit(attackerFactory.createElf(1,4));
        board->setUnit(unit3);
        std::cout<<"1: "<<unit1->ID<<std::endl;
        std::cout<<"3: "<<unit3->ID<<std::endl;

        board->printField();
        std::cout<<std::endl;

        std::cout<<"START"<<std::endl;
        std::cout<<unit1->ID<<std::endl;
        board->moveUnit(unit1, 0, 0);
        board->printField();
        std::cout<<std::endl;

        board->deleteUnit(unit3);
        board->printField();
    }
    void makeStandartBoard(){
        board = new GameBoard(5, 5);//standart size
    }
    void makeBoard(size_t w, size_t h){
        board = new GameBoard(w, h);
    }
    void finishGame(){
        isStarted = false;
        delete board;
    }
    void changeSettings(){
        specialSettings = true;
        //получить из гуи специальные настройки
    }

    std::pair<coord*, coord*> selectUnit(){
        //получитьь укзатель на отправитель команды
        coord *from = new coord;
        coord *to = new coord;
        from->x = 0;
        from->y = 0;
        to->x = 3;
        to->y = 3;
        return std::pair<coord*, coord*>(from, to);
    }
    void selectCommand(){//здесь создаются объекты команд//create UI?
        size_t x = 0;//номер команды
        ICommand *command = nullptr;
        switch (x) {
            case 0:
                command = new InfluenceCommand(this->board, selectUnit().first, selectUnit().second);
            //execCommand(command);
            break;
            case 1:
                command = new MoveCommand(this->board,selectUnit().first, selectUnit().second );
                break;
            default:
                break;
        }
        if(!command)
            execCommand(command);
    }
    bool execCommand(ICommand *command){
        return  command->execute();
    }
    void undo(){
        ICommand *command = history->pop();
        if(!command)
            command->undo();
    }
    ~GameFacade(){
        delete board;
    }
};



#endif // GAMEFACADE_H
