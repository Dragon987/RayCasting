#include <iostream>
#include <MyLib/engine.hpp>
#include <random>
#include <time.h>
#include <vector>

#include "./../headers/Boundary.hpp"
#include "./../headers/Ray.hpp"
#include "./../headers/Particle.hpp"

#define __random__(min, max) rand() % (max - min + 1) + min
#define map(x, a, b, c, d) (x - a) * (d - c) / (b - a) + c


int main()
{
    Renderer r("Ray Tracing!!!", 800, 400);

    std::vector<Boundary> walls;

    Particle p;
    double x, y;

    srand(time(0));

    for (int i = 0; i < 5; i++)
    {
        int x1 = __random__(1, 399);
        int y1 = __random__(1, 399);
        int x2 = __random__(1, 399);
        int y2 = __random__(1, 399);
        walls.push_back(Boundary(x1, y1, x2, y2));
    }

    walls.push_back(Boundary(1, 1, 0, 400));
    walls.push_back(Boundary(0, 399, 399, 399));
    walls.push_back(Boundary(400, 400, 400, 0));
    walls.push_back(Boundary(400, 0, 1, 1));

    while (!r.WindowShouldClose())
    {
        r.Background({0, 0, 0, 0});

        for (auto wall : walls)
            wall.Show(&r);        
        p.Show(&r);

        r.GetMousePos((double *)&x, (double *)&y);
        p.Update(x, y);

        if (r.GetKey(KEY_LEFT) == GLFW_PRESS)
            p.Rotate(-0.1);
        if (r.GetKey(KEY_RIGHT) == GLFW_PRESS)
            p.Rotate(0.1);

        auto scene = p.Look(walls, &r);

        const int w = 400 / scene.size();
        for (int i = 0; i < scene.size(); i++)
        {
            float color = map(scene[i], 0.0f, 566.0f, 1.0f, 0.0f);
            float height = map(scene[i], 0, 566, 400, 0);
            r.FillRect(400 + w / 2 + i * w, 200, w, height / 2, Renderer::RECT_MODE_CENTER, {color, color, color, color});
        }

        r.SwapBuffers();

        r.PollEvents();
    }   
    return 0;
}