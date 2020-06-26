#ifndef NEUTRALOBJECTINTERFACE_H
#define NEUTRALOBJECTINTERFACE_H

#include "enum.h"

class INeutralObject
{
public:
    virtual ~INeutralObject() = default;
    virtual NeutralObjectType getType() = 0;
};

class Castle : public INeutralObject {
    NeutralObjectType getType() override { return CASTLE; }
};

class Dungeon : public INeutralObject {
    NeutralObjectType getType() override { return DUNGEON; }
};

class Waterfall : public INeutralObject {
    NeutralObjectType getType() override { return WATERFALL; }
};

class Labyrinth : public INeutralObject {
    NeutralObjectType getType() override { return LABYRINTH; }
};

#endif // NEUTRALOBJECTINTERFACE_H
