#ifndef UNITINTERFACE_H
#define UNITINTERFACE_H

#include "creature.h"
#include<iostream>


class IUnit : public ICreature
{
public:

    coord unitCoord;
    size_t ID = 0;
    Attribute health;
    Attribute protection;
    Attribute power;
    Attribute magic;

    Artefact* artefact = nullptr;//поменять на щит


    virtual void setAttributes() = 0;
    virtual UnitType getType() = 0;
    virtual ~IUnit() = default;
    virtual void influenceOnUnit() = 0;

    coord getCoord() const override { return unitCoord; }
    size_t getHealthValue() const override { return health.getValue(); }
    size_t getProtectionValue() const { return protection.getValue(); }
    size_t getPowerValue() const { return power.getValue(); }
    size_t getMagicValue() const { return magic.getValue(); }
    bool isDestroyed() const override { return health.isReset(); }

    void getAttackEffect(size_t val) override;
    void getProtectEffect() override;
    void getHealEffect(size_t val) override;

    bool changeCoord(size_t newX, size_t newY) override;
    void setArtefact(size_t val) { this->artefact = new Artefact(val); }





};

#endif // UNITINTERFACE_H
