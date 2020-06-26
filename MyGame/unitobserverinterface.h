#ifndef UNITOBSERVERINTERFACE_H
#define UNITOBSERVERINTERFACE_H



class IUnitObserver {

public:
    virtual void update() = 0;
    virtual ~IUnitObserver() = default;
};


#endif // UNITOBSERVERINTERFACE_H
