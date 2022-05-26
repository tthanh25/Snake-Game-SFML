#pragma once
#include <SFML/Graphics.hpp>

#include <iostream>
#include "Game.h"
#include "State.h"
class Menu
{

public:
    sf::RenderWindow &WINDOWW;
    sf::Text menuKey[2];
    sf::Text poorSnake;
    sf::Texture TextBackground;
    sf::Sprite BackgroundMenu;
    sf::Font font;
    int changeKey;

    Menu(sf::RenderWindow &window);
    void handleEvent(sf::Event event);
    void MoveUp();
    void MoveDown();
    void Draw();

};