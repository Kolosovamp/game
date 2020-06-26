#ifndef CREATURE_H
#define CREATURE_H

#include "UnitAttributes.h"
#include "enum.h"
#include "mediator.h"




class ICreature
{

public:
    virtual ~ICreature() = default;
    IMediator* mediator = nullptr;
    Shield* shield = nullptr;


    void setMediator(IMediator* mediator){
        this->mediator = mediator;
    }
    void setShield(Shield *shield) { this->shield = shield; }

    virtual coord getCoord() const = 0;
    virtual bool isDestroyed() const = 0;
    virtual size_t getHealthValue() const = 0;
    virtual bool changeCoord(size_t newX, size_t newY) = 0;    

    virtual void getAttackEffect(size_t val) = 0;
    virtual void getProtectEffect() = 0;
    virtual void getHealEffect(size_t val) = 0;

};



#endif // CREATURE_H
