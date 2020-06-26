#ifndef SPECIFICUNITES_H
#define SPECIFICUNITES_H

#include "abstractunites.h"

#define MAXVALUE 100

class ClericHealer: public virtual ICleric {
public:
    void setAttributes() override;
    ~ClericHealer() override{}
    UnitType getType() override { return DEFENDER_CLERIC; }
    ClericHealer(size_t x, size_t y);
    void influenceOnUnit() override;
};

class ClericNecromancer: public virtual ICleric {
public:
    void setAttributes() override;
    ~ClericNecromancer() override{}
    UnitType getType() override { return ATTACKER_CLERIC; }
    ClericNecromancer(size_t x, size_t y);
    void influenceOnUnit() override;
};

class DwarfGuardian: public virtual IDwarf {
public:
    void setAttributes() override;
    ~DwarfGuardian() override{}
    UnitType getType() override { return ATTACKER_DWARF; }
    DwarfGuardian(size_t x, size_t y);
    void influenceOnUnit() override;
};

class DwarfGunsmith : public virtual IDwarf {
public:
    void setAttributes() override;
    ~DwarfGunsmith() override{}
    UnitType getType() override { return DEFENDER_DWARF; }
    DwarfGunsmith(size_t x, size_t y);
    void influenceOnUnit() override;
};


class ElfWizard: public virtual IElf {
public:
    void setAttributes() override;
    ~ElfWizard() override{}
    UnitType getType() override { return DEFENDER_ELF; }
    ElfWizard(size_t x, size_t y);
    void influenceOnUnit() override;
};

class ElfWarrior : public virtual IElf {
public:
    void setAttributes() override;
    ~ElfWarrior() override{}
    UnitType getType() override { return ATTACKER_ELF; }
    ElfWarrior(size_t x, size_t y);
    void influenceOnUnit() override;
};

#endif // SPECIFICUNITES_H
