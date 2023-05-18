#include "camera.h"

Camera::Camera(m3::vec3 world_up, float fov):
    pos(0, 0, 0),
    front(0, 0, -1),
    world_up(world_up),
    fov(fov),
    rot(0, 1, 0, 0)
{
    return;
}


m3::mat4 Camera::get_matrix()
{
    m3::mat4 translation = m3::mat4::translation_matrix(-this->pos.x(), -this->pos.y(), -this->pos.z());

    m3::vec3 front = this->rot * this->front * m3::quat::inverse(this->rot);

    m3::vec3 target = this->pos + front;
    m3::vec3 direction = this->rot * m3::vec3::normalize(this->pos - target) * m3::quat::inverse(this->rot);

    m3::vec3 right = m3::vec3::normalize(this->world_up % direction);
    m3::vec3 up = this->rot * m3::vec3::normalize(direction % right) * m3::quat::inverse(this->rot);

    // change of basis
    m3::mat4 cob = m3::mat4::change_of_basis_matrix(right, up, direction);

    return cob * translation;
}


float Camera::get_fov()
{
    return this->fov;
}


void Camera::move(float x, float y, float z)
{
    m3::vec3 front = this->rot * this->front * m3::quat::inverse(this->rot);
    m3::vec3 target = this->pos + front;
    m3::vec3 direction = m3::vec3::normalize(this->pos - target);

    m3::vec3 right = m3::vec3::normalize(this->world_up % direction);
    m3::vec3 up = m3::vec3::normalize(direction % right);

    this->pos += right * x;
    this->pos += direction * z;
    this->pos += up * y;

    return;
}

void Camera::rotate(float x, float y, float z)
{
    m3::quat q_x(x, m3::vec3(1, 0, 0));
    m3::quat q_y(y, m3::vec3(0, 1, 0));
    m3::quat q_z(z, m3::vec3(0, 0, 1));

    this->rot = q_x * q_y * q_z * this->rot;

    return;
}


m3::vec3 Camera::forward()
{
    m3::vec3 front = this->rot * this->front * m3::quat::inverse(this->rot);
    m3::vec3 target = this->pos + front;
    m3::vec3 direction = m3::vec3::normalize(this->pos - target);

    return direction;
}