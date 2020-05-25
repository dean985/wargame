#pragma once
namespace WarGame
{
    class Soldier
    {
    public:
        // typedef unsigned int uint;
        uint _hp;
        uint _dpa;
        // std::pair<int, int> _location;
        uint _team;

        Soldier(uint hp, uint dpa, uint team){
            _hp = hp;
            _dpa = dpa;
            _team = team;
        }

        // virtual void move(WarGame::Board &board, WarGame::Board::MoveDIR);
    };
} 