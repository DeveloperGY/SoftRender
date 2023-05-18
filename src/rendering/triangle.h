#pragma once

#include <math3d.h>

class Triangle
{
    private:
        m3::vec3 vertices[3];
        m3::vec3 normal_vec;

    public: // Constructors/Destructor
        Triangle(m3::vec3 v0, m3::vec3 v1, m3::vec3 v2, m3::vec3 normal);

    public: // Utility
        m3::vec3 v0();
        m3::vec3 v1();
        m3::vec3 v2();
        m3::vec3 normal();
};