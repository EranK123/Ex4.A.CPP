namespace coup{
    class Duke : public Player{
        private:

        public:
        Duke(Game game, string s);
        void tax();
        void block(Player p);
    };
}