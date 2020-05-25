#pragma once
#include "Soldier.hpp"
#include "Commander.hpp"
#include <typeinfo>
namespace WarGame
{

    class FootCommander : public WarGame::Soldier, public WarGame::Commander
    {
    public:
        FootCommander(uint team) : Soldier(150, 50, team) {}

        // void addSoldier(Soldier *const s);
        // void addSoldiers(std::vector<Soldier *> ss);
    };


    // void FootCommander::addSoldier(Soldier *const s)
    // {
    //     this->Commander::soldiers.push_back(s);
    //     return;
    // }

    // void FootCommander::addSoldiers(std::vector<Soldier *> ss)
    // {
    //     for (Soldier *sold : ss)
    //     {
    //         if (typeid(sold).name() == "FootSoldier")
    //         {
    //             this->addSoldier(sold);
    //         }
    //     }
    // }
} 