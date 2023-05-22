#pragma once

#include "vertex.h"

#include <math3d.h>
#include <td.h>

class Triangle
{
    private:
        Vertex vertices[3];

    public: // Constructors/Destructor
        Triangle(Vertex v0, Vertex v1, Vertex v2);

    public: // Utility
        Vertex v0();
        Vertex v1();
        Vertex v2();
};