#pragma once
#include "Point.hpp"
#include <iostream>
using namespace std;
namespace ariel
{
class Character
{
private:
   Point location;
   int HP;
   string name;

   
public:
    Character(Point location_arg, int HP_arg, string name_arg);
    Character();
    bool isAlive();
    double distance(Character* other);
    void hit(int dmg);
    string getName();
    int getHP();
    Point getLocation();
    void setLocation(Point dest);
    string print();
    virtual string getType();
};
}
