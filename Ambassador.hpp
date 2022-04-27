#include "Player.hpp"
#include <string.h>
#include <iostream>
#include <vector>
using namespace std;
namespace coup{
    class Ambassador : public Player{
        public:
        Ambassador(Game game, string name);
        static void transfer(const Player &p1, const Player &p2);
    };
}