#include "mesh.h"

Mesh::Mesh(std::string filename)
{
    std::ifstream file;
    file.open(filename);

    if (!file.is_open())
    {
        this->loaded = false;
        return;
    }


    std::vector<m3::vec3> vertices;
    std::vector<int> indices;


    std::string line;
    std::string word;

    while (std::getline(file, line))
    {

        std::istringstream ss(line);

        ss >> word;

        if (word == "v")
        {
            float v0, v1, v2;
            ss >> v0 >> v1 >> v2;
            vertices.push_back(m3::vec3(v0, v1, v2));
        }
        else if(word == "f")
        {
            for (int i=0; i<3; i++)
            {
                std::string set;
                std::string index;

                ss >> set;
                std::getline(std::istringstream(set), index, '/');

                indices.push_back(std::atoi(index.c_str()) - 1);

            }
        }
    }

    file.close();


    for (int i=0; i<indices.size(); i+=3)
    {
        int i0 = indices.at(i);
        int i1 = indices.at(i+1);
        int i2 = indices.at(i+2);

        m3::vec3 v0 = vertices.at(i0);
        m3::vec3 v1 = vertices.at(i1);
        m3::vec3 v2 = vertices.at(i2);

        this->triangles.push_back(Triangle(v0, v1, v2));
    }


    this->loaded = true;

    return;
}


std::vector<Triangle> &Mesh::get_triangles()
{
    return this->triangles;
}