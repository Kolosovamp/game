#include "boardcomponent.h"

bool BoardComponent::setUnit(IUnit *newUnit){

    if(this->isEmpty){
        this->unit = newUnit;
        //std::cout << unit->ID<<std::endl;
        //std::cout << newUnit->ID<<std::endl;
        this->isEmpty = false;
    }
    else return false;
    std::cout<<newUnit->ID<<std::endl;
    if(newUnit->ID == 0){
        std::cout<<"CREATE"<<std::endl;
        this->unitManager->notifyObservers(CREATE);
    }
    proxyLandscape->influenceOnUnit();
    if(chooseStrategy())
        this->strategy->execute(this);
    return true;    
}

bool BoardComponent::chooseStrategy(){

    if(!this->unit || !this->neutralObject)
        return false;
    UnitType unitType = this->unit->getType();

    switch (neutralObject->getType()) {

       case DUNGEON:
        if(unitType == DEFENDER_ELF || unitType == ATTACKER_ELF)
            this->setStrategy(new DungeonElfStrategy);
        if(unitType == DEFENDER_DWARF || unitType == ATTACKER_DWARF)
            this->setStrategy(new DungeonDwarfStrategy);
        if(unitType == DEFENDER_CLERIC || unitType == ATTACKER_CLERIC)
            this->setStrategy(new DungeonClericStrategy);
        break;
       case WATERFALL:
        if(unitType == DEFENDER_ELF || unitType == ATTACKER_ELF)
            this->setStrategy(new WaterfallElfStrategy);
        if(unitType == DEFENDER_DWARF || unitType == ATTACKER_DWARF)
            this->setStrategy(new WaterfallDwarfStrategy);
        if(unitType == DEFENDER_CLERIC || unitType == ATTACKER_CLERIC)
            this->setStrategy(new WaterfallClericStrategy);
        break;
       case CASTLE:
        if(unitType == DEFENDER_ELF || unitType == ATTACKER_ELF)
            this->setStrategy(new CastleElfStrategy);
        if(unitType == DEFENDER_DWARF || unitType == ATTACKER_DWARF)
            this->setStrategy(new CastleDwarfStrategy);
        if(unitType == DEFENDER_CLERIC || unitType == ATTACKER_CLERIC)
            this->setStrategy(new CastleClericStrategy);
        break;
       case LABYRINTH:
            this->setStrategy(new LabyrinthStrategy);
        break;
       default:
        break;
    }
    return true;
}

void BoardComponent::setNeutralObject(INeutralObject *neutralObject){

    if(this->neutralObject) return;
    this->neutralObject = neutralObject;

    if(chooseStrategy())
        this->strategy->execute(this);

}

bool BoardComponent::deleteUnit(){

    if(this->unit != nullptr){
        //std::cout << unit->ID<<std::endl;
        if(this->unit->ID == 0){//показатель удаления,  а не перемещения
            this->unitManager->notifyObservers(DESTROY);
            std::cout<<"DESTROY"<<std::endl;
        }
        this->unit = nullptr;
        this->isEmpty = true;
        this->strategy = nullptr;

        return true;
    }
    return false;
}

bool BoardComponent::setBase(Base *base){

    if(this->isEmpty){
        this->base = base;
        this->isEmpty = false;
        return true;
    }
    return false;
}

bool BoardComponent::deleteBase(){

    if(this->isEmpty == false){
        this->base = nullptr;
        this->isEmpty = true;
        return true;
    }
    return false;
}


