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
    Board board(10,10);
    board[{5,4}] = new FootSoldier(1);
    board[{7,1}] = new FootSoldier(2);
    board[{0,3}] = new FootCommander(1);
    board[{7,3}] = new FootCommander(2);

    board[{0,5}] = new FootSoldier(1);
    board[{7,5}] = new FootSoldier(2);

    board[{1,7}] = new FootSoldier(1);
    board[{4,4}] = new FootSoldier(2);

    board[{2, 2}] = new FootSoldier(1);
    board[{6, 6}] = new FootCommander(2);

    board[{0,7}] = new FootSoldier(1);
    board[{0,0}] = new FootSoldier(2);

    CHECK(board[{5, 4}]->_team == 1);
    CHECK(board[{0, 3}]->_team == 1);
    CHECK(board[{0, 7}]->_team == 1);
    CHECK(board[{0, 7}]->_team == 1);
    CHECK(board[{6, 6}]->_team == 2);
    CHECK(board[{7, 1}]->_team == 2);
    CHECK(board[{7, 3}]->_team == 2);
    CHECK(board[{0, 5}]->_team == 1);
    CHECK(board[{1, 7}]->_team == 1);
    CHECK(board[{7, 5}]->_team == 2);
    CHECK(board[{4, 4}]->_team == 2);
    CHECK(board[{0, 0}]->_team == 2);
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
    Board board(10, 10);
    board[{0, 1}] = new FootSoldier(1);
    board[{0, 3}] = new FootCommander(1);
    board[{0, 5}] = new FootSoldier(1);
    board[{1, 7}] = new FootSoldier(1);
    board[{0, 7}] = new FootSoldier(1);
    board[{7, 1}] = new FootSoldier(2);
    board[{7, 3}] = new FootCommander(2);
    board[{7, 5}] = new FootSoldier(2);
    board[{7, 7}] = new FootSoldier(2);
    board[{0, 0}] = new FootSoldier(2);

    //  Not the right player
    CHECK_THROWS(board.move(1, {0, 0}, Board::Down));
    CHECK_THROWS(board.move(2, {0, 1}, Board::Down));
    CHECK_THROWS(board.move(2, {0, 3}, Board::Down));
    CHECK_THROWS(board.move(2, {0, 5}, Board::Down));
    CHECK_THROWS(board.move(2, {0, 7}, Board::Left));
    CHECK_THROWS(board.move(2, {1, 7}, Board::Down));
    CHECK_THROWS(board.move(1, {7, 1}, Board::Up));
    CHECK_THROWS(board.move(1, {7, 3}, Board::Up));
    CHECK_THROWS(board.move(1, {7, 5}, Board::Up));
    CHECK_THROWS(board.move(1, {7, 7}, Board::Up));

    //  No soldier at location.
    CHECK_THROWS(board.move(1, {1, 0}, Board::Up));
    CHECK_THROWS(board.move(1, {2, 0}, Board::Up));
    CHECK_THROWS(board.move(1, {3, 0}, Board::Up));
    CHECK_THROWS(board.move(1, {4, 0}, Board::Up));
    CHECK_THROWS(board.move(1, {6, 6}, Board::Up));
    CHECK_THROWS(board.move(1, {6, 6}, Board::Up));
    CHECK_THROWS(board.move(1, {7, 2}, Board::Up));
    CHECK_THROWS(board.move(1, {1, 3}, Board::Up));
    CHECK_THROWS(board.move(1, {4, 4}, Board::Up));
    CHECK_THROWS(board.move(1, {8, 8}, Board::Up));

    //Destination has another soldier in it
    CHECK_THROWS(board.move(1, {0, 0}, Board::Left));
    CHECK_THROWS(board.move(1, {0, 2}, Board::Right));
    CHECK_THROWS(board.move(1, {0, 7}, Board::Down));
    CHECK_THROWS(board.move(1, {1, 7}, Board::Up));

    // Destination is not available
    CHECK_THROWS(board.move(1, {0, 1}, Board::Up));
    CHECK_THROWS(board.move(1, {0, 5}, Board::Up));
    CHECK_THROWS(board.move(1, {0, 8}, Board::Up));
    CHECK_THROWS(board.move(1, {0, 9}, Board::Up));
    CHECK_THROWS(board.move(2, {9, 1}, Board::Down));
    CHECK_THROWS(board.move(2, {7, 3}, Board::Down));
    CHECK_THROWS(board.move(2, {7, 5}, Board::Down));
    CHECK_THROWS(board.move(2, {7, 7}, Board::Down));
    CHECK_THROWS(board.move(1, {0, 0}, Board::Up));
    CHECK_THROWS(board.move(1, {0, 0}, Board::Left));




//Location that are not on the board
    CHECK_THROWS(board.move(1, {100, 56}, Board::Left));
    CHECK_THROWS(board.move(1, {1200, 50}, Board::Up));
    CHECK_THROWS(board.move(1, {77, 444}, Board::Right));
    CHECK_THROWS(board.move(1, {3437, 374}, Board::Up));
    CHECK_THROWS(board.move(1, {347, 3}, Board::Right));
    CHECK_THROWS(board.move(1, {9, 77}, Board::Up));
    CHECK_THROWS(board.move(1, {23, 2438}, Board::Up));
    CHECK_THROWS(board.move(2, {334, 66}, Board::Left));
    CHECK_THROWS(board.move(2, {22, 22}, Board::Up));
    CHECK_THROWS(board.move(2, {45, 8}, Board::Up));
    CHECK_THROWS(board.move(2, {346, 3}, Board::Up));
    CHECK_THROWS(board.move(2, {82, 45}, Board::Up));
    CHECK_THROWS(board.move(1, {88, 3}, Board::Down));
    CHECK_THROWS(board.move(1, {-10, -21}, Board::Right));
    CHECK_THROWS(board.move(1, {-10, -2}, Board::Up));
    CHECK_THROWS(board.move(1, {92, 33}, Board::Down));

}
}
