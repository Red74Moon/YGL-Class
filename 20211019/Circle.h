#pragma once
#include "Shape.h"

class Circle :  public Shape
{
public:
    Circle();
    Circle(int NewX, int NewY, int Radius);
    virtual ~Circle();

    inline int  GetRadius() { return Radius; }
    inline void SetRadius(int NewRadius) { Radius = NewRadius; }

    virtual void Draw() override;

private:
    int Radius;
};

