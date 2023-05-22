#include "color.h"

Color::Color(unsigned char r, unsigned char g, unsigned char b)
{
    this->data = (td_color){r, g, b};

    return;
}

td_color Color::get_data()
{
    return this->data;
}