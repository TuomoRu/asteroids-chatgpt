// Spaceship.hpp
#ifndef SPACESHIP_HPP
#define SPACESHIP_HPP

#include "GameObject.hpp"

class Spaceship : public GameObject {
public:
    // Constructor
    Spaceship(Vector2D pos = Vector2D(), Vector2D vel = Vector2D(), float rot = 0.0f)
        : GameObject(pos, vel, rot), lives(3), speed(0.0f), canShoot(true), shootCooldown(0.0f) {}

    // Override GameObject's Update and Draw methods
    virtual void Update() override;
    virtual void Draw() const override;

    // Additional functionality specific to the spaceship
    void RotateLeft(float deltaTime);  // Rotate the spaceship left
    void RotateRight(float deltaTime); // Rotate the spaceship right
    void Accelerate(float deltaTime);  // Accelerate the spaceship
    void Shoot();                       // Fire a bullet

    // Getters and Setters for spaceship properties
    int GetLives() const { return lives; }
    void SetLives(int newLives) { lives = newLives; }
    bool CanShoot() const { return canShoot; }
    void ResetShootCooldown() { shootCooldown = 0; } // Reset shooting cooldown to enable shooting again

private:
    int lives;            // Number of lives the spaceship has
    float speed;          // Current speed of the spaceship
    bool canShoot;        // Flag to control shooting rate
    float shootCooldown;  // Cooldown timer for shooting to prevent continuous shooting
};

#endif // SPACESHIP_HPP