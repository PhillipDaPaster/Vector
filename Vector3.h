#pragma once
#include <DirectXMath.h>

using namespace DirectX;

class Vector3 : public XMFLOAT3 {
public:
    Vector3() : XMFLOAT3(0.0f, 0.0f, 0.0f) {}
    Vector3(float x, float y, float z) : XMFLOAT3(x, y, z) {}
    Vector3(const XMFLOAT3& other) : XMFLOAT3(other) {}
    Vector3(const XMVECTOR& vec) {
        XMStoreFloat3(this, vec);
    }

    XMVECTOR ToXMVECTOR() const {
        return XMLoadFloat3(this);
    }

    Vector3 operator + (const Vector3& other) const {
        return Vector3(XMVectorAdd(ToXMVECTOR(), other.ToXMVECTOR()));
    }

    Vector3 operator - (const Vector3& other) const {
        return Vector3(XMVectorSubtract(ToXMVECTOR(), other.ToXMVECTOR()));
    }

    Vector3 operator * (float scalar) const {
        return Vector3(XMVectorScale(ToXMVECTOR(), scalar));
    }

    Vector3 operator / (float scalar) const {
        return Vector3(XMVectorScale(ToXMVECTOR(), 1.0f / scalar));
    }

    float Dot(const Vector3& other) const {
        return XMVectorGetX(XMVector3Dot(ToXMVECTOR(), other.ToXMVECTOR()));
    }

    Vector3 Cross(const Vector3& other) const {
        return Vector3(XMVector3Cross(ToXMVECTOR(), other.ToXMVECTOR()));
    }

    float Length() const {
        return XMVectorGetX(XMVector3Length(ToXMVECTOR()));
    }

    Vector3 Normalize() const {
        return Vector3(XMVector3Normalize(ToXMVECTOR()));
    }
};
