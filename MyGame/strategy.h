#ifndef STRATEGY_H
#define STRATEGY_H

#include "enum.h"
#include "boardcomponent.h"
#include <iostream>

class BoardComponent;

//интерфейс стратегии
class IStrategy
{
public:
    virtual void execute(BoardComponent* cage) = 0;
    virtual ~IStrategy() = default;
};



//конкретные стратегии
class DungeonElfStrategy : public IStrategy{
public:
    DungeonElfStrategy(){}
    void execute(BoardComponent* cage) override;
};
class DungeonDwarfStrategy : public IStrategy{
public:
    DungeonDwarfStrategy(){}
    void execute(BoardComponent* cage) override;
};
class DungeonClericStrategy : public IStrategy{
public:
    DungeonClericStrategy(){}
    void execute(BoardComponent* cage) override;
};

class WaterfallElfStrategy : public IStrategy{
public:
    WaterfallElfStrategy(){}
    void execute(BoardComponent* cage) override;
};
class WaterfallDwarfStrategy : public IStrategy{
public:
    WaterfallDwarfStrategy(){}
    void execute(BoardComponent* cage) override;
};
class WaterfallClericStrategy : public IStrategy{
public:
    WaterfallClericStrategy(){}
    void execute(BoardComponent* cage) override;
};

class CastleElfStrategy : public IStrategy{
public:
    CastleElfStrategy(){}
    void execute(BoardComponent* cage) override;
};
class CastleDwarfStrategy : public IStrategy{
public:
    CastleDwarfStrategy(){}
    void execute(BoardComponent* cage) override;
};
class CastleClericStrategy : public IStrategy{
public:
    CastleClericStrategy(){}
    void execute(BoardComponent* cage) override;
};

class LabyrinthStrategy : public IStrategy{
public:
    LabyrinthStrategy(){}
    void execute(BoardComponent* component) override;
};







//конкретные стратегии
/*class ElfStrategy : public IStrategy{
public:
    ElfStrategy(){}
    void execute(NeutralObjectType type) override;
};

class DwarfStrategy : public IStrategy{
public:
    DwarfStrategy(){}
    void execute(NeutralObjectType type) override;
};

class ClericStrategy : public IStrategy{
public:
    ClericStrategy(){}
    void execute(NeutralObjectType type) override;
};*/

#endif // STRATEGY_H
