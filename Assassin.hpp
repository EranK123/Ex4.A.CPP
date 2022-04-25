#include "Player.hpp"
namespace coup{
    class Assassin : public Player{
        private:

        public:
        Assassin(Game game, string s);
        void eliminate(Player p);

    };
}