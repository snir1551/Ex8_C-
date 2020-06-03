//
// Created by Yirat and Orian on 19/05/2020.
//

#include "doctest.h"
#include "DemoGame.hpp"
#include "FootSoldier.hpp"
#include "FootCommander.hpp"
#include "Sniper.hpp"
#include "SniperCommander.hpp"
#include "Paramedic.hpp"
#include "ParamedicCommander.hpp"
using namespace WarGame;
WarGame::Board fillBoard(){
    WarGame::Board p(6,6);
    p[{0,0}]= new FootSoldier(1);
    p[{3,3}]= new FootSoldier(2);
    p[{5,0}]= new FootCommander(1);
    p[{3,5}]= new FootCommander(2);
    p[{0,1}]= new Sniper(1);
    p[{3,0}]= new Sniper(2);
    p[{2,1}]= new SniperCommander(1);
    p[{0,3}]= new SniperCommander(2);
    p[{5,1}]= new Paramedic(1);
    p[{1,3}]= new Paramedic(2);
    p[{4,5}]= new ParamedicCommander(1);
    p[{4,0}]= new ParamedicCommander(2);
    return p;
}
WarGame::Board fillCommBoard(){
    WarGame::Board p (5,5);
    p[{0,0}] = new FootSoldier(1);
    p[{0,1}] = new FootSoldier(2);
    p[{0,3}] = new SniperCommander(2);
    p[{0,4}] = new FootCommander(2);
    p[{2,0}] = new Paramedic(2);
    p[{2,1}] = new Paramedic(1);
    p[{2,2}] = new FootCommander(1);
    p[{2,3}] = new SniperCommander(1);
    p[{4,0}] = new Sniper(1);
    p[{4,1}] = new Sniper(2);
    p[{4,3}] = new ParamedicCommander(1);
    p[{4,4}] = new ParamedicCommander(2);
    return p;
}



TEST_CASE("Check Adding player to board"){
    WarGame::Board q(1,1);
            CHECK_FALSE(q.has_soldiers(1));
            CHECK_FALSE(q.has_soldiers(2));
    WarGame::Board p = fillBoard();
            CHECK(p.has_soldiers(1));
            CHECK(p.has_soldiers(2));
            CHECK(typeid(*p[{0,0}]) == typeid(FootSoldier));
            CHECK(typeid(*p[{3,3}]) == typeid(FootSoldier));
            CHECK(typeid(*p[{5,0}]) == typeid(FootCommander));
            CHECK(typeid(*p[{3,5}]) == typeid(FootCommander));
            CHECK(typeid(*p[{0,1}]) == typeid(Sniper));
            CHECK(typeid(*p[{3,0}]) == typeid(Sniper));
            CHECK(typeid(*p[{2,1}]) == typeid(SniperCommander));
            CHECK(typeid(*p[{0,3}]) == typeid(SniperCommander));
            CHECK(typeid(*p[{5,1}]) == typeid(Paramedic));
            CHECK(typeid(*p[{1,3}]) == typeid(Paramedic));
            CHECK(typeid(*p[{4,5}]) == typeid(ParamedicCommander));
            CHECK(typeid(*p[{4,0}]) == typeid(ParamedicCommander));
}

TEST_CASE("Check Adding player to board 2"){
    WarGame::Board q(1,1);
            CHECK_FALSE(q.has_soldiers(1));
            CHECK_FALSE(q.has_soldiers(2));
    WarGame::Board p = fillCommBoard();
            CHECK(p.has_soldiers(1));
            CHECK(p.has_soldiers(2));
            CHECK(typeid(*p[{0,0}]) == typeid(FootSoldier));
            CHECK(typeid(*p[{0,1}]) == typeid(FootSoldier));
            CHECK(typeid(*p[{0,3}]) == typeid(SniperCommander));
            CHECK(typeid(*p[{0,4}]) == typeid(FootCommander));
            CHECK(typeid(*p[{2,3}]) == typeid(SniperCommander));
            CHECK(typeid(*p[{4,1}]) == typeid(Sniper));
            CHECK(typeid(*p[{2,2}]) == typeid(FootCommander));
            CHECK(typeid(*p[{2,3}]) == typeid(SniperCommander));
            CHECK(typeid(*p[{2,0}]) == typeid(Paramedic));
            CHECK(typeid(*p[{2,1}]) == typeid(Paramedic));
            CHECK(typeid(*p[{4,3}]) == typeid(ParamedicCommander));
            CHECK(typeid(*p[{4,4}]) == typeid(ParamedicCommander));
            CHECK(typeid(*p[{4,0}]) == typeid(Sniper));
}

TEST_CASE("Move function - no Commander"){
    WarGame::Board p = fillBoard();
    p.move(1,{0,0},WarGame::Board::Up);
            CHECK(p[{0,0}]== nullptr);
            CHECK(typeid(*p[{1,0}])==typeid(FootSoldier));

    p.move(1,{0,1},WarGame::Board::Right);
            CHECK(p[{0,1}]==nullptr);
            CHECK(typeid(*p[{0,2}])== typeid(Sniper));

    p.move(1,{5,1},WarGame::Board::Down);
            CHECK(p[{5,1}]==nullptr);
            CHECK(typeid(*p[{4,1}])== typeid(Paramedic));


    p.move(2,{3,0},WarGame::Board::Right);
            CHECK(p[{3,0}]== nullptr);
            CHECK(typeid(*p[{3,1}])==typeid(Sniper));

    p.move(2,{3,3},WarGame::Board::Up);
            CHECK(p[{3,3}]== nullptr);
            CHECK(typeid(*p[{4,3}])==typeid(FootSoldier));

    p.move(2,{1,3},WarGame::Board::Right);
            CHECK(p[{1,3}]== nullptr);
            CHECK(typeid(*p[{1,4}])==typeid(Paramedic));

}

