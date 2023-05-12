#include "model.h"

Model::Model()
{
    return;
}

std::vector<Triangle> Model::get_triangles()
{
    return this->m_triangles;
}

m3::vec4 Model::get_position()
{
    return this->m_position;
}

m3::mat4 Model::get_matrix()
{
    m3::mat4 translation = m3::mat4::gen_translation(this->m_position.x(), this->m_position.y(), this->m_position.z());

    return translation;
}