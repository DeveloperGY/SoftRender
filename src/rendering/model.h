#pragma once


#include "mesh.h"

#include <string>
#include <math3d.h>


class Model
{
    private:
        Mesh mesh;
        int color;
        m3::vec3 pos;


    public: // Constructors/Destructor
        Model(std::string filename, int color);
    
    public: // Utility
        m3::mat4 get_matrix();
};