TEST_CASE("Move Function - Commander"){
    WarGame::Board p = fillCommBoard();
    p.move(1,{2,2},WarGame::Board::Up);
            CHECK(p[{2,2}]==nullptr);
            CHECK(typeid(*p[{3,2}])== typeid(FootCommander));

    p.move(1,{2,3},WarGame::Board::Down);
            CHECK(p[{2,3}]==nullptr);
            CHECK(typeid(*p[{1,3}])==typeid(SniperCommander));


    p.move(1,{4,3},WarGame::Board::Down);
            CHECK(p[{4,3}]==nullptr);
            CHECK(typeid(*p[{3,3}])==typeid(ParamedicCommander));


    p.move(2,{0,4},WarGame::Board::Up);
            CHECK(p[{0,4}]==nullptr);
            CHECK(typeid(*p[{1,4}])== typeid(FootCommander));

    p.move(2,{0,3},WarGame::Board::Left);
            CHECK(p[{0,3}]==nullptr);
            CHECK(typeid(*p[{0,2}])==typeid(SniperCommander));


    p.move(2,{4,4},WarGame::Board::Down);
            CHECK(p[{4,4}]==nullptr);
            CHECK(typeid(*p[{3,4}])==typeid(ParamedicCommander));
}

TEST_CASE("Exceptions") {
    WarGame::Board p = fillBoard();
    //Out of board
            CHECK_THROWS(p.move(1, {5, 1}, WarGame::Board::Up));
            CHECK_THROWS(p.move(1, {0, 0}, WarGame::Board::Down));
            CHECK_THROWS(p.move(2, {3, 5}, WarGame::Board::Right));
            CHECK_THROWS(p.move(1, {4, 5}, WarGame::Board::Right));
            CHECK_THROWS(p.move(1, {5, 0}, WarGame::Board::Left));
    //Busy place
            CHECK_THROWS(p.move(2, {4, 0}, WarGame::Board::Up));
            CHECK_THROWS(p.move(2, {3, 0}, WarGame::Board::Up));
            CHECK_THROWS(p.move(2, {0, 3}, WarGame::Board::Up));
            CHECK_THROWS(p.move(2, {1, 3}, WarGame::Board::Down));
            CHECK_THROWS(p.move(1, {0, 1}, WarGame::Board::Left));
    //Null Place
            CHECK_THROWS(p.move(1, {2, 0}, WarGame::Board::Up));
            CHECK_THROWS(p.move(1, {4, 3}, WarGame::Board::Up));
            CHECK_THROWS(p.move(1, {2, 2}, WarGame::Board::Down));
            CHECK_THROWS(p.move(2, {1, 0}, WarGame::Board::Right));
            CHECK_THROWS(p.move(2, {5, 4}, WarGame::Board::Left));
    //Source out of bound
            CHECK_THROWS(p.move(1, {6, 0}, WarGame::Board::Up));
            CHECK_THROWS(p.move(1, {7, 3}, WarGame::Board::Up));
            CHECK_THROWS(p.move(1, {8, 2}, WarGame::Board::Down));
            CHECK_THROWS(p.move(2, {9, 0}, WarGame::Board::Right));
            CHECK_THROWS(p.move(2, {10, 4}, WarGame::Board::Left));
}

TEST_CASE("Check Moves"){
    WarGame::Board p = fillBoard();
            CHECK_NOTHROW(p.move(1,{0,0},WarGame::Board::Up));
            CHECK_NOTHROW(p.move(1,{0,1},WarGame::Board::Left));
            CHECK_NOTHROW(p.move(1,{2,1},WarGame::Board::Down));
            CHECK_NOTHROW(p.move(2,{3,0},WarGame::Board::Down));
            CHECK_NOTHROW(p.move(2,{3,3},WarGame::Board::Right));
            CHECK_NOTHROW(p.move(2,{3,5},WarGame::Board::Down));
            CHECK_NOTHROW(p.move(2,{4,0},WarGame::Board::Down));
            CHECK_NOTHROW(p.move(1,{4,5},WarGame::Board::Up));
            CHECK_NOTHROW(p.move(1,{5,0},WarGame::Board::Down));
            CHECK_NOTHROW(p.move(1,{5,1},WarGame::Board::Right));
            CHECK_NOTHROW(p.move(1,{5,2},WarGame::Board::Right));
            CHECK_NOTHROW(p.move(1,{5,5},WarGame::Board::Left));
            CHECK_NOTHROW(p.move(1,{4,0},WarGame::Board::Right));
}
TEST_CASE("Extra"){
    WarGame::Board b (4,4);
            CHECK(!b.has_soldiers(1));
            CHECK(!b.has_soldiers(2));
    b[{0,0}]= new FootSoldier(1);
            CHECK(!b.has_soldiers(2));
            CHECK(b.has_soldiers(1));
    b[{3,3}] = new Sniper(2);
            CHECK(b.has_soldiers(1));
            CHECK(b.has_soldiers(2));
    b.move(1,{0,0},WarGame::Board::Up);
            CHECK(b.has_soldiers(1));
            CHECK(b.has_soldiers(2));
    b.move(2,{3,3},WarGame::Board::Down);
            CHECK(b.has_soldiers(1));
            CHECK(b.has_soldiers(2));
    b.move(2,{2,3},WarGame::Board::Down);
            CHECK(b.has_soldiers(2));
            CHECK(!b.has_soldiers(1));

}
