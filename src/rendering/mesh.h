#pragma once
#include "triangle.h"


#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <math3d.h>

#include <iostream>

class Mesh
{
    private:
        std::vector<Triangle> triangles;
        bool loaded;

    public: // Constructors/Destructor
        Mesh(std::string filename);

    public: // Utility
        std::vector<Triangle> &get_triangles();
};