// GameObject.cpp
#include "GameObject.hpp"

// Constructor
GameObject::GameObject(Vector2D pos, Vector2D vel, float rot)
    : position(pos), velocity(vel), rotation(rot) {
    // Initialization or other constructor actions can be placed here if necessary
}

// Destructor - Even if it's virtual and default, defining it explicitly could be helpful in certain scenarios
GameObject::~GameObject() {
    // Clean up resources or log actions if needed
}

float GameObject::GetRadius()
{
    return 0.0f;
}

// Note: Since the Update and Draw methods are pure virtual, they are not implemented here.
// Derived classes will provide their own implementations for these methods.

// Other non-pure virtual or non-inline member functions would be implemented here, if they exist.