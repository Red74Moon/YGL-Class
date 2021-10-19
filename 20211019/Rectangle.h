#pragma once
#include "Shape.h"
class Rectangle :public Shape
{
public:
    Rectangle();

    virtual ~Rectangle();

    virtual void Draw() override;
};

