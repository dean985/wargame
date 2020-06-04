#pragma once

#include <vector>
  
class Board;

class Soldier
{
public:
    enum role
    {
        Foot,
        Paramedic,
        Sniper
    };
    int _hp;
    int _dpa;
    int _team;
    role _specialty;
    bool _commander;

    Soldier(int hp, int dpa, role specialty, bool commander, int team) : _hp(hp), _dpa(dpa), _team(team), _specialty(specialty), _commander(commander) {}

    // virtual void hit(Board &board, std::pair<int, int> source) = 0;
    virtual void hit(std::vector<std::vector<Soldier *>> &board, std::pair<int, int> source) = 0;
    virtual void hitAll(std::vector<std::vector<Soldier *>> &board, std::pair<int, int> source) = 0;
    virtual void heal() = 0;
    
    virtual ~Soldier() {}
};
