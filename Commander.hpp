#pragma once
#include "Soldier.hpp"
#include <vector>
namespace WarGame
{

    class Commander
    {
    public:
        std::vector<Soldier *> soldiers;

        virtual ~Commander();

        virtual void addSoldier(Soldier *const s)
        {
        }
        virtual void addSoldiers(std::vector<Soldier *> ss);
    };
}
