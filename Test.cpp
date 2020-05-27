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

WarGame::Board game1()
{
    WarGame::Board board(10, 10);

    board[{0, 3}] = new WarGame::Sniper(1);
    board[{0, 2}] = new WarGame::Sniper(2);
    board[{9, 1}] = new WarGame::FootSoldier(1);
    board[{9, 2}] = new WarGame::FootSoldier(2);
    board[{6, 5}] = new WarGame::ParamedicCommander(1);
    board[{4, 0}] = new WarGame::ParamedicCommander(2);
    board[{2, 5}] = new WarGame::FootCommander(1);
    board[{2, 4}] = new WarGame::FootCommander(2);
    board[{2, 1}] = new WarGame::SniperCommander(1);
    board[{5, 3}] = new WarGame::SniperCommander(2);
    board[{8, 4}] = new WarGame::Paramedic(1);
    board[{8, 3}] = new WarGame::Paramedic(2);
    board.showBoard();
    return board;
}

TEST_CASE("Test for The boards Functions")
{
    
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