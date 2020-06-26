#ifndef ENUM_H
#define ENUM_H

enum UnitType { ATTACKER_ELF, ATTACKER_CLERIC, ATTACKER_DWARF,
                DEFENDER_ELF, DEFENDER_CLERIC, DEFENDER_DWARF };

enum LandscapeType {FOREST, MOUNTAIN, PLAIN};

enum NeutralObjectType { CASTLE, WATERFALL, DUNGEON, LABYRINTH };

enum UnitEventType { CREATE, DESTROY };//создание и уничтожение юнитов

enum InfluenceType { ATTACK, PROTECT, HEAL };


enum EventType { UNITEVENT, LANDSCAPEEVENT, NEUTRALEVENT, BOARDEVENT };

#endif // ENUM_H
