#pragma once
#include "Soldier.hpp"
#include <cstdlib>

class FootSoldier : public Soldier
{
    const int maxLife = 100;

public:
    FootSoldier(int team) : Soldier(100, 10, role::Foot, false, team) {}

    virtual void hit(std::vector<std::vector<Soldier *>> &board, std::pair<int, int> source) override
    {
        int dist1 = board.size() + board[0].size();
        int Distance ;
        Soldier** nearSoldier = nullptr;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                Distance = abs(j-source.second) + abs(i - source.first) ;

                if (board[i][j] != nullptr && board[i][j]->_team != this->_team && Distance < dist1){
                    dist1 = Distance;
                    nearSoldier = &board[i][j];
                }

            }
        }
        if (nearSoldier){
            //(*nearSoldier)->harm(this(footsoldier)->_dpa, nearSoldier);
            (*nearSoldier)->_hp -= this->_dpa;
            if ((*nearSoldier)->_hp <=0){
                (*nearSoldier) = nullptr;
            }
        }else {
            //Soldier couldn't find someone to shoot at.
            //No one got shot.
            throw "FootSoldier couldn't find someone to shoot at";
        }
    }

    // Soldier *ClosestSoldier(std::vector<std::vector<Soldier *>> &board, std::pair<int, int> source)
    // {
    //     //If out of boundries of the board
    //     if (source.first < 0 || source.first >= board.size() || source.second < 0 || source.second >= board[source.first].size() || board[source.first][source.second] == (Soldier *)-1)
    //     {
    //         return nullptr;
    //     }
    //     Soldier *res = board[source.first][source.second];
    //     if (res != nullptr && res->_team != this->_team)
    //         return res;
    //     board[source.first][source.second] = (Soldier *)-1;
    //     res = ClosestSoldier(board, std::pair<int, int>{source.first + 1, source.second});
    //     if (res != nullptr)
    //         return res;
    //     res = ClosestSoldier(board, std::pair<int, int>{source.first - 1, source.second});
    //     if (res != nullptr)
    //         return res;
    //     res = ClosestSoldier(board, std::pair<int, int>{source.first, source.second + 1});
    //     if (res != nullptr)
    //         return res;
    //     return ClosestSoldier(board, std::pair<int, int>{source.first, source.second - 1});
    // }

    void heal() override
    {
        _hp = maxLife;
    }
};