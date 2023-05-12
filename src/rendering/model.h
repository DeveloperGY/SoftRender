#pragma once

#include "triangle.h"
#include <vector>

class Model
{
    private:
        std::vector<Triangle> m_triangles;
        m3::vec4 m_position;

    public: // Constructors/Destructor
        Model();

    public: // Getters/Setters
        std::vector<Triangle> get_triangles();
        m3::vec4 get_position();

        m3::mat4 get_matrix();
};