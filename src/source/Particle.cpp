#include "./../headers/Particle.hpp"
#include <iostream>

Particle::Particle()
    : x(200), y(200), fov(360)
{
    n_rays = (int)(fov / 10);
    rays = new Ray[n_rays];
    int c = 0;

    for (float i = 0; i < fov; i += 10.0)
        rays[c++] = Ray(x, y, i);
}

void Particle::Look(Boundary &wall, Renderer *r)
{
    for (int i = 0; i < n_rays; i++)
    {
        Point pt = rays[i].Cast(wall);
        if (PointExist(pt))
            r->Line(x, y, pt.x, pt.y, {1, 1, 1, 1});
    }
}


void Particle::Show(Renderer * r)
{
    r->DrawCircle(x, y, 4, {1, 1, 1, 1});

    for (int i = 0; i < n_rays; i++)
        rays[i].Show(r);
}

void Particle::Update(float x_, float y_)
{
    this->x = x_;
    this->y = y_;

    for (int i = 0; i < n_rays; i++)
    {
        rays[i].posX = x_;
        rays[i].posY = y_;
    }

}

void Particle::Look(std::vector<Boundary> &walls, Renderer *r)
{
    for (int i = 0; i < n_rays; i++)
    {
        float record = INFINITY;
        Point winner = {-1, -1};

        for (int j = 0; j < 5; j++)
        {
            Point pt = rays[i].Cast(walls[j]);
            float d;
            if (PointExist(pt))
            {
                d = dist(x, y, pt.x, pt.y);
                if (d < record)
                {
                    record = d;
                    winner = pt;
                }
            }
        }
        
        if (PointExist(winner))
            r->Line(x, y, winner.x, winner.y, {1, 1, 1, 1});
    
    }
}