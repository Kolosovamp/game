#ifndef BASE_H
#define BASE_H

#include <iostream>
#include "unitfactory.h"
#include "gameboard.h"
#include "unitobserverinterface.h"
#include <vector>
#include "creature.h"
#include "UnitAttributes.h"

class GameBoard;
//class IMediator;

class Base : public IUnitObserver, public ICreature {
    coord baseCoord;
    Attribute baseHealth;
    size_t curUnitCount;
    size_t maxNumOfCreation;
    size_t ID = 0;

    GameBoard *board;
    std::vector<IUnit*> units;
    UnitFactory* defenderFactory = new DefenderFactory();
    UnitFactory* attackerFactory = new AttackerFactory();

public:
    Base(GameBoard *board, size_t x, size_t y);
    coord getCoord() const override { return baseCoord; }
    void getAttackEffect(size_t val) override;
    void getProtectEffect() override;
    void getHealEffect(size_t val) override;
    bool changeCoord(size_t newX, size_t newY) override;
    void update() override;

    ~Base(){
        delete this->defenderFactory;
        delete this->attackerFactory;
        //boardMediator = nullptr;
        board = nullptr;
    }
    bool isDestroyed() const override { return baseHealth.isReset(); }
    size_t getHealthValue() const override{ return baseHealth.getValue(); }
    void setHealth(size_t newVal) { baseHealth.setValue(newVal); }    
    void checkBaseStatus() const {

        //curUnitCount, maxNumOfCreation, baseHealth
    }

    void createUnit(UnitType unitType, size_t x, size_t y);



};

#endif // BASE_H
