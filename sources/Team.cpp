#include "Team.hpp"
#include <iostream>
#include <limits>


using namespace std;

namespace ariel
{
    Team::Team(Character* leader_arg)
    {
        if(leader_arg->getIsLeader()){
            __throw_runtime_error("Already leading another team");
        }
        this->leader = leader_arg;
        this->leader->makeLeader();
        this->leader->makeTeamMember();
        this->allMembers.push_back(this->leader);
        if(leader_arg->getType() == "C")
        {
            this->cowboys.push_back(this->leader);
        } else
        {
            this->ninjas.push_back(this->leader);
        }
        
    }
    
    Team::Team()
    {
        this->leader = new Character();
        this->leader->makeLeader();
        this->leader->makeTeamMember();
        this->allMembers.push_back(this->leader);
    }

    Character* Team::getLeader()
    {
        return this->leader;
    }

    void Team::setLeader(Character* new_leader)
    {
        if(new_leader->getIsLeader()){
            __throw_runtime_error("Already leading another team");
        }
        this->leader = new_leader;
        this->leader->makeLeader();

    }

    vector<Character*> Team::getMembersByTeam()
    {
        vector<Character*> allMembers = this->cowboys;
        allMembers.insert(allMembers.end(), this->ninjas.begin(), this->ninjas.end());
        return allMembers;
    }

    vector<Character*> Team::getMembers()
    {
        return this->allMembers;
    }

    vector<Character*> Team::getCowboys()
    {
        return this->cowboys;
    }

    vector<Character*> Team::getNinjas()
    {
        return this->ninjas;
    }


    void Team::add(Character* new_member)
    { 
        if(this->allMembers.size() == 10) {
            __throw_runtime_error("Max team members reached - 10");
        }
        if(!new_member){
            __throw_invalid_argument("Given null member pointer");
        }
        if(new_member->getIsTeamMember()){
             __throw_runtime_error("Alreading a member of another team");
        }
        this->allMembers.push_back(new_member);
        new_member->makeTeamMember();
        if(new_member->getType() == "C")
        {
            this->cowboys.push_back(new_member);    
        } else
        {
            this->ninjas.push_back(new_member);
        }
    }

    void Team::findNewLeader()
    {
        double minDistance = numeric_limits<double>::max();
        Character* newLeader = this->getMembersByTeam().front();
        for(Character* member : this->getMembersByTeam()) {
            if(member->isAlive())
            {
                double dist = this->leader->distance(member);
                if(dist < minDistance)
                {
                    minDistance = dist;
                    newLeader = member;
                }
            }
        }
        this->leader = newLeader;
    }

    Character* Team::findClosestEnemy(Team* enemyTeam)
    {
        double minDistance = numeric_limits<double>::max();
        Character* toAttack = enemyTeam->getMembersByTeam().front();
        for(Character* member : enemyTeam->getMembersByTeam()) {
            if(member->isAlive())
            {
                double dist = this->leader->distance(member);
                if(dist < minDistance)
                {
                    minDistance = dist;
                    toAttack = member;
                }
            }
        }
        return toAttack;
    }

    void Team::attack(Team* enemy_team)
    {
        if(!enemy_team){
            __throw_invalid_argument("Given null team pointer");
        }
        if(!enemy_team->stillAlive()){
            __throw_runtime_error("Everyone is dead, go home");
        }
        if(!this->leader->isAlive())
        {
            this->findNewLeader();
        }
        Character* currEnemy = this->findClosestEnemy(enemy_team);
        for(Character* member : this->getMembersByTeam()) {
            if(enemy_team->stillAlive() && member->isAlive())
            {
                if(!currEnemy->isAlive()){
                    currEnemy = this->findClosestEnemy(enemy_team);
                }
                if(member->getType() == "C")
                {
                    Cowboy* sherif = dynamic_cast<Cowboy*>(member);
                    if(sherif->hasboolets())
                    {
                        sherif->shoot(currEnemy);
                    } else
                    {
                        sherif->reload();
                    }
                } else
                {
                    Ninja* ninjaMan = dynamic_cast<Ninja*>(member);
                    if(ninjaMan->distance(currEnemy) < 1)
                    {
                        ninjaMan->slash(currEnemy);
                    } else
                    {
                        ninjaMan->move(currEnemy);
                    }
                }
            }
        }

    }

    int Team::stillAlive()
    {
        int counter = 0;
        for(Character* member : this->getMembersByTeam()) {
            if(member->isAlive())
            {
                counter++;
            }
        }
        return counter;
    }

    void Team::print()
    {
        for(Character* member : this->getMembersByTeam()) {
            cout << member->print() << endl;
        }
    }
}