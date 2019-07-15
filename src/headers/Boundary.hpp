#pragma once

#include <MyLib/engine.hpp>

class Boundary 
{
private:

private:

public:
    float x1, y1, x2, y2;

public:
    Boundary(float x1, float y1, float x2, float y2);
    inline Boundary() {};
    void Show(Renderer *r);
};