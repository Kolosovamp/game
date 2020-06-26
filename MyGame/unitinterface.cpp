#include "unitinterface.h"

bool IUnit::changeCoord(size_t newX, size_t newY){
    //check coord
    (this->unitCoord).x = newX;
    (this->unitCoord).y = newY;

    return true;
}


void IUnit::getAttackEffect(size_t val){
    if(!this->shield)//отсутствие щита
        this->health.getDamage(val);
    //проверка на уничтожение?
}

void IUnit::getProtectEffect(){
    this->setShield(new Shield());
}

void IUnit::getHealEffect(size_t val){
    this->health.upgradeAttribute(val);
}
