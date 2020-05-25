#include <string>
#include <vector>
#include <stdexcept>
#include "Board.hpp"
#include "Soldier.hpp"
namespace WarGame
{
        // operator for putting soldiers on the game-board during initialization.
        Soldier *&Board::operator[](std::pair<int, int> location)
        {
            Soldier *s = nullptr;
            return s;
        }

        // operator for reading which soldiers are on the game-board.
        Soldier *Board::operator[](std::pair<int, int> location) const
        {
            Soldier *s = nullptr;
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
    

} 