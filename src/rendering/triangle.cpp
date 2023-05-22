#include "triangle.h"

Triangle::Triangle(Vertex v0, Vertex v1, Vertex v2)
{
    this->vertices[0] = v0;
    this->vertices[1] = v1;
    this->vertices[2] = v2;

    return;
}

Vertex Triangle::v0()
{
    return this->vertices[0];
}

Vertex Triangle::v1()
{
    return this->vertices[1];
}

Vertex Triangle::v2()
{
    return this->vertices[2];
}