#ifndef UNITFACTORY_H
#define UNITFACTORY_H

#include "abstractunites.h"
#include "specificunites.h"

class IElf;
class IDwarf;
class ICleric;

//абстрактная фабрика
class UnitFactory
{
public:
    virtual ~UnitFactory() = default;
    virtual ICleric* createCleric(size_t x, size_t y) const = 0;
    virtual IDwarf* createDwarf(size_t x, size_t y) const = 0;
    virtual IElf* createElf(size_t x, size_t y) const = 0;
};

//конкретная фабрика
class DefenderFactory : public UnitFactory {
public:
    ICleric* createCleric(size_t x, size_t y) const override;
    IDwarf* createDwarf(size_t x, size_t y) const override;
    IElf* createElf(size_t x, size_t y) const override;
};

//конкретная фабрика
class AttackerFactory : public UnitFactory {
public:
    ICleric* createCleric(size_t x, size_t y) const override;
    IDwarf* createDwarf(size_t x, size_t y) const override;
    IElf* createElf(size_t x, size_t y) const override;
};

#endif // UNITFACTORY_H
