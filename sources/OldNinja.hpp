#pragma once
#include "Ninja.hpp"

namespace ariel {
class OldNinja : public Ninja
    {
    public:
        OldNinja(string name_arg, Point location_arg);
        OldNinja();
    };
}