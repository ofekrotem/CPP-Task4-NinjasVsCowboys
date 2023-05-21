    #pragma once
    #include "Character.hpp"
    using namespace std;

    namespace ariel
    {
        class Cowboy : public Character
        {
        private:
            int currBullets;
        public:
            Cowboy(string name_arg, Point location_arg);
            Cowboy();
            void shoot(Character* enemy);
            bool hasboolets();
            void reload();
            string getType() override;
        };
        
        
    }