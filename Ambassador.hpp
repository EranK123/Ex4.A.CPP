#include "Player.hpp"
namespace coup{
    class Ambassador : public Player{
        private:

        public:
        Ambassador(Game game, string s);
        void transfer(Player p1, Player p2);
    };
}