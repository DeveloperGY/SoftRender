#include "vertex.h"

Vertex::Vertex()
{
    this->position = m3::vec3(0, 0, 0);

    return;
}

Vertex::Vertex(m3::vec3 pos)
{
    this->position = pos;

    return;
}


m3::vec3 Vertex::pos()
{
    return this->position;
}