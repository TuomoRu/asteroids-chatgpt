// Asteroid.cpp
#include "Asteroid.hpp"
#include "raylib.h"

void Asteroid::Update() {
    // Update asteroid position based on velocity
    position.Add(velocity);

    // Screen wrap logic
    if (position.x > GetScreenWidth()) position.x = 0;
    if (position.x < 0) position.x = GetScreenWidth();
    if (position.y > GetScreenHeight()) position.y = 0;
    if (position.y < 0) position.y = GetScreenHeight();
}

void Asteroid::Draw() const {
    // Simple asteroid drawing using circles for demonstration purposes
    // Adjust the size based on asteroidSize, and feel free to replace with more detailed graphics
    int radius = static_cast<int>(asteroidSize) * 10; // Example size scaling
    DrawCircle(static_cast<int>(position.x), static_cast<int>(position.y), radius, DARKGRAY);
}

void Asteroid::Break() {
    // Implementation for breaking the asteroid into smaller pieces
    // This function would likely create two new asteroids of the next smaller size
    // and add them to the game's asteroid list, then mark the current asteroid for deletion
}