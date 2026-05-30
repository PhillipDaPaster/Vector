#pragma once
#include <DirectXMath.h>

using namespace DirectX;

class Vector4 : public XMFLOAT4 {
public:
    Vector4() : XMFLOAT4(0.0f, 0.0f, 0.0f, 0.0f) {}
    Vector4(float x, float y, float z, float w) : XMFLOAT4(x, y, z, w) {}
    Vector4(const XMFLOAT4& other) : XMFLOAT4(other) {}
    Vector4(const XMVECTOR& vec) {
        XMStoreFloat4(this, vec);
    }

    XMVECTOR ToXMVECTOR() const {
        XMLoadFloat4(this);
        return XMLoadFloat4(this);
    }

    Vector4 operator + (const Vector4& other) const {
        return Vector4(XMVectorAdd(ToXMVECTOR(), other.ToXMVECTOR()));
    }

    Vector4 operator - (const Vector4& other) const {
        return Vector4(XMVectorSubtract(ToXMVECTOR(), other.ToXMVECTOR()));
    }

    Vector4 operator * (float scalar) const {
        return Vector4(XMVectorScale(ToXMVECTOR(), scalar));
    }

    Vector4 operator / (float scalar) const {
        return Vector4(XMVectorScale(ToXMVECTOR(), 1.0f / scalar));
    }

    float Dot(const Vector4& other) const {
        return XMVectorGetX(XMVector4Dot(ToXMVECTOR(), other.ToXMVECTOR()));
    }

    float Length() const {
        return XMVectorGetX(XMVector4Length(ToXMVECTOR()));
    }

    Vector4 Normalize() const {
        return Vector4(XMVector4Normalize(ToXMVECTOR()));
    }
};
