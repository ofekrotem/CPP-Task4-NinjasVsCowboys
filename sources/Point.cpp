#include "Point.hpp"
#include <iostream>
#include <cmath>

using namespace std;
namespace ariel 
{
    Point::Point(double x_arg, double y_arg) : x(x_arg) , y(y_arg){}

    Point::Point()
    {
        this->x = 0;
        this->y = 0;
    }

    double Point::getX()
    {
        return this->x;
    }

    double Point::getY()
    {
        return this->y;
    }

    string Point::print()
    {
        return "(" + to_string(this->x) + "," + to_string(this->y) + ")";
    }

    double Point::distance(Point other)
    {
        double dx = this->x - other.getX();
        double dy = this->y - other.getY();
        return std::sqrt(dx * dx + dy * dy); 
    }

    Point Point::moveTowards(const Point& source, const Point& destination, double distance)
    {
        if (distance < 0) {
            throw invalid_argument("Distance cannot be negative");
        }

        double dx = destination.x - source.x;
        double dy = destination.y - source.y;
        double original_distance = sqrt(dx * dx + dy * dy); 

        if (original_distance == 0 || distance == 0) {
            return source;
        }

        if (distance >= original_distance) {
            return destination;
        }

        double ux = dx / original_distance;
        double uy = dy / original_distance;

        double move_x = ux * distance;
        double move_y = uy * distance;

        Point result(source.x + move_x, source.y + move_y);

        return result;
    }




}