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

    virtual void hit(Board &board, std::pair<int, int> source) = 0;
    virtual void hit(std::vector<std::vector<Soldier *>> &board, std::pair<int, int> source) = 0;

    virtual void heal() = 0;
    //     void print_board(std::vector<std::vector<Soldier*>> &board,std::pair<int,int> source){
    //     std::cout << std::fixed << std::setprecision(2) << std::setfill('0');
    //     for(int i=0; i<board.size();i++){
    //         for(int j=0; j< board.size();j++){
    //             if( i == source.first && j == source.second){
    //                     std::cout << "||" << std::setw(9) << "!!!!!!!!!";
    //             }
    //             else if (board[i][j]==0)
    //             {
    //                 std::cout << "||" << std::setw(9)<< "000000000";
    //             }
    //             else
    //             {
    //                 std::cout << "||" << std::setw(9)<<  board[i][j];
    //             }

    //         }
    //         std::cout << "||" << std::endl;
    //     }
    //     std::cout << "" << std::endl;
    // }
    virtual ~Soldier() {}
};
