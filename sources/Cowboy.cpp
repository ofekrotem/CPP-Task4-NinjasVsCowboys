#include "Cowboy.hpp"

using namespace std;

namespace ariel
{
    Cowboy::Cowboy(string name_arg, Point location_arg) : Character(location_arg,110,name_arg), currBullets(6)
    {}
    
    Cowboy::Cowboy() : Character(), currBullets(0)
    {}

    void Cowboy::shoot(Character* enemy)
    {
        if(!this->isAlive() || !enemy->isAlive() || this == enemy)
        {
            __throw_runtime_error("Trying to attack dead enemy/you are dead");
        }
        if(this->hasboolets())
        {
            this->currBullets-=1;
            enemy->hit(10);
        }      
    }

    bool Cowboy::hasboolets()
    {
        return this->currBullets > 0;
    }

    void Cowboy::reload()
    {
        if (!this->isAlive())
        {
            __throw_runtime_error("U R DEAD!");
        }
        this->currBullets = 6;
    }

    string Cowboy::getType() 
    {
        return "C";
    }
}