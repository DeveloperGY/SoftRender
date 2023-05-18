#include "renderer.h"

Renderer::Renderer(int width, int height)
{
    if (!td_initialize(width, height))
    {
        this->initialized = false;
        return;
    }

    this->initialized = true;
    this->width = width;
    this->height = height;
    this->aspect_ratio = (float)this->width / (float)this->height;

    return;
}

Renderer::~Renderer()
{
    td_terminate(1);
    return;
}


void Renderer::display()
{
    td_display();
    return;
}

void Renderer::render(Model m, Camera c, bool wireframe)
{
    float near = 0.01;
    float far = 100;

    m3::mat4 model_matrix = m.get_matrix();
    m3::mat4 view_matrix = c.get_matrix();
    m3::mat4 projection_matrix = m3::mat4::projection_matrix(c.get_fov(), this->aspect_ratio * (3.0/5.0), near, far);
    m3::mat4 mvp_matrix = projection_matrix * view_matrix * model_matrix;

    m3::vec4 vertices[3];

    for (auto &t: m.get_mesh().get_triangles())
    {
        // transform the normal

        vertices[0] = mvp_matrix * m3::vec3::as_vec4(t.v0(), 1);
        vertices[1] = mvp_matrix * m3::vec3::as_vec4(t.v1(), 1);
        vertices[2] = mvp_matrix * m3::vec3::as_vec4(t.v2(), 1);


        for (int i=0; i<3; i++) // perspective division perspective division
        {
            if (vertices[i].w() != 0)
            {
                float x = vertices[i].x() / vertices[i].w();
                float y = vertices[i].y() / vertices[i].w();
                float z = vertices[i].z() / vertices[i].w();
                float w = vertices[i].w();

                vertices[i] = m3::vec4(x, y, z, w);
            }
            else
            {
                float x = vertices[i].x() / 0.01;
                float y = vertices[i].y() / 0.01;
                float z = vertices[i].z() / 0.01;
                float w = vertices[i].w();

                vertices[i] = m3::vec4(x, y, z, w);
            }
        }


        // face normal calculation

        m3::vec3 v_0 = m3::vec4::as_vec3(vertices[0]);
        m3::vec3 v_1 = m3::vec4::as_vec3(vertices[1]);
        m3::vec3 v_2 = m3::vec4::as_vec3(vertices[2]);

        m3::vec3 normal = m3::vec3::normalize((v_1 - v_0) % (v_2-v_1));

        if (m3::vec3(0, 0, 1) * normal < 0 && !wireframe)
        {
            continue;
        }


        // Translate to screen coordinates

        int hw = this->width / 2;
        int hh = this->height / 2;

        for (int i=0; i<3; i++)
        {
            vertices[i] = m3::vec4(hw + (vertices[i].x() * hw), hh - (vertices[i].y() * hh), vertices[i].z(), vertices[i].w());
        }

        
        // check for bounds

        m3::vec4 v0 = vertices[0];
        m3::vec4 v1 = vertices[1];
        m3::vec4 v2 = vertices[2];

        bool v0_in = (v0.z() <= 1) && (v0.z() >= -1);
        bool v1_in = (v1.z() <= 1) && (v1.z() >= -1);
        bool v2_in = (v2.z() <= 1) && (v2.z() >= -1);        


        // line drawing and rasterization

        if (wireframe)
        {
            if (v0_in && v1_in)
            {
                td_drawFillRect(0, 0, 2, 2, ' ', TD_COLOR_DEFAULT, TD_COLOR_RED);
                td_drawLine(v0.x(), v0.y(), v1.x(), v1.y(), ' ', m.get_color(), m.get_color());
            }

            if (v1_in && v2_in)
            {
                td_drawFillRect(2, 0, 2, 2, ' ', TD_COLOR_DEFAULT, TD_COLOR_GREEN);
                td_drawLine(v1.x(), v1.y(), v2.x(), v2.y(), ' ', m.get_color(), m.get_color());
            }

            if (v2_in && v0_in)
            {
                td_drawFillRect(4, 0, 2, 2, ' ', TD_COLOR_DEFAULT, TD_COLOR_BLUE);
                td_drawLine(v2.x(), v2.y(), v0.x(), v0.y(), ' ', m.get_color(), m.get_color());
            }
        }
        else
        {
            if (v0_in && v1_in && v2_in)
            {
                int x_min = std::min(v0.x(), std::min(v1.x(), v2.x()));
                int x_max = std::max(v0.x(), std::max(v1.x(), v2.x()));
                int y_min = std::min(v0.y(), std::min(v1.y(), v2.y()));
                int y_max = std::max(v0.y(), std::max(v1.y(), v2.y()));

                x_min = std::max(0, x_min);
                x_max = std::min(x_max, this->width - 1);
                y_min = std::max(0, y_min);
                y_max = std::min(y_max, this->height - 1);

                for (int y=y_min; y<=y_max; y++)
                {
                    for(int x=x_min; x<=x_max; x++)
                    {
                        m3::vec3 v(x, y, 0);
                        
                        float e0 = this->edge_cross(m3::vec4::as_vec3(v0), m3::vec4::as_vec3(v1), v);
                        float e1 = this->edge_cross(m3::vec4::as_vec3(v1), m3::vec4::as_vec3(v2), v);
                        float e2 = this->edge_cross(m3::vec4::as_vec3(v2), m3::vec4::as_vec3(v0), v);

                        if (e0 <= 0 && e1 <= 0 && e2 <= 0)
                        {
                            td_drawPoint(x, y, ' ', m.get_color(), m.get_color());
                        }
                    }
                }
            }
        }


        // // draw vertices

        // if (v0_in)
        // {
        //     td_drawPoint(v0.x(), v0.y(), ' ', m.get_color(), TD_COLOR_MAGENTA);
        // }
        // if (v1_in)
        // {
        //     td_drawPoint(v1.x(), v1.y(), ' ', m.get_color(), TD_COLOR_MAGENTA);
        // }
        // if (v2_in)
        // {
        //     td_drawPoint(v2.x(), v2.y(), ' ', m.get_color(), TD_COLOR_MAGENTA);
        // }
    }

    return;
}


bool Renderer::is_initialized()
{
    return this->initialized;
}

float Renderer::edge_cross(m3::vec3 a, m3::vec3 b, m3::vec3 p)
{
    m3::vec3 ab = b-a;
    m3::vec3 ap = p-a;

    return ab.x() * ap.y() - ab.y() * ap.x();
}