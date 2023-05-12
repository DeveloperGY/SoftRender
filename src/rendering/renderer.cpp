#include "renderer.h"

Renderer::Renderer(int width, int height):
    m_initialized(false),
    m_width(0),
    m_height(0)
{
    if (!td_initialize(width, height))
    {
        return;
    }

    this->m_initialized = true;
    this->m_width = width;
    this->m_height = height;

    return;
}

Renderer::~Renderer()
{
    if (this->is_initialized())
    {
        td_terminate(1);
    }
    return;
}


/**
 * Utility
 */

bool Renderer::is_initialized()
{
    return this->m_initialized;
}

m3::mat4 Renderer::get_matrix()
{
    m3::mat4 m;

    // TODO: finish projection matrix

    return m;
}


/**
 * Rendering
 */

void Renderer::display()
{
    td_display();

    return;
}

void Renderer::draw(Model m, Camera c)
{   
    m3::mat4 model_matrix = m.get_matrix();
    m3::mat4 view_matrix = c.get_matrix();
    m3::mat4 projection_matrix = this->get_matrix();

    for (Triangle &t: m.get_triangles())
    {
        m3::vec4 v0 = projection_matrix * view_matrix * model_matrix * t.v0();
        m3::vec4 v1 = projection_matrix * view_matrix * model_matrix * t.v1();
        m3::vec4 v2 = projection_matrix * view_matrix * model_matrix * t.v2();
    }

    return;
}