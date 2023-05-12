#include "triangle.h"

Triangle::Triangle(m3::vec4 v0, m3::vec4 v1, m3::vec4 v2)
{
    this->m_vertices[0] = v0;
    this->m_vertices[1] = v1;
    this->m_vertices[2] = v2;
    return;
}

m3::vec4 Triangle::v0()
{
    return this->m_vertices[0];
}

m3::vec4 Triangle::v1()
{
    return this->m_vertices[1];
}

m3::vec4 Triangle::v2()
{
    return this->m_vertices[2];
}