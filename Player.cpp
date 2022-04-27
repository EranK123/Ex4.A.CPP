#include "Player.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;
using namespace coup;

Player::Player(Game game, string name){
    this->coin_amount = 0;
    this->game = game;
    this->name = move(name);
}

void Player::income(){
   
}

void Player::foreign_aid(){
   
}

void Player::coup( Player &p){

}

int Player::coins(){
    return -1;
}
