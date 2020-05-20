#pragma once
#include "FootCommander.hpp"

void FootCommander::addSoldier(Soldier * const s){
    this->Commander::soldiers.push_back(s);
    return;
}

void FootCommander::addSoldiers(std::vector<Soldier *> ss){
    for (Soldier* sold : ss){
        if (typeid(sold).name() == "FootSoldier"){
            this->addSoldier(sold);
        }
    }
}