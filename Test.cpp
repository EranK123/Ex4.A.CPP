#include "doctest.h"
#include "Player.hpp"
#include "Duke.hpp"
#include "Assassin.hpp"
#include "Ambassador.hpp"
#include "Captain.hpp"
#include "Contessa.hpp"
#include "Game.hpp"

using namespace coup;

#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

TEST_CASE("Coup with no coins"){
    Game game_1{};
	Duke duke{game_1, "Moshe"};
	Assassin assassin{game_1, "Yossi"};
	Ambassador ambassador{game_1, "Meirav"};
	Captain captain{game_1, "Reut"};
	Contessa contessa{game_1, "Gilad"};

    CHECK_THROWS(duke.coup(assassin));
    CHECK_THROWS(captain.coup(contessa));
    CHECK_THROWS(ambassador.coup(contessa));
}

TEST_CASE("Didnt coup"){
    Game game_1{};
    Duke duke{game_1, "Moshe"};
	Assassin assassin{game_1, "Yossi"};
    duke.foreign_aid();
    assassin.foreign_aid();
    duke.foreign_aid();
    assassin.foreign_aid();
    duke.foreign_aid();
    assassin.foreign_aid();
    duke.foreign_aid();
    assassin.foreign_aid();
    duke.foreign_aid();
    assassin.foreign_aid();
    CHECK_THROWS(duke.income());
    CHECK_THROWS(assassin.income());
}

TEST_CASE("Bad"){
Game game_1{};
	Assassin assassin{game_1, "Yossi"};
    Ambassador ambassador{game_1, "Meirav"};
    Duke duke{game_1, "Moshe"};
    assassin.foreign_aid();
    ambassador.foreign_aid();
    CHECK_THROWS(duke.block(assassin));
    assassin.income();
    ambassador.income();
    duke.income();
    CHECK_THROWS(assassin.eliminate(duke));
}

TEST_CASE("Also bad"){
    Game game_1{};
	Assassin assassin{game_1, "Yossi"};
    Ambassador ambassador{game_1, "Meirav"};
    Duke duke{game_1, "Moshe"};
    Captain captain{game_1, "Reut"};
	Contessa contessa{game_1, "Gilad"};
    CHECK_THROWS(ambassador.income());
    CHECK_THROWS(duke.foreign_aid());
    CHECK_THROWS(captain.steal(contessa));
    CHECK_THROWS(contessa.block(assassin));
    CHECK_THROWS(captain.income());
    CHECK_THROWS(game_1.winner());
}

TEST_CASE("Good Coins"){
    Game game_1{};
	Assassin assassin{game_1, "Yossi"};
    Ambassador ambassador{game_1, "Meirav"};
    Duke duke{game_1, "Moshe"};
    Captain captain{game_1, "Reut"};
	Contessa contessa{game_1, "Gilad"};
    CHECK(assassin.coins() == 0);
    assassin.foreign_aid();
    CHECK(assassin.coins() == 2);
    ambassador.income();
    CHECK(ambassador.coins() == 1);
    duke.tax();
    CHECK(duke.coins() == 3);
    captain.steal(duke);
    CHECK(captain.coins() == 2);
    contessa.foreign_aid();
    CHECK(contessa.coins() == 2);
    assassin.income();
    CHECK(assassin.coins() == 3);
    ambassador.transfer(duke, contessa);
    CHECK(duke.coins() == 2);
    CHECK(contessa.coins() == 3);
    duke.tax();
    CHECK(duke.coins() == 5);
}

