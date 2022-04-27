#include "Player.hpp"
namespace coup{
    class Assassin : public Player{
        private:

        public:
        Assassin(Game game, string name);
        static void eliminate(const Player &p);
    };
}