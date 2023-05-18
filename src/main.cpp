#include "rendering/renderer.h"

#include <termDisplay.h>

int main(void)
{
    // Predefinitions
    const int scale = 4;
    const int width = 40 * scale * 2, height = 24 * scale;

    const float velocity = 0.05;
    const float rotation = 5;


    // Create Renderer

    Renderer renderer(width, height);

    if (!renderer.is_initialized())
    {
        return -1;
    }


    // Generate Models and Cameras

    Camera c(m3::vec3(0, 1, 0), 60.0f);

    Model m0("res/cube.obj", TD_COLOR_CYAN);
    Model m1("res/cube.obj", TD_COLOR_YELLOW);

    m0.translate(0, 0, -3);
    m1.translate(3, 0, -3);

    


    // Render Loop

    char input;

    while ((input = getch(0)) != 'p')
    {
        // Handle input

        if (input == 'w')
        {
            c.move(0, 0, -velocity);
        }
        else if(input == 's')
        {
            c.move(0, 0, velocity);
        }
        else if(input == 'a')
        {
            c.move(-velocity, 0, 0);
        }
        else if(input == 'd')
        {
            c.move(velocity, 0, 0);
        }
        else if(input == 'q')
        {
            c.rotate(0, rotation, 0);
        }
        else if(input == 'e')
        {
            c.rotate(0, -rotation, 0);
        }


        // m1.rotate(0, 0, 0.4);
        // m1.rotate(0, 0.4, 0);

        renderer.render(m0, c, true);
        renderer.render(m1, c, true);

        renderer.display();
    }


    return 0;
}