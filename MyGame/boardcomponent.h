#ifndef BOARDCOMPONENT_H
#define BOARDCOMPONENT_H

#include <iostream>
#include "base.h"
#include "landscapes.h"
#include "neutralobjectinterface.h"
#include "strategy.h"

class Base;
class UnitManager;
class IStrategy;
class IUnit;

class BoardComponent
{

    UnitManager* unitManager;

    IUnit* unit;
    Base* base;

    ILandscape* proxyLandscape;//заместитель ландшафта

    INeutralObject* neutralObject;    
    IStrategy* strategy;

    bool isEmpty = true;


public:    
    BoardComponent() : unitManager(nullptr), unit(nullptr), base(nullptr),
        proxyLandscape(nullptr), neutralObject(nullptr), strategy(nullptr),isEmpty(true){}


    BoardComponent(const BoardComponent &component) : unitManager(component.unitManager),
        unit(component.unit), base(component.base), proxyLandscape(component.proxyLandscape),
        neutralObject(component.neutralObject), strategy(component.strategy),
        isEmpty(component.isEmpty){}

    ~BoardComponent(){
        unitManager = nullptr;
        base = nullptr;
        unit = nullptr;
        proxyLandscape = nullptr;
        neutralObject = nullptr;
        strategy = nullptr;
        isEmpty = true;
    }
    bool empty() const { return  this->isEmpty; }

    bool setUnit(IUnit *newUnit);
    bool deleteUnit();
    IUnit* getUnit() const { return this->unit; }

    bool setBase(Base *base);
    bool deleteBase();
    Base* getBase() const { return this->base; }

    void setStrategy(IStrategy* strategy){ this->strategy = strategy; }
    bool chooseStrategy();

    void setNeutralObject(INeutralObject* neutralObject);
    void setLandscape(ILandscape* landscape) {
        //std ::cout << landscape->getType() << std::endl;
        this->proxyLandscape = new ProxyLandscape(landscape->getType());
    }
    void setManager(UnitManager *unitManager) { this->unitManager = unitManager; }

    /*void getDamage(size_t damage){
        if(this->unit == nullptr)
            return;
        (this->unit->health).getDamage(damage);
        if(this->unit->isDestroyed())
            this->deleteUnit();
    }*/



};

#endif // BOARDCOMPONENT_H
