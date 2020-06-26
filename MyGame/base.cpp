#include "base.h"

Base::Base(GameBoard* board, size_t x, size_t y)
{    
    this->board = board;
    this->baseCoord.x = x;
    this->baseCoord.y = y;
    baseHealth.setValue(100);
    board->setBase(this);
    this->ID = board->getBaseCount();
    this->maxNumOfCreation = (board->getMaxUnitCount() - board->getUnitCount())/board->getMaxBaseCount();
    this->board->unitManager->subscribeObserverForUpdates(CREATE, this);
    this->board->unitManager->subscribeObserverForUpdates(DESTROY, this);
}

void Base::update(){
    this->maxNumOfCreation = (this->board->getMaxUnitCount() - this->board->getUnitCount())/this->board->getMaxBaseCount();
    this->curUnitCount = this->board->getUnitCount();
}

bool Base::changeCoord(size_t newX, size_t newY){
    if(newX < board->getMaxWidth() && newY < board->getMaxHeight()){
        (this->baseCoord).x = newX;
        (this->baseCoord).y = newY;
        return true;
    }
    return false;
}

void Base::createUnit(UnitType unitType, size_t x, size_t y) {
    IUnit* unit;
    switch (unitType) {
        case DEFENDER_ELF:
            unit = defenderFactory->createElf(x, y);
            break;
        case DEFENDER_CLERIC:
            unit = defenderFactory->createCleric(x, y);
            break;
        case DEFENDER_DWARF:
            unit = defenderFactory->createDwarf(x, y);
            break;
        case ATTACKER_ELF:
            unit = attackerFactory->createElf(x, y);
            break;
        case ATTACKER_CLERIC:
            unit = attackerFactory->createCleric(x, y);
            break;
        case ATTACKER_DWARF:
            unit = attackerFactory->createDwarf(x, y);
            break;
    }
    board->setUnit(unit);
}

void Base::getAttackEffect(size_t val) {
    if(!this->shield)//отсутствие щита
        this->baseHealth.getDamage(val);
    //проверка на уничтожение?
}

void Base::getProtectEffect() {
    this->setShield(new Shield());
}

void Base::getHealEffect(size_t val) {
    this->baseHealth.upgradeAttribute(val);
}




