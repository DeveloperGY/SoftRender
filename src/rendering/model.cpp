#include "model.h"

Model::Model(std::string filename, int color):
    mesh(filename),
    color(color)
{
    return;
}


m3::mat4 Model::get_matrix()
{
    m3::mat4 translation = m3::mat4::translation_matrix(this->pos.x(), this->pos.y(), this->pos.z());
    return translation;
}