#include "strategy.h"


void DungeonElfStrategy::execute(BoardComponent* component){
    size_t curMagic = component->getUnit()->getMagicValue();
    curMagic /= 2;
    curMagic *= -1;
    component->getUnit()->magic.upgradeAttribute(curMagic);
}

void DungeonDwarfStrategy::execute(BoardComponent* component){
    component->getUnit()->health.upgradeAttribute(50);
}

void DungeonClericStrategy::execute(BoardComponent* component){
    size_t curMagic = component->getUnit()->getMagicValue();
    curMagic /= 2;
    curMagic *= -1;
    component->getUnit()->magic.upgradeAttribute(curMagic);
}

void WaterfallElfStrategy::execute(BoardComponent* component){
    component->getUnit()->health.upgradeAttribute(50);
}

void WaterfallDwarfStrategy::execute(BoardComponent* component){
    size_t curProtection = component->getUnit()->getProtectionValue();
    curProtection /= 2;
    curProtection *= -1;
    component->getUnit()->protection.upgradeAttribute(curProtection);
}

void WaterfallClericStrategy::execute(BoardComponent* component){
    size_t curProtection = component->getUnit()->getProtectionValue();
    curProtection /= 2;
    curProtection *= -1;
    component->getUnit()->protection.upgradeAttribute(curProtection);
}

void CastleElfStrategy::execute(BoardComponent* component){
    size_t curPower = component->getUnit()->getPowerValue();
    curPower /= 2;
    curPower *= -1;
    component->getUnit()->power.upgradeAttribute(curPower);
}

void CastleDwarfStrategy::execute(BoardComponent* component) {
    size_t curPower = component->getUnit()->getPowerValue();
    curPower /= 2;
    curPower *= -1;
    component->getUnit()->power.upgradeAttribute(curPower);
}

void CastleClericStrategy::execute(BoardComponent* component){
    component->getUnit()->health.upgradeAttribute(50);
}

void LabyrinthStrategy::execute(BoardComponent* component) {
    size_t number = rand() % 3 + 1;
    switch (number) {
     case 1:
        component->getUnit()->setArtefact(rand() % 20 + 5);
        break;
     case 2:
        component->deleteUnit();
        break;
     case 3:
        component->getUnit()->protection.upgradeAttribute(15);
        break;
    default:
        break;
    }
}




