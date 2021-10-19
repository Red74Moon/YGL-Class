#pragma once
#include "Shape.h"
class Circle :  public Shape
{
public:
    Circle();
    virtual ~Circle();

    virtual void Draw() override;
};

