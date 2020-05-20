#pragma once
#include "Soldier.hpp"
#include "Commander.hpp"
#include <typeinfo>

class FootCommander: public Soldier, public Commander{
    public:
    FootCommander(uint team) : Soldier(150, 50, team) {}
    ~FootCommander();

    void addSoldier(Soldier * const s);
    void addSoldiers(std::vector<Soldier *> ss);
};

FootCommander::~FootCommander(){
    Soldier::~Soldier();
}


