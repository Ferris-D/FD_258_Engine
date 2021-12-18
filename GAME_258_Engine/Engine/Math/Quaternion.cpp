#include "Quaternion.h"

Quaternion::Quaternion(float w_, float x_, float y_, float z_)
{
    v.x = x_;
    v.y = y_;
    v.z = z_;
    v.w = w_;
}

Quaternion::Quaternion(float w_, glm::vec3 v_)
{
    w_ = w_ / 360.0f * (float)(atan(1.0f) * 4.0f);
    v.x = v_.x * sin(w_ / 2.0f);
    v.y = v_.y * sin(w_ / 2.0f);
    v.z = v_.z * sin(w_ / 2.0f);
    v.w = cos(w_ / 2.0f);
}

Quaternion::Quaternion(glm::vec4 v_)
{
    v_.w = v_.w / 360.0f * (float)(atan(1.0f) * 4.0f);
    v.x = v_.x * sin(v_.w / 2.0f);
    v.y = v_.y * sin(v_.w / 2.0f);
    v.z = v_.z * sin(v_.w / 2.0f);
    v.w = cos(v_.w / 2.0f);
}

Quaternion Quaternion::Normalize(Quaternion q_)
{
    double n = glm::sqrt(q_.v.x * q_.v.x + q_.v.y * q_.v.y + q_.v.z * q_.v.z + q_.v.w * q_.v.w);
    q_.v.x /= n;
    q_.v.y /= n;
    q_.v.z /= n;
    q_.v.w /= n;
    return q_;
}

void Quaternion::Normalize()
{
    double n = glm::sqrt(v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w);
    v.x /= n;
    v.y /= n;
    v.z /= n;
    v.w /= n;
}

Quaternion Quaternion::ApplyVelocity(Quaternion q_, glm::vec3 av_, float deltaTime_)
{
    Quaternion qq;
    qq = q_ + (Quaternion(0.0f,av_.x,av_.y,av_.z) * q_ * (deltaTime_/2));
    qq.Normalize();
    return qq;
}

// Quaternion add operator
Quaternion Quaternion::operator+(Quaternion otherQuat_)
{
    return Quaternion(v.w + otherQuat_.v.w, v.x + otherQuat_.v.x, v.y + otherQuat_.v.y, v.z + otherQuat_.v.z);
}

// Quaternion multiply operator
Quaternion Quaternion::operator*(Quaternion otherQuat_)
{
    Quaternion qm;

    qm.v.x = v.x * otherQuat_.v.w + v.y * otherQuat_.v.z - v.z * otherQuat_.v.y + v.w * otherQuat_.v.x;
    qm.v.y = -v.x * otherQuat_.v.z + v.y * otherQuat_.v.w + v.z * otherQuat_.v.x + v.w * otherQuat_.v.y;
    qm.v.z = v.x * otherQuat_.v.y - v.y * otherQuat_.v.x + v.z * otherQuat_.v.w + v.w * otherQuat_.v.z;
    qm.v.w = -v.x * otherQuat_.v.x - v.y * otherQuat_.v.y - v.z * otherQuat_.v.z + v.w * otherQuat_.v.w;

    return qm;
}

Quaternion Quaternion::operator*(float f_)
{
    return Quaternion(v.w * f_, v.x * f_, v.y * f_, v.z * f_);
}

Quaternion Quaternion::operator/(float s_)
{
    return Quaternion(v.x / s_, v.y / s_, v.z / s_, v.w / s_);
}

