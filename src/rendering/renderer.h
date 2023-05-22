#pragma once


#include "model.h"
#include "camera.h"

#include <td.h>
#include <math3d.h>
#include <iostream>


class Renderer
{
    private:
        int width;
        int height;
        float aspect_ratio;

        bool initialized;

    public: // Constructor/Destructor
        Renderer(int width, int height);
        ~Renderer();
    
    private: // Utility
        float edge_cross(m3::vec3 a, m3::vec3 b, m3::vec3 p);

    public: // Utility
        void display();
        void render(Model m, Camera c, bool wireframe);

        bool is_initialized();
};