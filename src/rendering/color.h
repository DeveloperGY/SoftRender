#pragma once

#include <td.h>

class Color
{
    private:
        td_color data;

    public: // Constructors/Destructor
        Color(unsigned char r, unsigned char g, unsigned char b);
    
    public:
        td_color get_data();
};