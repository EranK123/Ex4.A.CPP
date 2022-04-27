#include "Ambassador.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>
#include <string.h>
using namespace std;
using namespace coup;

Ambassador::Ambassador(Game game, string name) : Player(game, move(name)){

}


void Ambassador::transfer(const Player &p1, const Player &p2){

}