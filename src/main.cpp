#include "rendering/renderer.h"

int main(void)
{
    // Pre-definitions
    const int width = 80, height = 48;
    const float vfov = 60.0f;


    // Setup Renderer
    Renderer renderer(width, height);

    if (!renderer.is_initialized())
    {
        return -1;
    }


    // Prep for loop
    Camera c(m3::vec4(0, 1, 0, 0));

    Model m;


    // Main Loop

    while (getch(0) != 'q')
    {
        renderer.draw(m, c);
        renderer.display();
    }

    return 0;
}