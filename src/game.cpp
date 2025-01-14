// Game.cpp
#include "Game.hpp"
#include "raylib.h"
#include <raymath.h>

Game::Game() : gameOver(false), spaceship(nullptr) {
    InitWindow(800, 600, "Asteroids");
    Init();
}

Game::~Game() {
    Shutdown();
    CloseWindow(); // Close the Raylib window
}

void Game::Init() {
    // Initialize game entities
    spaceship = new Spaceship(Vector2D(GetScreenWidth()/2, GetScreenHeight()/2));
    // Initially spawn a few asteroids
    for(int i = 0; i < 5; ++i) {
        SpawnAsteroid();
    }
}

void Game::Run() {
    SetTargetFPS(60); // Set the game to run at 60 frames/second
    while (!WindowShouldClose() && !gameOver) {
        Update();
        Draw();
    }
}

void Game::Update() {
    spaceship->Update();
    for (auto* asteroid : asteroids) {
        asteroid->Update();
    }
    for (auto* bullet : bullets) {
        bullet->Update();
    }

    CheckCollisions();
    Cleanup();
}

void Game::Draw() {
    BeginDrawing();
    ClearBackground(BLACK);

    spaceship->Draw();
    for (auto* asteroid : asteroids) {
        asteroid->Draw();
    }
    for (auto* bullet : bullets) {
        bullet->Draw();
    }

    EndDrawing();
}

void Game::Shutdown() {
    // Clean up dynamically allocated memory
    delete spaceship;
    for (auto* asteroid : asteroids) {
        delete asteroid;
    }
    asteroids.clear();
    for (auto* bullet : bullets) {
        delete bullet;
    }
    bullets.clear();
}

void Game::SpawnAsteroid() {
    // Define asteroid size range if your game design includes different sizes
    Asteroid::Size sizes[] = {Asteroid::Size::Large, Asteroid::Size::Medium, Asteroid::Size::Small};
    int sizeIndex = GetRandomValue(0, 2); // Randomly select size (assuming 0: Large, 1: Medium, 2: Small)
    
    // Define the bounds for the spawn location and velocity to ensure asteroids appear from all sides
    float posX = static_cast<float>(GetRandomValue(0, GetScreenWidth()));
    float posY = static_cast<float>(GetRandomValue(0, GetScreenHeight()));
    
    // Ensure that asteroids don't spawn too close to the spaceship to avoid immediate collisions
    // You might want to adjust these values based on your game's difficulty level
    while (Vector2Distance(Vector2{posX, posY}, Vector2{static_cast<float>(spaceship->GetPosition().x), static_cast<float>(spaceship->GetPosition().y)}) < 150) {
        posX = static_cast<float>(GetRandomValue(0, GetScreenWidth()));
        posY = static_cast<float>(GetRandomValue(0, GetScreenHeight()));
    }

    // Define velocity
    float velX = static_cast<float>(GetRandomValue(-100, 100)) / 100.0f; // Random velocity X
    float velY = static_cast<float>(GetRandomValue(-100, 100)) / 100.0f; // Random velocity Y

    // Create the asteroid with the randomized position, velocity, and size
    Asteroid* newAsteroid = new Asteroid(Vector2D(posX, posY), Vector2D(velX, velY), sizes[sizeIndex]);

    // Add the new asteroid to the game's list of asteroids
    asteroids.push_back(newAsteroid);
}

void Game::CheckCollisions() {
    // Vector to keep track of asteroids that need to be removed
    std::vector<Asteroid*> asteroidsToRemove;
    // Vector to keep track of bullets that need to be removed
    std::vector<Bullet*> bulletsToRemove;

    // Check for bullet-asteroid collisions
    for (auto* bullet : bullets) {
        for (auto* asteroid : asteroids) {
            if (IsColliding(bullet, asteroid)) {
                // If a bullet hits an asteroid, mark both for removal
                bulletsToRemove.push_back(bullet);
                asteroidsToRemove.push_back(asteroid);

                // Handle additional game logic here, like increasing the score or creating smaller asteroids
            }
        }
    }

    // Check for spaceship-asteroid collisions
    for (auto* asteroid : asteroids) {
        if (IsColliding(spaceship, asteroid)) {
            // Handle spaceship collision with asteroid
            // You might want to subtract a life, destroy the spaceship, or end the game
            asteroidsToRemove.push_back(asteroid);

            // Additional logic for spaceship collision could go here
        }
    }

    // Remove bullets that collided with asteroids
    for (auto* bullet : bulletsToRemove) {
        bullets.erase(std::remove(bullets.begin(), bullets.end(), bullet), bullets.end());
        delete bullet; // Remember to delete to free memory
    }

    // Remove asteroids that were hit or collided with the spaceship
    for (auto* asteroid : asteroidsToRemove) {
        asteroids.erase(std::remove(asteroids.begin(), asteroids.end(), asteroid), asteroids.end());
        delete asteroid; // Remember to delete to free memory
    }
}

bool Game::IsColliding(GameObject* obj1, GameObject* obj2) {
    // Simple circular collision detection
    Vector2D pos1 = obj1->GetPosition();
    Vector2D pos2 = obj2->GetPosition();
    float distance = Vector2D::Distance(pos1, pos2);

    // Assuming GetRadius is a method that returns the collision radius of the object
    float collisionDistance = obj1->GetRadius() + obj2->GetRadius();
    return distance < collisionDistance;
}

void Game::Cleanup() {
    // Remove inactive or destroyed bullets
    auto bulletIter = bullets.begin();
    while (bulletIter != bullets.end()) {
        Bullet* bullet = *bulletIter;
        // Assume Bullet objects have an `IsAlive` method to check their status
        if (!bullet->IsAlive()) {
            delete bullet; // Free the memory
            bulletIter = bullets.erase(bulletIter); // Remove from the list and get next iterator
        } else {
            ++bulletIter; // Move to the next bullet if this one is still active
        }
    }

    // Remove inactive or destroyed asteroids
    auto asteroidIter = asteroids.begin();
    while (asteroidIter != asteroids.end()) {
        Asteroid* asteroid = *asteroidIter;
        // Assuming Asteroid objects have a similar method or flag to check if they should be removed
        if (!asteroid->IsActive()) {
            delete asteroid; // Free the memory
            asteroidIter = asteroids.erase(asteroidIter); // Remove from the list and get next iterator
        } else {
            ++asteroidIter; // Move to the next asteroid if this one is still active
        }
    }
}