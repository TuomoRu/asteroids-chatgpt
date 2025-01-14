// Game.hpp
#ifndef GAME_HPP
#define GAME_HPP

#include "Spaceship.hpp"
#include "Asteroid.hpp"
#include "Bullet.hpp"
#include <vector>

class Game {
public:
    Game();
    ~Game();

    void Init();    // Initialize the game
    void Run();     // Run the game loop
    void Update();  // Update game logic
    void Draw();    // Draw the game to the screen
    void Shutdown();// Clean up resources

private:
    bool gameOver;              // Flag to control the game loop
    Spaceship* spaceship;       // Player's spaceship
    std::vector<Asteroid*> asteroids; // List of asteroids
    std::vector<Bullet*> bullets;     // List of bullets

    void SpawnAsteroid();       // Function to add an asteroid
    void CheckCollisions();    // Check for collisions between game entities
    bool IsColliding(GameObject* obj1, GameObject* obj2);
    void Cleanup();            // Cleanup destroyed entities
};

#endif // GAME_HPP