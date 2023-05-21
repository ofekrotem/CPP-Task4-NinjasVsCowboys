#include "Ninja.hpp"

using namespace std;

namespace ariel
{
    Ninja::Ninja(int speed_arg, int HP_arg , string name_arg, Point location_arg) : Character(location_arg, HP_arg, name_arg) ,speed(speed_arg)
    {}
    
    Ninja::Ninja() : Character(), speed(0)
    {}

    void Ninja::move(Character* enemy)
    {
        this->setLocation(Point::moveTowards(this->getLocation(), enemy->getLocation(), this->speed));
    }

    void Ninja::slash(Character* enemy)
    {
        if(!this->isAlive() || !enemy->isAlive() ||  this == enemy)
        {
            __throw_runtime_error("Trying to attack dead enemy/you are dead");
        }
        if(this->distance(enemy) < 1)
        {
            enemy->hit(40);
        }
    }

    string Ninja::getType()
    {
        return "N";
    }
}