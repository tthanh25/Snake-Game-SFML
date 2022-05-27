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
    sf::Text textLevel[3];
    int changeLevel;
    bool startIn = false;

    Menu(sf::RenderWindow &window);
    void handleEvent(sf::Event &event);
    void handleEventMenu(sf::Event &event);
    void MoveUp();
    void MoveDown();
    void MoveUpLevel();
    void MoveDownLevel();
    void Draw();

};