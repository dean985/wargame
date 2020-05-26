#pragma once
// #include "Board.hpp"
namespace WarGame
{
    typedef unsigned int uint;

    class Soldier
    {
    public:
        uint _hp;
        uint _dpa;
        uint _team;
        
        Soldier(uint hp, uint dpa, uint team){
            _hp = hp;
            _dpa = dpa;
            _team = team;
        }
        virtual ~Soldier(){}
        virtual void attack(Board &board, Board::MoveDIR);
    };
} 