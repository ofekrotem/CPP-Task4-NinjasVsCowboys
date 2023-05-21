#pragma once
#include "Ninja.hpp"
#include "Point.hpp"

namespace ariel {
class YoungNinja : public Ninja
    {
    public:
        YoungNinja(string name_arg, Point location_arg);
        YoungNinja();
    };
}