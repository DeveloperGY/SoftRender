#include "triangle.h"

Triangle::Triangle(m3::vec3 v0, m3::vec3 v1, m3::vec3 v2, m3::vec3 normal)
{
    this->vertices[0] = v0;
    this->vertices[1] = v1;
    this->vertices[2] = v2;

    this->normal_vec = normal;

    return;
}

m3::vec3 Triangle::v0()
{
    return this->vertices[0];
}

m3::vec3 Triangle::v1()
{
    return this->vertices[1];
}

m3::vec3 Triangle::v2()
{
    return this->vertices[2];
}

m3::vec3 Triangle::normal()
{
    return this->normal_vec;
}