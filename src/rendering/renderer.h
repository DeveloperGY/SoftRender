#pragma once

#include <termDisplay.h>
#include "model.h"
#include "camera.h"

class Renderer
{
    private:
        bool m_initialized;

        int m_width;
        int m_height;

    public: // Constructors/Destructors
        Renderer(int width, int height);
        ~Renderer();

    public: // Rendering
        void display();
        void draw(Model m, Camera c);

    private: // Private Utility
        m3::mat4 get_matrix();

    public: // Public Utility
        bool is_initialized();
};