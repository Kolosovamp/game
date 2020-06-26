#include "unitfactory.h"

ICleric* DefenderFactory::createCleric(size_t x, size_t y) const{
    return new ClericHealer(x, y);
}

IDwarf* DefenderFactory::createDwarf(size_t x, size_t y) const{
    return new DwarfGunsmith(x, y);
}

IElf* DefenderFactory::createElf(size_t x, size_t y) const{
    return new ElfWizard(x, y);
}

ICleric* AttackerFactory::createCleric(size_t x, size_t y) const{
    return new ClericNecromancer(x, y);
}

IDwarf* AttackerFactory::createDwarf(size_t x, size_t y) const{
    return new DwarfGuardian(x, y);
}

IElf* AttackerFactory::createElf(size_t x, size_t y) const{
    return new ElfWarrior(x, y);
}
