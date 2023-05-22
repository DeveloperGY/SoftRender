#pragma once

#include "mesh.h"
#include "color.h"

#include <string>
#include <math3d.h>
#include <td.h>


class Model
{
    private:
        Mesh mesh;
        Color color;
        
        m3::vec3 pos;
        m3::quat rot;
        m3::vec3 scl;


    public: // Constructors/Destructor
        Model(std::string filename, Color color);
    
    public: // Utility
        m3::mat4 get_matrix();

        Mesh get_mesh();
        Color get_color();

        void translate(float x, float y, float z);
        void rotate(float x, float y, float z);
};