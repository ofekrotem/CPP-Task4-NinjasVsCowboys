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
        if(this->hasbullets())
        {
            this->currBullets-=1;
            enemy->hit(10);
        } else 
        {
            this->reload();
        }       
    }

    bool Cowboy::hasbullets()
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