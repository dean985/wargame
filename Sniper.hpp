#include "Soldier.hpp"

namespace WarGame
{
    class Sniper : public Soldier 
    {
        public:

            Sniper(uint team) : Soldier(100, 50, team){
        
            }
            
            // void move(WarGame::Board &, WarGame::Board::MoveDIR){
            //     return;
            // }
    };
}