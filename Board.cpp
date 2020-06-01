#include <string>
#include <vector>
#include <stdexcept>
#include "Soldier.hpp"
#include "Board.hpp"
#include <iostream>
typedef unsigned int uint;
namespace WarGame
{
    Soldier *&Board::operator[](std::pair<int, int> location)
    {
        return this->board[location.first][location.second];
    }

    Soldier *Board::operator[](std::pair<int, int> location) const
    {
        return this->board[location.first][location.second];
    }

    void Board::move(uint player_number, std::pair<int, int> source, MoveDIR direction)
    {
        return;
    }

    bool Board::has_soldiers(uint player_number) const
    {
        return false;
    }

    void Board::showBoard()
    {
        std::vector<std::string> summary;
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                Soldier *current = board[i].at(j);
                if (current)
                {
                    int life = current->_hp;
                    Soldier::role job = current->_specialty;
                    int team = current->_team;
                    std::string info;
                    switch (job)
                    {
                    case Soldier::Foot:
                        info = "F" + std::to_string(team);
                        break;
                    case Soldier::Paramedic:
                        info = "P" + std::to_string(team);
                        break;
                    case Soldier::Sniper:
                        info = "S" + std::to_string(team);
                        break;
                    }
                    if (current->_commander)
                    {
                        info += "C";
                        std::cout << "|" << info;
                    }
                    else
                    {
                        std::cout << "|" << info << " ";
                    }
                    std::string data = std::to_string(i) + "," + std::to_string(j) + " ";
                    data += info + " = " + std::to_string(life);
                    summary.push_back(data);
                    data = "";
                }
                else
                {
                    std::cout << "|   ";
                }
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
        for (int i = 0; i < summary.size(); i++)
        {
            std::cout << summary[i] << std::endl;
        }
    }
} // namespace WarGame