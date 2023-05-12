#include "camera.h"

Camera::Camera(m3::vec4 world_up):
    m_position(m3::vec4(0, 0, 0, 1)),
    m_world_up(world_up),
    m_front(m3::vec4(0, 0, -1, 1))
{
    return;
}

m3::mat4 Camera::get_matrix()
{
    m3::vec4 direction = this->m_position + this->m_front;

    m3::vec4 right = m3::vec4::normalized(direction % this->m_world_up);
    m3::vec4 up = m3::vec4::normalized(right % direction);

    m3::mat4 m(
            right.x(),     right.y(),     right.z(), 0,
               up.x(),        up.y(),        up.z(), 0,
        direction.x(), direction.y(), direction.z(), 0,
                    0,              0,            0, 1
    );

    return m * m3::mat4::gen_translation(-this->m_position.x(), -this->m_position.y(), -this->m_position.z());
}