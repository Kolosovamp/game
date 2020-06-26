#ifndef MEDIATOR_H
#define MEDIATOR_H

#include <iostream>

class IMediator
{
public:
    virtual ~IMediator() = default;
    virtual void notify(size_t val = 0) = 0;
};


#endif // MEDIATOR_H
