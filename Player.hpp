#pragma once
#include "Game.hpp"
#include <string.h>
#include <iostream>
#include <vector>
using namespace std;

namespace coup{
    class Player{
        private:
        int coin_amount;
        string name;
        public:
        Player(Game game, string name);
        void income();
        void foreign_aid();
        void coup(Player p);
        Player role();
        int coins();
    };
}