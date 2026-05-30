#pragma once
#include <DirectXMath.h>

using namespace DirectX;

class Matrix4x4 : public XMFLOAT4X4 {
public:
    Matrix4x4() {
        XMStoreFloat4x4(this, XMMatrixIdentity());
    }

    Matrix4x4(const XMMATRIX& mat) {
        XMStoreFloat4x4(this, mat);
    }

    Matrix4x4(const XMFLOAT4X4& mat) : XMFLOAT4X4(mat) {}

    XMMATRIX ToXMMATRIX() const {
        return XMLoadFloat4x4(this);
    }

    Matrix4x4 operator*(const Matrix4x4& other) const {
        return Matrix4x4(XMMatrixMultiply(ToXMMATRIX(), other.ToXMMATRIX()));
    }

    Vector2 TransformPoint(const Vector2& point) const {
        XMVECTOR vec = XMVectorSet(point.x, point.y, 0.0f, 1.0f);
        XMVECTOR result = XMVector4Transform(vec, ToXMMATRIX());
        return Vector2(result);
    }

    static Matrix4x4 Identity() {
        return Matrix4x4(XMMatrixIdentity());
    }

    static Matrix4x4 Translation(float x, float y, float z) {
        return Matrix4x4(XMMatrixTranslation(x, y, z));
    }

    static Matrix4x4 RotationZ(float angle) {
        return Matrix4x4(XMMatrixRotationZ(angle));
    }

    static Matrix4x4 Scale(float x, float y, float z) {
        return Matrix4x4(XMMatrixScaling(x, y, z));
    }
};
