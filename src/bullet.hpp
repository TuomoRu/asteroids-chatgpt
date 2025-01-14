// Bullet.hpp
#ifndef BULLET_HPP
#define BULLET_HPP

#include "GameObject.hpp"

class Bullet : public GameObject {
public:
    // Constructor
    Bullet(Vector2D pos, Vector2D vel)
        : GameObject(pos, vel), lifespan(2.0f) {} // Lifespan in seconds

    // Override GameObject's Update and Draw methods
    virtual void Update() override;
    virtual void Draw() const override;

    // Check if the bullet is still alive
    bool IsAlive() const;

private:
    float lifespan; // Time remaining before the bullet disappears
};

#endif // BULLET_HPP