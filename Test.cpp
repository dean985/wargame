#include "doctest.h"

#include "FootSoldier.hpp"
#include "FootCommander.hpp"
#include "Sniper.hpp"
#include "SniperCommander.hpp"
#include "Paramedic.hpp"
#include "ParamedicCommander.hpp"

#include "DemoGame.hpp"
#include "Board.hpp"

/*

about 8 Testcases

thats mean 13 tests for each testcase

*/

class Sniper;
namespace WarGame{
Board game1()
{
    WarGame::Board board(10, 10);

    board[{0, 3}] = new Sniper(1);
    board[{0, 2}] = new Sniper(2);
    board[{9, 1}] = new FootSoldier(1);
    board[{9, 2}] = new FootSoldier(2);
    board[{6, 5}] = new ParamedicCommander(1);
    board[{4, 0}] = new ParamedicCommander(2);
    board[{2, 5}] = new FootCommander(1);
    board[{2, 4}] = new FootCommander(2);
    board[{2, 1}] = new SniperCommander(1);
    board[{5, 3}] = new SniperCommander(2);
    board[{8, 4}] = new Paramedic(1);
    board[{8, 3}] = new Paramedic(2);

    //board.showBoard();
    return board;
}
Board game2()
{
    WarGame::Board board(10, 10);

    board[{0, 3}] = new Sniper(2);
    board[{0, 2}] = new Sniper(2);
    board[{9, 1}] = new FootSoldier(2);
    board[{9, 2}] = new FootSoldier(2);
    board[{6, 5}] = new ParamedicCommander(2);
    board[{4, 0}] = new ParamedicCommander(2);


    //board.showBoard();
    return board;
}
TEST_CASE("Test for The boards Functions")
{
    Board b = game1();
    Board c = game2();
    CHECK(b[{9,2}]->_team == 2);
    CHECK(b[{0,3}]->_team == 1);
    CHECK(b.has_soldiers(1)==true);
    CHECK(c.has_soldiers(1)==false);
    CHECK(b.has_soldiers(2)==true);
    CHECK(c.has_soldiers(2)==true);
    CHECK(c[{9,1}]->_specialty == Soldier::role::Foot);//7

    
    //now we check move function
    c.move(2,{9,1},(Board::MoveDIR::Down));
    CHECK(c[{8,1}]->_specialty == Soldier::role::Foot);//throw segfault cuse the move failed
    
    //8
    
        c.move(2,{0,3},(Board::MoveDIR::Up));
        //CHECK(c[{1,3}]->_specialty == Soldier::role::Sniper);//7
    //9
    
    //10
    
    //11
    
    //12
    
    //13
    
    
    
}

TEST_CASE("Test for The FootSoldier Functions")
{
    
}
TEST_CASE("Test for The FootCommander Functions")
{
    
}
TEST_CASE("Test for The paramedic Functions")
{
    
}
TEST_CASE("Test for The paramedicCommander Functions")
{
    
}
TEST_CASE("Test for The sniper Functions")
{
    
}
TEST_CASE("Test for The sniperCommander Functions")
{
    
}
TEST_CASE("General Test for other situations")
{
    
}
}