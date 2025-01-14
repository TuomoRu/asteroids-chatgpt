// Vector2D.cpp
#include "Vector2D.hpp"
#include <cmath> // For sqrt function in Magnitude calculation

// Constructors
Vector2D::Vector2D() : x(0.0f), y(0.0f) {}

Vector2D::Vector2D(float x, float y) : x(x), y(y) {}

// Vector operations
Vector2D& Vector2D::Add(const Vector2D& vec) {
    x += vec.x;
    y += vec.y;
    return *this;
}

Vector2D& Vector2D::Subtract(const Vector2D& vec) {
    x -= vec.x;
    y -= vec.y;
    return *this;
}

Vector2D& Vector2D::Multiply(float scalar) {
    x *= scalar;
    y *= scalar;
    return *this;
}

float Vector2D::DotProduct(const Vector2D& vec) const {
    return x * vec.x + y * vec.y;
}

float Vector2D::Magnitude() const {
    return std::sqrt(x * x + y * y);
}

Vector2D& Vector2D::Normalize() {
    float magnitude = Magnitude();
    if (magnitude > 0) {
        (*this) *= (1 / magnitude);
    }
    return *this;
}

// Operator overloads
Vector2D& Vector2D::operator+=(const Vector2D& vec) {
    return this->Add(vec);
}

Vector2D& Vector2D::operator-=(const Vector2D& vec) {
    return this->Subtract(vec);
}

Vector2D& Vector2D::operator*=(float scalar) {
    return this->Multiply(scalar);
}

Vector2D operator+(Vector2D v1, const Vector2D& v2) {
    return v1.Add(v2);
}

Vector2D operator-(Vector2D v1, const Vector2D& v2) {
    return v1.Subtract(v2);
}

Vector2D operator*(Vector2D v1, float scalar) {
    return v1.Multiply(scalar);
}

// Utility functions
float Vector2D::Distance(const Vector2D& v1, const Vector2D& v2) {
    Vector2D vec(v2.x - v1.x, v2.y - v1.y);
    return vec.Magnitude();
}