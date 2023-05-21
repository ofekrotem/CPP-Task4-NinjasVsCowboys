#include "Character.hpp"

using namespace std;

namespace ariel
{
    Character::Character(Point location_arg, int HP_arg, string name_arg)
    {
        this->location = location_arg;
        this->HP = HP_arg;
        this->name = name_arg;
        this->isLeader = false;
        this->isTeamMember = false;
    }
    
    Character::Character()
    {
        this->location = Point(0,0);
        this->HP = 0;
        this->name = "Default";
        this->isLeader = false;
        this->isTeamMember = false;
    }

    double Character::distance(Character* other) 
    {
        return this->location.distance(other->getLocation());
    }

    bool Character::isAlive()
    {
        return this->HP > 0;
    }

    void Character::hit(int dmg)
    {
        if(dmg < 0 )
        {
            __throw_invalid_argument("Negative dmg given");
        }
        this->HP -= dmg;
        if(this->HP <=0)
        {
            this->HP = 0;
        }
    }

    string Character::getName()
    {
        return this->name;
    }

    int Character::getHP()
    {
        return this->HP;
    }

    Point Character::getLocation()
    {
        return this->location;
    }
    
    string Character::getType()
    {
        return "Character";
    }

    string Character::print()
    {
        if(this->isAlive())
        {
            return this->getType() + " " + this->getName()+" , "+to_string(this->HP)+" , "+this->getLocation().print();
        }
        return "(" + this->getType() + " " + this->getName() +") , " + this->location.print();
    }

    void Character::setLocation(Point dest)
    {
        this->location = dest;
    }
    
    bool Character::getIsLeader()
    {
        return this->isLeader;
    }

    void Character::makeLeader()
    {
        if(this->isLeader || !this->isAlive())
        {
            __throw_runtime_error("Can't assign to be leader");
        }
        this->isLeader = true;
    }

    bool Character::getIsTeamMember()
    {
        return this->isTeamMember;
    }

    void Character::makeTeamMember()
    {
        if(this->isTeamMember || !this->isAlive())
        {
            __throw_runtime_error("Can't add to team");
        }
        this->isTeamMember = true;
    }
}