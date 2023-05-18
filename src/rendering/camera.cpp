#include "camera.h"

Camera::Camera(m3::vec3 world_up, float fov):
    pos(0, 0, 0),
    front(0, 0, -1),
    world_up(world_up),
    fov(fov),
    rot(0, 0, 0)
{
    return;
}


m3::mat4 Camera::get_matrix()
{
    m3::quat rot = this->rotation();

    m3::vec3 target = this->pos + this->front;
    m3::vec3 direction = rot * m3::vec3::normalize(this->pos - target) * m3::quat::inverse(rot);
    m3::vec3 right = m3::vec3::normalize(this->world_up % direction);
    m3::vec3 up = m3::vec3::normalize(direction % right);

    m3::mat4 cob = m3::mat4::change_of_basis_matrix(right, up, direction);
    m3::mat4 translation = m3::mat4::translation_matrix(-this->pos.x(), -this->pos.y(), -this->pos.z());

    return cob * translation;
}


float Camera::get_fov()
{
    return this->fov;
}


void Camera::move(float x, float y, float z)
{
    m3::quat rot = this->rotation();

    m3::vec3 target = this->pos + this->front;
    m3::vec3 direction = rot * m3::vec3::normalize(this->pos - target) * m3::quat::inverse(rot);
    m3::vec3 right = m3::vec3::normalize(this->world_up % direction);
    m3::vec3 up = m3::vec3::normalize(direction % right);

    this->pos += (right * x) + (up * y) + (direction * z);

    return;
}

void Camera::rotate(float x, float y, float z)
{m3::quat qx = m3::quat(this->rot.x(), m3::vec3(1, 0, 0));
    this->rot += m3::vec3(x, y, z);
    return;
}

m3::quat Camera::rotation()
{
    m3::quat qx = m3::quat(this->rot.x(), m3::vec3(1, 0, 0));
    m3::quat qy = m3::quat(this->rot.y(), m3::vec3(0, 1, 0));
    m3::quat qz = m3::quat(this->rot.z(), m3::vec3(0, 0, 1));

    return qx * qy * qz;
}

m3::vec3 Camera::direction()
{
    m3::quat rot = this->rotation();

    m3::vec3 target = this->pos + this->front;
    return rot * m3::vec3::normalize(this->pos - target) * m3::quat::inverse(rot);
}