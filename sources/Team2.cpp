#include "Team2.hpp"

namespace ariel{
Team2::Team2(Character* leader) : Team(leader)
{}

Team2::Team2() : Team()
{}

vector<Character*> Team2::getMembersByTeam()
{
    return this->getMembers();
} 

}