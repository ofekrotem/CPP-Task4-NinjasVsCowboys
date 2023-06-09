#pragma once
#include <iostream>
using namespace std;
namespace ariel 
{
    class Point
    {
    private:
        double x;
        double y;
    public:
        Point(double x_arg, double y_arg);
        Point();
        double getX();
        double getY();
        double distance(Point other);
        string print();
        static Point moveTowards(const Point& source, const Point& destination, double distance);
    };

}
