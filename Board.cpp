#include <string>
#include <vector>
#include <stdexcept>
#include "Soldier.hpp"
#include "Board.hpp"
typedef unsigned int uint;
namespace WarGame{
    Soldier*& Board::operator[](std::pair<int,int> location){
        return this->board[location.first][location.second];
    }
    
    Soldier* Board::operator[](std::pair<int,int> location) const{
        return this->board[location.first][location.second];
    }
    
    void Board::move(uint player_number, std::pair<int,int> source, MoveDIR direction){
        return;
    }

    bool Board::has_soldiers(uint player_number) const{
        return false;
    }
    
}