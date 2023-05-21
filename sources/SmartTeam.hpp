#pragma once
#include "Team.hpp"

namespace ariel {
class SmartTeam : public Team
{
public:
    SmartTeam(Character* leader);
    SmartTeam();
    vector<Character*> getMembersByTeam() override;
    static bool compareMembers(Character* a, Character* b);
};
}
