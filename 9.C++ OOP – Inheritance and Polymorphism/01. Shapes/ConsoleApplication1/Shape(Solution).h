#pragma once

#include"Vector2D.h"


class Shape {
protected:
    double area;
    Vector2D center;

    Shape() : area(0), center(0, 0) {}
    Shape(Vector2D center) : center(center) {}

public:

    Vector2D getCenter() {
        return this->center;
    }
    double getArea() {
        return this->area;
    }

};
