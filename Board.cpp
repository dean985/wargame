#include <string>
#include <vector>
#include <stdexcept>
#include "Soldier.hpp"
#include "Board.hpp"
#include <iostream>
#include <unistd.h>

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
        
        std::pair<int,int> next_location;
        if(this->board[source.first][source.second] == nullptr)
        {
            std::cout << "no soldier on this area!" << std::endl;
            return;
        }
        else
        {// check if the choosen soldire is from the player_number
            if((*this)[source]->_team != player_number)
            {
                std::cout << "the soldier is not on player "<<player_number <<" team!" << std::endl;
                return;
            }
            else{
                // now we need to check where we move and if is it avilible
                switch(direction) {
                        case Up:
                            if(this->board.size()-1< source.first+1)
                            {
                                std::cout << "can't reach the destination" << std::endl;
                                return;
                            }
                            else
                            {
                                if((*this)[{source.first+1,source.second}] != nullptr)
                                {
                                    std::cout << "can't reach the destination" << std::endl;
                                    return;
                                }
                                else{
                                    next_location.first = source.first+1;
                                    next_location.second = source.second;
                                    
                                 
                                }
                            }
                            break;
                        case Down:
                            if(0 > source.first-1)
                            {
                                std::cout << "can't reach the destination" << std::endl;
                                return;
                            }
                            else
                            {
                                if((*this)[{source.first-1,source.second}] != nullptr)
                                {
                                    std::cout << "can't reach the destination" << std::endl;
                                    return;
                                }
                                else{
                                    
                                    next_location.first = source.first-1;
                                    next_location.second = source.second;
                        
                                }
                            }
                            break;
                        case Right:
                            if(this->board[0].size()-1< source.second + 1)
                            {
                                std::cout << "can't reach the destination" << std::endl;
                                return;
                            }
                            else
                            {
                                if((*this)[{source.first,source.second+1}] != nullptr)
                                {
                                    std::cout << "can't reach the destination" << std::endl;
                                    return;
                                }
                                else{
                                    next_location.first = source.first;
                                    next_location.second = source.second+1;
                                 
                                }
                            }
                            break;
                        case Left:
                            if(0 > source.second - 1)
                            {
                                std::cout << "can't reach the destination" << std::endl;
                                return;
                            }
                            else
                            {
                                if((*this)[{source.first,source.second-1}] != nullptr)
                                {
                                    std::cout << "can't reach the destination" << std::endl;
                                    return;
                                }
                                else{
                                    next_location.first = source.first;
                                    next_location.second = source.second-1;
        
                                }
                            }
                            break;
                        default:
                            std::cout << "unrecognized direction" << std::endl;
                    }   
            }
               (*this)[next_location] = (*this)[source];
                (*this)[source] = nullptr;
        }
        (*this)[next_location]->hit(this->board,next_location); 
        std::cout << direction << "\n" << std::endl;
         
        this->showBoard();
        
        /// here I call the hit!
        
        return;
    }

  

    bool Board::has_soldiers(uint player_number) const
    {
        

         for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                Soldier *current = board[i].at(j);
                if(current != nullptr)
                {
                    if(current->_team == player_number)
                        return true;
                    
                }
            }
            
        }
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
        
        usleep(500000);
    }
} // namespace WarGame