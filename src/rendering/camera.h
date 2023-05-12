#pragma once

#include <math3d.h>

class Camera
{
    private:
        m3::vec4 m_position;
        m3::vec4 m_world_up;
        m3::vec4 m_front;

    public: // Constructors/Destructor
        Camera(m3::vec4 world_up);

    public: // Utilities
        m3::mat4 get_matrix();
};