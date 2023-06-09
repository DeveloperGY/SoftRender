#include "rendering/renderer.h"

#include <td.h>

int main(void)
{
    // Predefinitions
    const int scale = 4;
    const int width = 40 * scale, height = 24 * scale;


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
    
    Model m("res/cube.obj", Color(255, 255, 255));
    m.translate(0, 0, -3);


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
        else if(input == ' ')
        {
            c.move(0, velocity, 0);
        }
        else if(input == 'v')
        {
            c.move(0, -velocity, 0);
        }
        else if(input == 'r')
        {
            c.rotate(rotation, 0, 0);
        }
        else if(input == 'f')
        {
            c.rotate(-rotation, 0, 0);
        }

        m.rotate(0.5, 0.5, 0.5);
        renderer.render(m, c, false);
        renderer.render(m, c, true);
        
        renderer.display();
    }


    return 0;
}