#pragma once
#include "Character.hpp"
#include <iostream>

using namespace std;

namespace ariel
{
    class Ninja : public Character
    {
    private:
        int speed;
    public:
        Ninja(int speed_arg, int HP_arg, string name_arg, Point location_arg);
        Ninja();
        void move(Character* enemy);
        void slash(Character* enemy);
        string getType() override;
    };
    
    class YoungNinja : public Ninja
    {
    public:
        YoungNinja(string name_arg, Point location_arg);
        YoungNinja();
    };
    
    class OldNinja : public Ninja
    {
    public:
        OldNinja(string name_arg, Point location_arg);
        OldNinja();
    };

    class TrainedNinja : public Ninja
    {
    public:
        TrainedNinja(string name_arg, Point location_arg);
        TrainedNinja();
    };
}