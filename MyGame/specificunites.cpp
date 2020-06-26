#include "specificunites.h"



DwarfGuardian::DwarfGuardian(size_t x, size_t y){
    changeCoord(x,y);
    setAttributes();

}

void DwarfGuardian::influenceOnUnit(){
    //command = ATTACK;
    if(this->mediator)
        this->mediator->notify();
}

DwarfGunsmith::DwarfGunsmith(size_t x, size_t y){
    changeCoord(x,y);
    setAttributes();

}

void DwarfGunsmith::influenceOnUnit(){
    //command = PROTECT;
    if(this->mediator)
        this->mediator->notify();
}

ClericHealer::ClericHealer(size_t x, size_t y){
    setAttributes();
    changeCoord(x,y);

}

void ClericHealer::influenceOnUnit(){
    //command = HEAL;
    if(this->mediator){
        this->mediator->notify();
    }
}

ClericNecromancer::ClericNecromancer(size_t x, size_t y){
    setAttributes();
    changeCoord(x,y);

}

void ClericNecromancer::influenceOnUnit(){
    //command = ATTACK;
    size_t val = this->magic.getValue()+this->power.getValue();
    if(this->mediator)
        this->mediator->notify();
}

ElfWizard::ElfWizard(size_t x, size_t y){
    setAttributes();
    changeCoord(x, y);

}

void ElfWizard::influenceOnUnit(){
    //command = PROTECT;
    if(this->mediator)
        this->mediator->notify();
}

ElfWarrior::ElfWarrior(size_t x, size_t y){
    setAttributes();
    changeCoord(x, y);

}

void ElfWarrior::influenceOnUnit(){
    //command = ATTACK;
    if(this->mediator)
        this->mediator->notify();
}

void DwarfGuardian::setAttributes(){

    this->magic.setValue(MAXVALUE);
    this->power.setValue(MAXVALUE - 30);
    this->health.setValue(MAXVALUE);
    this->protection.setValue(MAXVALUE - 10);

}

void DwarfGunsmith::setAttributes(){

    this->magic.setValue(MAXVALUE);
    this->power.setValue(MAXVALUE - 25);
    this->health.setValue(MAXVALUE);
    this->protection.setValue(MAXVALUE - 20);

}

void ClericHealer::setAttributes() {

    this->magic.setValue(MAXVALUE - 25);
    this->power.setValue(MAXVALUE);
    this->health.setValue(MAXVALUE - 40);
    this->protection.setValue(MAXVALUE);

}

void ClericNecromancer::setAttributes() {

    this->magic.setValue(MAXVALUE - 10);
    this->power.setValue(MAXVALUE);
    this->health.setValue(MAXVALUE - 30);
    this->protection.setValue(MAXVALUE);

}

void ElfWizard::setAttributes() {

    magic.setValue(MAXVALUE - 15);
    power.setValue(MAXVALUE - 25);
    health.setValue(MAXVALUE);
    protection.setValue(MAXVALUE);

}

void ElfWarrior::setAttributes() {

    magic.setValue(MAXVALUE - 50);
    power.setValue(MAXVALUE - 20);
    health.setValue(MAXVALUE);
    protection.setValue(MAXVALUE);

}

