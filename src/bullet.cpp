// Bullet.cpp
#include "Bullet.hpp"
#include "raylib.h"

void Bullet::Update() {
    // Move the bullet
    position.Add(velocity);

    // Reduce the lifespan of the bullet
    lifespan -= GetFrameTime();

    // Bullets could also wrap around the screen or disappear at the edges,
    // depending on the desired game behavior
}

void Bullet::Draw() const {
    // Simple representation of the bullet as a small circle or a line
    DrawCircle(static_cast<int>(position.x), static_cast<int>(position.y), 2, WHITE); // Example size and color
}

bool Bullet::IsAlive() const {
    return lifespan > 0;
}