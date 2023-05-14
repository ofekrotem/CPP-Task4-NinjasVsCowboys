#include "doctest.h"
#include "Point.hpp"
#include "Character.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "Team.hpp"
#include <string>
#include <cmath>

using namespace ariel;
using namespace std;

TEST_CASE("Test Point") {
    Point p1(0,0);
    Point p2(3,4);
    CHECK(p1.distance(p2) == doctest::Approx(5.0));
    Point p3 = p1.moveTowards(p2, 1);
    CHECK(p3.getX() == doctest::Approx(0.6));
    CHECK(p3.getY() == doctest::Approx(0.8));
}

TEST_CASE("Test Character") {
    Point p1(0,0);
    Character c1(p1, 100, "Test");
    CHECK(c1.isAlive() == true);
    c1.hit(50);
    CHECK(c1.getHP() == 50);
    c1.hit(60);
    CHECK(c1.getHP() == 0);
    CHECK(c1.isAlive() == false);
}

TEST_CASE("Test Cowboy") {
    Point p1(0,0);
    Cowboy cowboy("Cowboy1", p1);
    CHECK(cowboy.hasbullets() == true);
    cowboy.shoot(&cowboy);  // Can a cowboy shoot himself?
    CHECK(cowboy.getHP() == 100);
    CHECK(cowboy.hasbullets() == true);
    cowboy.reload();
    CHECK(cowboy.hasbullets() == true);
}

TEST_CASE("Test Ninja") {
    Point p1(0,0);
    Ninja ninja(10, 100, "Ninja1", p1);
    CHECK(ninja.getHP() == 100);
    ninja.slash(&ninja);  // Can a ninja slash himself?
    CHECK(ninja.getHP() == 60);
}

TEST_CASE("Test Team") {
    Point p1(0,0);
    Point p2(3,4);
    Cowboy cowboy("Cowboy1", p1);
    Ninja ninja(10, 100, "Ninja1", p2);
    Team team1(&cowboy);
    Team team2(&ninja);
    CHECK(team1.stillAlive() == 1);
    CHECK(team2.stillAlive() == 1);
    CHECK_NOTHROW(team1.attack(&team2));
    CHECK_NOTHROW(team2.attack(&team1));
}

TEST_CASE("Test YoungNinja") {
    Point p1(0,0);
    YoungNinja youngNinja("YoungNinja1", p1);
    CHECK(youngNinja.getHP() == 100);
}

TEST_CASE("Test OldNinja") {
    Point p1(0,0);
    OldNinja oldNinja("OldNinja1", p1);
    CHECK(oldNinja.getHP() == 150);
}

TEST_CASE("Test TrainedNinja") {
    Point p1(0,0);
    TrainedNinja trainedNinja("TrainedNinja1", p1);
    CHECK(trainedNinja.getHP() == 120);
}


