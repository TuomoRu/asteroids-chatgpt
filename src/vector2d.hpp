// Vector2D.hpp
#ifndef VECTOR2D_HPP
#define VECTOR2D_HPP

class Vector2D {
public:
    float x, y;

    // Constructors
    Vector2D();
    Vector2D(float x, float y);

    // Vector operations
    Vector2D& Add(const Vector2D& vec);
    Vector2D& Subtract(const Vector2D& vec);
    Vector2D& Multiply(float scalar);
    float DotProduct(const Vector2D& vec) const;
    float Magnitude() const;
    Vector2D& Normalize();

    // Operator overloads for convenience
    Vector2D& operator+=(const Vector2D& vec);
    Vector2D& operator-=(const Vector2D& vec);
    Vector2D& operator*=(float scalar);
    friend Vector2D operator+(Vector2D v1, const Vector2D& v2);
    friend Vector2D operator-(Vector2D v1, const Vector2D& v2);
    friend Vector2D operator*(Vector2D v1, float scalar);

    // Utility functions
    static float Distance(const Vector2D& v1, const Vector2D& v2);
};

#endif // VECTOR2D_HPP