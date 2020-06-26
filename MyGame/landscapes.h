#ifndef LANDSCAPES_H
#define LANDSCAPES_H

#include "enum.h"
#include <iostream>

class ILandscape
{
public:
    virtual ~ILandscape() = default;
    virtual LandscapeType getType() = 0;
    virtual void influenceOnUnit() = 0;
};

class MyLandscape : public ILandscape{
public:
    virtual LandscapeType getType() = 0;
    virtual void influenceOnUnit() = 0;
};

class Forest : public MyLandscape {
public:
    Forest(){}
    LandscapeType getType() override { return FOREST; }
    ~Forest(){}
    void influenceOnUnit() override {
        //std::cout << "/1" << std::endl;
    }
};

class Mountain : public MyLandscape {
public:
    Mountain(){}
    LandscapeType getType() override { return MOUNTAIN; }
    ~Mountain(){}
    void influenceOnUnit() override {
        //std::cout << "/2" << std::endl;
    }
};

class Plain : public MyLandscape {
public:
    Plain(){}
    LandscapeType getType() override { return PLAIN; }
    ~Plain(){}
    void influenceOnUnit() override {
        //std::cout << "/3" << std::endl;
    }
};


class ProxyLandscape: public ILandscape {
public:
    MyLandscape *realLandscape;
    LandscapeType type;
    LandscapeType getType() override { return type; }
    ProxyLandscape(LandscapeType type) : realLandscape(nullptr){
        this->type = type;
    }
    ~ProxyLandscape(){
        realLandscape = nullptr;
    }
    void influenceOnUnit() override;
    void setLandscapeType(LandscapeType type) { this->type = type; }


};


#endif // LANDSCAPES_H
