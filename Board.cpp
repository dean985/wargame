#include <string>
#include <vector>
#include <stdexcept>
#include "Board.hpp"
#include "Soldier.hpp"
#include <iostream>
namespace WarGame
{
    // operator for putting soldiers on the game-board during initialization.
    Soldier *&Board::operator[](std::pair<int, int> location)
    {
        return this->board[location.first][location.second];
    }

    // operator for reading which soldiers are on the game-board.
    Soldier *Board::operator[](std::pair<int, int> location) const
    {
        Soldier *s = new Soldier(1, 2, 3);
        return s;
    }

    // The function "move" tries to move the soldier of player "player"
    //     from the "source" location to the "target" location,
    //     and activates the special ability of the soldier.
    // If the move is illegal, it throws "std::invalid_argument".
    // Illegal moves include:
    //  * There is no soldier in the source location (i.e., the soldier pointer is null);
    //  * The soldier in the source location belongs to the other player.
    //  * There is already another soldier (of this or the other player) in the target location.
    // IMPLEMENTATION HINT: Do not write "if" conditions that depend on the type of soldier!
    // Your code should be generic. All handling of different types of soldiers
    //      must be handled by polymorphism.
    void Board::move(uint player_number, std::pair<int, int> source, MoveDIR direction)
    {
        return;
    }

    // returns true iff the board contains one or more soldiers of the given player.
    bool Board::has_soldiers(uint player_number) const
    {
        return false;
    }
    void WarGame::Board::showBoard()
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; board[i].size(); j++)
            {
                Soldier *current = board[i].at(j);
                std::cout << current->_team << "," << current->_hp << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

} // namespace WarGame