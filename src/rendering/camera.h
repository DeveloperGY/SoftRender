#pragma once

#include <math3d.h>

class Camera
{
    private:
        m3::vec3 pos;
        m3::vec3 front;
        m3::vec3 world_up;

        float fov;

        m3::vec3 rot;

    public: // Constructors/Destructor
        Camera(m3::vec3 world_up, float fov);

    private: // Utility
        m3::quat rotation();

    public: // Utility
        m3::mat4 get_matrix();
        float get_fov();

        void move(float x, float y, float z);
        void rotate(float x, float y, float z);
        m3::vec3 direction();
};