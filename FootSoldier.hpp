#pragma once
#include "Soldier.hpp"

class FootSoldier : public Soldier{
    public:
    FootSoldier(uint team) : Soldier(100, 10, team){
        
    }
    ~FootSoldier();
    void move(WarGame::Board &, WarGame::Board::MoveDIR);
};


FootSoldier::~FootSoldier(){
    Soldier::~Soldier();
}

