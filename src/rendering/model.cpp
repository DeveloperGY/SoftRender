#include "model.h"

Model::Model(std::string filename, int color):
    mesh(filename),
    color(color),
    pos(0, 0, 0),
    rot(0, 1, 0, 0),
    scl(1, 1, 1)
{
    return;
}


m3::mat4 Model::get_matrix()
{
    m3::mat4 translation = m3::mat4::translation_matrix(this->pos.x(), this->pos.y(), this->pos.z());
    m3::mat4 scale = m3::mat4::scale_matrix(this->scl.x(), this->scl.y(), this->scl.z());
    return translation * this->rot * scale;
}


Mesh &Model::get_mesh()
{
    return this->mesh;
}

int &Model::get_color()
{
    return this->color;
}


void Model::translate(float x, float y, float z)
{
    this->pos += m3::vec3(x, y ,z);
    return;
}

void Model::rotate(float x, float y, float z)
{
    m3::quat q_x(x, m3::vec3(1, 0, 0));
    m3::quat q_y(y, m3::vec3(0, 1, 0));
    m3::quat q_z(z, m3::vec3(0, 0, 1));

    this->rot = this->rot * q_x * q_y * q_z;
    
    return;
}