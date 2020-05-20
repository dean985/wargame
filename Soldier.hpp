#pragma once
#include "Board.hpp"

class Soldier{
    public:
        // typedef unsigned int uint;
        uint _hp;
        uint _dpa;
        std::pair<int, int> _location;
        uint _team;

        Soldier();
        Soldier(uint hp, uint dpa, uint team);
        virtual ~Soldier();

        virtual void move(WarGame::Board &, WarGame::Board::MoveDIR);
};