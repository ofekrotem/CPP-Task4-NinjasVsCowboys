#pragma once
#include "Character.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include <vector>
using namespace std;

namespace ariel
{
    class Team
    {
    private:
        Character* leader;
        vector<Character*> cowboys;
        vector<Character*> ninjas;
    public:
        Team(Character* leader);
        Team();
        Character* getLeader();
        void setLeader(Character* new_leader);
        vector<Character*> getMembers();
        void add(Character* new_member);
        void attack(Team* enemy_team);
        int stillAlive();
        void print();
        void findNewLeader();
        Character* findClosestEnemy(Team* enemyTeam);


    };
    
}