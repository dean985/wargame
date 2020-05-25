#include "Soldier.hpp"

namespace WarGame
{
    class Paramedic : public Soldier 
    {
        public:

            Paramedic(uint team) : Soldier(100, 50, team){
        
            }
            
            // void move(WarGame::Board &, WarGame::Board::MoveDIR){
            //     return;
            // }
    };
}