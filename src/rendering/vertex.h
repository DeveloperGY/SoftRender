#pragma once

#include <td.h>
#include <math3d.h>

class Vertex
{
    private:
        m3::vec3 position;

    public: // Constructors/Destructor
        Vertex();
        Vertex(m3::vec3 pos);

    public: // Utility
        m3::vec3 pos();
};