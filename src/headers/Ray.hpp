#pragma once

#include <MyLib/engine.hpp>

#include "./Boundary.hpp"

#define PointExist(pt) (pt.x != -1 && pt.y != -1) ? true : false


struct Point
{
    float x, y;
};

void ShowPoint(const Point &p, Renderer *r);

class Ray
{
private:

private:

public:
    float posX, posY, dirX, dirY;

public:
    Ray(float x, float y);
    Ray(float x, float y, float angle);
    Ray();
    void Show(Renderer *r);
    void LookAt(float x, float y);
    Point Cast(const Boundary &wall);

};