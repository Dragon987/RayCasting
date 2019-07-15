#include <math.h>
#include <math_constants.h>
#include <iostream>

#include "./../headers/Ray.hpp"

Ray::Ray(float x, float y)
{
    posX = x;
    posY = y;
    dirX = 1;
    dirY = 0;
}

Ray::Ray(float x, float y, float angle)
{
    posX = x;
    posY = y;

    angle = ((float)M_PI * angle) / 180.0f;
    
    dirX = cosf(angle);
    dirY = sinf(angle);
}

Ray::Ray() {}

void Ray::Show(Renderer *r)
{
    //r->Translate(-posX, r->width - posX, -posY, r->height - posY, 0, 100);

    r->Line(posX, posY, posX + dirX * 10, posY + dirY * 10, {1, 1, 1, 1});

    //r->Translate();
}

void ShowPoint(const Point &p, Renderer *r)
{
    r->FillCircle(p.x, p.y, 4, {1, 1, 1, 1});
}

Point Ray::Cast(const Boundary &wall)
{
    const float x1 = wall.x1;
    const float y1 = wall.y1;
    const float x2 = wall.x2;
    const float y2 = wall.y2;

    const float x3 = posX;
    const float y3 = posY;
    const float x4 = posX + dirX;
    const float y4 = posY + dirY;

    const float den = (x1 - x2) * 
                            (y3 - y4) - 
                            (y1 - y2) * 
                            (x3 - x4);
    
    if (den == 0)
        return {-1, -1};

    float t = (x1 - x3) * (y3 - y4)
            - (y1 - y3) * (x3 - x4);
    t /= den;

    float u = (x1 - x2) * (y1 - y3)
            - (y1 - y2) * (x1 - x3);
    u /= - den;

    if (t > 0 && t < 1 && u > 0)
        return {x3 + u * (x4 - x3), 
                y3 + u * (y4 - y3)};
    return {-1, -1};
}

void Ray::LookAt(float x, float y)
{
    dirX = x - posX;
    dirY = y - posY;
    float mag = sqrtf(dirX * dirX + dirY * dirY);

    dirX /= mag;
    dirY /= mag;
}