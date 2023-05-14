#include "Team.hpp"
#include <iostream>
#include <limits>


using namespace std;

namespace ariel
{
    Team::Team(Character* leader_arg)
    {
        this->leader = leader_arg;
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
        this->cowboys.push_back(this->leader);
    }

    Character* Team::getLeader()
    {
        return this->leader;
    }

    void Team::setLeader(Character* new_leader)
    {
        this->leader = new_leader;
    }

    vector<Character*> Team::getMembers()
    {
        vector<Character*> allMembers = this->cowboys;
        allMembers.insert(allMembers.end(), this->ninjas.begin(), this->ninjas.end());
        return allMembers;
    }

    void Team::add(Character* new_member)
    {

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
        Character* newLeader = this->getMembers().back();
        for(Character* member : this->getMembers()) {
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
        Character* toAttack = enemyTeam->getMembers().back();
        for(Character* member : enemyTeam->getMembers()) {
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
        if(!this->leader->isAlive())
        {
            this->findNewLeader();
        }
        Character* currEnemy = this->findClosestEnemy(enemy_team);
        for(Character* member : this->getMembers()) {
            if(member->isAlive())
            {
                currEnemy = this->findClosestEnemy(enemy_team);
                if(member->getType() == "C")
                {
                    Cowboy* sherif = dynamic_cast<Cowboy*>(member);
                    if(sherif->hasbullets())
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
        for(Character* member : this->getMembers()) {
            if(member->isAlive())
            {
                counter++;
            }
        }
        return counter;
    }

    void Team::print()
    {
        for(Character* member : this->getMembers()) {
            cout << member->print() << endl;
        }
    }
}