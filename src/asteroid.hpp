// Asteroid.hpp
#ifndef ASTEROID_HPP
#define ASTEROID_HPP

#include "GameObject.hpp"

class Asteroid : public GameObject {
public:
    enum class Size { Large = 3, Medium = 2, Small = 1 };

    // Constructor
    Asteroid(Vector2D pos, Vector2D vel, Size size)
        : GameObject(pos, vel), asteroidSize(size) {}

    // Override GameObject's Update and Draw methods
    virtual void Update() override;
    virtual void Draw() const override;

    // Getter for asteroid size
    Size GetSize() const { return asteroidSize; }

    // Function to break the asteroid into smaller pieces
    void Break();

private:
    Size asteroidSize; // Size of the asteroid
};

#endif // ASTEROID_HPP