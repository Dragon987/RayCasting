#pragma once

#include <vector>
#include <math.h>
#include <MyLib/engine.hpp>

#include "./Ray.hpp"

#define dist(x1, y1, x2, y2) sqrtf((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2))

class Particle
{
private:
    float angleLow, angleHigh;

private:

public:
    float x, y, fov;
    int n_rays;
    Ray *rays;

public:
    Particle();
    void Show(Renderer *r);
    void Update(float x, float y);
    void Look(Boundary &wall, Renderer *r);
    std::vector<float> Look(std::vector<Boundary> &walls, Renderer *r);
    void Rotate(float amount);
    inline ~Particle() { delete[] rays; };
};