#pragma once
#include <DirectXMath.h>

using namespace DirectX;

class Vector2 : public XMFLOAT2 {
public:
    Vector2() : XMFLOAT2(0.0f, 0.0f) {}
    Vector2(float x, float y) : XMFLOAT2(x, y) {}
    Vector2(const XMFLOAT2& other) : XMFLOAT2(other) {}
    Vector2(const XMVECTOR& vec) {
        XMStoreFloat2(this, vec);
    }

    XMVECTOR ToXMVECTOR() const {
        return XMLoadFloat2(this);
    }

    Vector2 operator + (const Vector2& other) const {
        return Vector2(XMVectorAdd(ToXMVECTOR(), other.ToXMVECTOR()));
    }

    Vector2 operator - (const Vector2& other) const {
        return Vector2(XMVectorSubtract(ToXMVECTOR(), other.ToXMVECTOR()));
    }

    Vector2 operator * (float scalar) const {
        return Vector2(XMVectorScale(ToXMVECTOR(), scalar));
    }

    Vector2 operator / (float scalar) const {
        return Vector2(XMVectorScale(ToXMVECTOR(), 1.0f / scalar));
    }

    float Dot(const Vector2& other) const {
        return XMVectorGetX(XMVector2Dot(ToXMVECTOR(), other.ToXMVECTOR()));
    }

    float Length() const {
        return XMVectorGetX(XMVector2Length(ToXMVECTOR()));
    }

    Vector2 Normalize() const {
        return Vector2(XMVector2Normalize(ToXMVECTOR()));
    }
};
