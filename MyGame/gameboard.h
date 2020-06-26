#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include"boardcomponent.h"
#include "unitobserverinterface.h"
#include <map>
#include <vector>
#include <algorithm>

class BoardComponent;
class Base;
class IUnit;

class UnitManager{
    std::map <UnitEventType, std::vector<IUnitObserver*>> unitObservers;
public:
    UnitManager(){}
    ~UnitManager(){
        for(auto event : unitObservers){
            event.second.clear();
        }
    }

    void subscribeObserverForUpdates(UnitEventType eventType, IUnitObserver* observer){ unitObservers[eventType].push_back(observer); }
    void unsubscribeObserverFromUpdates(UnitEventType eventType, IUnitObserver* observer) {
        std::vector<IUnitObserver*> v;
        v = unitObservers[eventType];
        v.erase(remove(v.begin(), v.end(), observer), v.end() );
    }
    void notifyObservers(UnitEventType eventType) {
        for(auto subscribe : unitObservers[eventType]){
            subscribe->update();
        }
    }
};


class GameBoard
{
    //инвариант класса
    const size_t maxWidth;
    const size_t maxHeight;
    size_t currentUnitCount;
    size_t currentBaseCount;
    const size_t maxBaseCount;
    const size_t maxUnitCount;

    BoardComponent ***field;
    std::map<LandscapeType, std::vector<std::pair<size_t, size_t>>> landscapeMap;

public:
    UnitManager* unitManager;
    friend class BoardIterator;

    GameBoard(const size_t maxWidth, const size_t maxHeight);
    GameBoard(const GameBoard &board);
    GameBoard(GameBoard &&board);
    ~GameBoard();

    void printField() const;
    size_t getMaxWidth() const;
    size_t getMaxHeight() const;
    size_t getMaxUnitCount() const { return maxUnitCount; }
    size_t getUnitCount() const { return currentUnitCount; }
    size_t getMaxBaseCount() const { return maxBaseCount; }
    size_t getBaseCount() const { return currentBaseCount; }
    std::map<LandscapeType, std::vector<std::pair<size_t, size_t>>> getLandscapeMap() const { return landscapeMap; }
    BoardComponent*** getField() const;    

    bool setUnit(IUnit *newIUnit);
    bool deleteUnit(IUnit* IUnit);
    bool moveUnit(IUnit *unit, size_t newX, size_t newY);

    bool setBase(Base *newBase);
    bool deleteBase(Base* base);


};


class BoardIterator{
    GameBoard* board;

    size_t currentWidth;
    size_t currentHeight;
    size_t maxWidth;
    size_t maxHeight;

public:
    BoardIterator(GameBoard* fieldAttachedTo);
    void reset();
    bool hasNext();
    BoardComponent* getNext();
};
#endif // GAMEBOARD_H
