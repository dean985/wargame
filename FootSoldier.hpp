#pragma once
#include "Soldier.hpp"

class FootSoldier : public Soldier
{
    const int maxLife = 100;

public:
    FootSoldier(int team) : Soldier(100, 10, role::Foot, false, team) {}

    virtual void hit(std::vector<std::vector<Soldier *>> &board, std::pair<int, int> source) override
    {
        Soldier *victim = ClosestSoldier(board, source);
        if(victim){
            victim->_hp -= this->_dpa;
        }
    }

    Soldier *ClosestSoldier(std::vector<std::vector<Soldier *>> &board, std::pair<int, int> source)
    {
        //If out of boundries of the board
        if (source.first < 0 || source.first >= board.size() || source.second < 0 || source.second >= board[source.first].size() || board[source.first][source.second] == (Soldier *)-1){
            return nullptr;
        }
        Soldier *res = board[source.first][source.second];
        if (res != nullptr && res->_team != this->_team)
            return res;
        board[source.first][source.second] = (Soldier *)-1;
        res = ClosestSoldier(board, std::pair<int, int>{source.first + 1, source.second});
        if (res != nullptr)
            return res;
        res = ClosestSoldier(board, std::pair<int, int>{source.first - 1, source.second});
        if (res != nullptr)
            return res;
        res = ClosestSoldier(board, std::pair<int, int>{source.first, source.second + 1});
        if (res != nullptr)
            return res;
        return ClosestSoldier(board, std::pair<int, int>{source.first, source.second - 1});
    }

    void heal() override
    {
        _hp = maxLife;
    }
};