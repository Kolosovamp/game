#ifndef UNITATTRIBUTES_H
#define UNITATTRIBUTES_H

#include<iostream>

struct coord{
    size_t x;
    size_t y;
    /*coord(size_t x, size_t y){
        this->x = x;
        this->y = y;
    }*/
};

class Attribute{

    size_t value;
public:
    size_t getValue() const { return this->value; }
    void setValue(size_t value) { this->value = value; }
    void getDamage(size_t value) { this->value -= value; }
    bool isReset() const { return this->value <= 0; }
    void upgradeAttribute(size_t val) { this->value += val; }
};

class Artefact{
    size_t bonus;
public:
    Artefact(size_t val) : bonus(val) {}
    size_t getBonus() const { return this->bonus; }
    void setBonus(size_t val) { this->bonus = val; }
};

class Shield{

public:
    Shield(){}
    ~Shield() = default;
};


#endif // UNITATTRIBUTES_H
