#ifndef COMMAND_H
#define COMMAND_H

#include<vector>
#include "boardcomponent.h"

//компоненты пля между собой тесно связаны, а именно - компоненты ячейки поля, но все зависит
class UnitMediator : public IMediator{//взаимодействие компонентов поля(добавить юнита, удалить унита, добавить базу, удалить базу, добавить нейтральный объект)
    IUnit *sender = nullptr;
    /*Base *base_receiver = nullptr;
    IUnit *unit_receiver = nullptr;*/
    ICreature *receiver = nullptr;

public:

    /*UnitMediator(IUnit *sender, Base *base) : sender(sender), base_receiver(base) {
        sender->setMediator(this);
        base_receiver->setMediator(this);
    }
    UnitMediator(IUnit *sender, IUnit *unit) : sender(sender), unit_receiver(unit) {
        sender->setMediator(this);
        unit_receiver->setMediator(this);
    }*/

    UnitMediator(IUnit *sender, ICreature *receiver) : sender(sender), receiver(receiver){
        sender->setMediator(this);
        receiver->setMediator(this);
    }

    void notify(size_t val = 0) override {
        UnitType type = this->sender->getType();
        if(type == DEFENDER_ELF || type == DEFENDER_ELF){
            receiver->getProtectEffect();
            return;
        }
        if(type == ATTACKER_ELF || type == ATTACKER_DWARF || type == ATTACKER_CLERIC){
            receiver->getAttackEffect(val);
            return;
        }
        receiver->getHealEffect(val);
    }
    ~UnitMediator(){}

};

class ICommand
{
protected:
    GameBoard *receiver = nullptr;
    coord *from = nullptr;
    coord *to = nullptr;
    GameBoard *boardCopy = nullptr;
    IMediator *mediator = nullptr;

public:
    explicit ICommand(GameBoard *receiver, coord *from, coord *to) : receiver(receiver), from(from), to(to), boardCopy(nullptr){}
    ~ICommand() = default;
    virtual bool execute() = 0;
    void saveCopy(){
        boardCopy = new GameBoard(*receiver);
    }
    void undo(){
        receiver = boardCopy;
    }
};

class MoveCommand : public ICommand{

public:
    MoveCommand(GameBoard *receiver, coord *from, coord *to) : ICommand(receiver, from, to){}
    bool execute() override{
        //boardCopy = new GameBoard(*receiver);
        this->saveCopy();
        bool execRes = receiver->moveUnit((receiver->getField())[from->x][from->y]->getUnit(), to->x, to->y);
        return execRes;
    }
};

class InfluenceCommand : public ICommand{//attack, protect or heal
public:
    InfluenceCommand(GameBoard *receiver, coord *from, coord *to) : ICommand(receiver, from, to){}
    bool execute() override {

        //boardCopy = new GameBoard(*receiver);
        this->saveCopy();
        bool execRes = false;

        IUnit *sender = receiver->getField()[from->x][from->y]->getUnit();
        if(receiver->getField()[to->x][to->y]->getUnit())
            mediator = new UnitMediator(sender, receiver->getField()[to->x][to->y]->getUnit());
        else mediator = new UnitMediator(sender, receiver->getField()[to->x][to->y]->getBase());
        sender->influenceOnUnit();

        return execRes;
    }
};

class UndoCommand : public ICommand{
public:
    UndoCommand(GameBoard *receiver, coord *from, coord *to) : ICommand(receiver, from, to){}
    bool execute() override{
        this->undo();
        return true;
    }
};

class CommandHistory {
    std::vector<ICommand*> history;
public:
    CommandHistory(){}
    void push(ICommand *command){
        history.push_back(command);
    }
    ICommand* pop(){
        ICommand* top = history.back();
        history.pop_back();
        return top;
    }
};

#endif // COMMAND_H
