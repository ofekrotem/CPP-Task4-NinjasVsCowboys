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
        this->setLocation(this->getLocation().moveTowards(enemy->getLocation(),this->speed));
    }

    void Ninja::slash(Character* enemy)
    {
        if(this->isAlive() && this->distance(enemy) < 1)
        {
            enemy->hit(40);
        }
    }

    string Ninja::getType()
    {
        return "N";
    }

    YoungNinja::YoungNinja(string name_arg, Point location_arg) : Ninja(14,100,name_arg,location_arg)
    {}

    YoungNinja::YoungNinja() : Ninja()
    {}

    OldNinja::OldNinja(string name_arg, Point location_arg) : Ninja(8,150,name_arg,location_arg)
    {}

    OldNinja::OldNinja() : Ninja()
    {}

    TrainedNinja::TrainedNinja(string name_arg, Point location_arg) : Ninja(12,120,name_arg,location_arg)
    {}

    TrainedNinja::TrainedNinja() : Ninja()
    {}
}