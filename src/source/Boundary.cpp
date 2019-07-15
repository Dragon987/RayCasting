
#include "./../headers/Boundary.hpp"


Boundary::Boundary(float x1, float y1, float x2, float y2)
    :x1(x1), y1(y1), x2(x2), y2(y2)
{

}

void Boundary::Show(Renderer *r)
{
    r->Line(x1, y1, x2, y2, {1, 1, 1, 1});
}
