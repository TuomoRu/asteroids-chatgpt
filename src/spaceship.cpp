// Spaceship.cpp
#include <math.h>
#include "Spaceship.hpp"
#include "raylib.h" // Include Raylib for drawing and input functions

// Constants for spaceship behavior
const float ROTATION_SPEED = 200.0f; // Degrees per second
const float ACCELERATION = 0.1f;     // Acceleration rate
const float MAX_SPEED = 4.0f;        // Maximum speed
const float SHOOT_COOLDOWN = 0.5f;   // Seconds between shots

void Spaceship::Update() {
    // Handle rotation
    if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
        RotateLeft(GetFrameTime());
    }
    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
        RotateRight(GetFrameTime());
    }

    // Handle acceleration
    if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) {
        Accelerate(GetFrameTime());
    }

    // Update position based on velocity
    position.Add(velocity);

    // Wrap around screen edges
    if (position.x > GetScreenWidth()) position.x = 0;
    if (position.x < 0) position.x = GetScreenWidth();
    if (position.y > GetScreenHeight()) position.y = 0;
    if (position.y < 0) position.y = GetScreenHeight();

    // Handle shooting
    if (canShoot && IsKeyPressed(KEY_SPACE)) {
        Shoot();
        canShoot = false;
        shootCooldown = SHOOT_COOLDOWN;
    }

    // Update shoot cooldown
    if (!canShoot) {
        shootCooldown -= GetFrameTime();
        if (shootCooldown <= 0) {
            canShoot = true;
        }
    }
}

void Spaceship::Draw() const {
    // Placeholder spaceship drawing - replace with actual spaceship drawing logic
    DrawTriangle(
        Vector2{position.x + sinf(rotation * DEG2RAD) * 20, position.y - cosf(rotation * DEG2RAD) * 20},
        Vector2{position.x - cosf((rotation + 90) * DEG2RAD) * 10, position.y - sinf((rotation + 90) * DEG2RAD) * 10},
        Vector2{position.x - cosf((rotation - 90) * DEG2RAD) * 10, position.y - sinf((rotation - 90) * DEG2RAD) * 10},
        WHITE);
}

void Spaceship::RotateLeft(float deltaTime) {
    rotation -= ROTATION_SPEED * deltaTime;
}

void Spaceship::RotateRight(float deltaTime) {
    rotation += ROTATION_SPEED * deltaTime;
}

void Spaceship::Accelerate(float deltaTime) {
    // Increase velocity in the direction of the current rotation
    velocity.x += sinf(rotation * DEG2RAD) * ACCELERATION;
    velocity.y -= cosf(rotation * DEG2RAD) * ACCELERATION;

    // Clamp speed to MAX_SPEED
    float currentSpeed = velocity.Magnitude();
    if (currentSpeed > MAX_SPEED) {
        velocity.Normalize();
        velocity *= MAX_SPEED;
    }
}

void Spaceship::Shoot() {
    // Implement shooting logic
    // This typically involves creating a new Bullet instance and adding it to a list of bullets in the game
}

// Note: The actual drawing of the spaceship and bullets should be done using appropriate Raylib functions
// and may involve loading and drawing textures or shapes that represent these entities.