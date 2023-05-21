#pragma once
#include "Character.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"
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
        vector<Character*> allMembers;
    public:
        Team(Character* leader);
        Team();
        Character* getLeader();
        void setLeader(Character* new_leader);
        vector<Character*> getMembers();
        vector<Character*> getNinjas();
        vector<Character*> getCowboys();
        
        virtual vector<Character*> getMembersByTeam();
        void add(Character* new_member);
        void attack(Team* enemy_team);
        int stillAlive();
        void print();
        void findNewLeader();
        Character* findClosestEnemy(Team* enemyTeam);


    };
    
}