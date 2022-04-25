#include "Game.cpp"
namespace coup{
    class Player{
        private:
        int coin_amount;
        
        public:
        Player();
        void income();
        void foreign_aid();
        void coup(Player p);
        int coins();
    };
}