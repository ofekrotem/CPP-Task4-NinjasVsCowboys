#include "SmartTeam.hpp"
#include <algorithm>

namespace ariel {
SmartTeam::SmartTeam(Character* leader) : Team(leader)
{}

SmartTeam::SmartTeam() : Team()
{}

bool SmartTeam::compareMembers(Character* a, Character* b) {
    // Compare by health and then by type
    if (a->getHP() == b->getHP()) {
        // If health is equal, compare by type
        // Cowboys are given a higher priority
        return a->getType() == "C";
    }
    return a->getHP() > b->getHP();
}

vector<Character*> SmartTeam::getMembersByTeam()
{
    vector<Character*> allMembers = this->getNinjas();
    allMembers.insert(allMembers.end(), this->getCowboys().begin(), this->getCowboys().end());
    std::sort(allMembers.begin(), allMembers.end(), compareMembers);
    return allMembers;
} 

}
