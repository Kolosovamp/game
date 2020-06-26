#ifndef ABSTRACTUNITES_H
#define ABSTRACTUNITES_H

#include "unitinterface.h"
//#include "mediator.h"

class ICleric : public virtual IUnit {
public:
    virtual void setAttributes() = 0;
    virtual void influenceOnUnit() = 0;
    virtual ~ICleric() = 0;
};

class IDwarf : public virtual IUnit {
public:
    virtual void setAttributes() = 0;
    virtual void influenceOnUnit() = 0;
    virtual ~IDwarf() = 0;
};

class IElf : public virtual IUnit {
public:
    virtual void setAttributes() = 0;
    virtual void influenceOnUnit() = 0;
    virtual ~IElf() = 0;
};


#endif // ABSTRACTUNITES_H
