#pragma once
#include "Soldier.hpp"
#include "Commander.hpp"
// #include <typeinfo>
namespace WarGame
{

    class ParamedicCommander : public WarGame::Soldier, public WarGame::Commander
    {
    public:
        ParamedicCommander(uint team) : Soldier(120, 100, team) {}

        // void addSoldier(Soldier * const s);
        // void addSoldiers(std::vector<Soldier *> ss);
    };
} 
