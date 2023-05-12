#pragma once

#include <math3d.h>

class Triangle
{
    private:
        m3::vec4 m_vertices[3];

    public: // Constructors/Destructor
        Triangle(m3::vec4 v0, m3::vec4 v1, m3::vec4 v2);

    public: // Utility
        m3::vec4 v0();
        m3::vec4 v1();
        m3::vec4 v2();
};