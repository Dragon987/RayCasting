#include <iostream>
#include <MyLib/engine.hpp>
#include <random>
#include <time.h>
#include <vector>

#include "./../headers/Boundary.hpp"
#include "./../headers/Ray.hpp"
#include "./../headers/Particle.hpp"

#define __random__(min, max) rand() % (max - min + 1) + min


int main()
{
    Renderer r("Ray Tracing!!!", 400, 400);

    std::vector<Boundary> walls;

    Particle p;
    double x, y;

    srand(time(0));

    for (int i = 0; i < 5; i++)
    {
        int x1 = __random__(0, 400);
        int y1 = __random__(0, 400);
        int x2 = __random__(0, 400);
        int y2 = __random__(0, 400);
        walls.push_back(Boundary(x1, y1, x2, y2));
    }

    while (!r.WindowShouldClose())
    {
        r.Background({0, 0, 0, 0});

        for (auto wall : walls)
            wall.Show(&r);        
        p.Show(&r);

        r.GetMousePos((double *)&x, (double *)&y);
        p.Update(x, y);

        p.Look(walls, &r);

        r.SwapBuffers();

        r.PollEvents();
    }   
    return 0;
}