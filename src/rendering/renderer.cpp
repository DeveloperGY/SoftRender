#include "renderer.h"

Renderer::Renderer()
{
    td_initialize(0, 0);
    return;
}

Renderer::~Renderer()
{
    td_terminate(1);
    return;
}