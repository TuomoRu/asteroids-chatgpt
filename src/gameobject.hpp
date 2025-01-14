// GameObject.hpp
#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include "Vector2D.hpp"

class GameObject {
public:
    // Constructor with initialization list for position and velocity
    GameObject(Vector2D pos = Vector2D(), Vector2D vel = Vector2D(), float rot = 0.0f) 
        : position(pos), velocity(vel), rotation(rot) {}

    virtual ~GameObject() = default; // Virtual destructor for safe polymorphic use

    // Update and Draw methods to be overridden by derived classes
    virtual void Update() = 0; // Pure virtual function for updating the game object's state
    virtual void Draw() const = 0; // Pure virtual function for drawing the game object

    // Getter for position
    Vector2D GetPosition() const { return position; }

    // Setter for position
    void SetPosition(const Vector2D& newPos) { position = newPos; }

    // Getter for velocity
    Vector2D GetVelocity() const { return velocity; }

    // Setter for velocity
    void SetVelocity(const Vector2D& newVel) { velocity = newVel; }

    // Getter for rotation
    float GetRotation() const { return rotation; }

    // Setter for rotation
    void SetRotation(float newRot) { rotation = newRot; }

    virtual float GetRadius() const = 0;

protected:
    Vector2D position; // Position of the game object
    Vector2D velocity; // Velocity of the game object
    float rotation; // Rotation angle of the game object in degrees
};

#endif // GAMEOBJECT_HPP