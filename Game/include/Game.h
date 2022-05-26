#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Audio.hpp>

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <memory>
#include <fstream>

#include "Snake.h"
#include "State.h"

class Game{  
public:
    bool FLAG;
    sf::RenderWindow &WINDOW;
    sf::Texture BOARD;
    sf::Sprite board;
    sf::Texture FOOD[2];
    sf::Sprite food[2];
    sf::Texture SNAKE[3];
    Snake snake;

    sf::Text scoreText[2];
    sf::Text highestScore;
    sf::Font font;
    int score;
    int bestScore;
    std::ifstream fileIN;
    std::ofstream fileOUT;
    sf::Font fontScore;

    sf::Texture WASD;
    sf::Sprite wasd;
    sf::Vector2f snake_direction;
    int z;

    sf::Time elapsedTime = sf::Time::Zero;
    sf::Time delayMove = sf::Time::Zero;
    sf::Time timePerFrame = sf::seconds(1.0f/60.0f);
    sf::Time timeDelayMove = sf::seconds(1.0f/1000.0f);

    bool musicGameOn = false;
    bool checkEat = false;
    bool CheckGamePause = false;
    bool CheckGameOver = false;
    sf::Font fontPause;
    sf::Text textGameOver;
    sf::Text textPause;

    sf::Music musicGame;
    sf::SoundBuffer eatSound;
    sf::Sound eat;

    Game(sf::RenderWindow &window);
    void randomFood();
    void Run(sf::Event &event);
    void Draw();
    void Reset();
    void BestScore();
};