#include "Menu.h"
#include <SFML/Audio.hpp>

Menu::Menu(sf::RenderWindow &window): WINDOWW(window)
    {
        if (!TextBackground.loadFromFile("source/anhMinecraftdeplamluon.jpg")) std::cout << "khong load duoc";
        if (!font.loadFromFile("source/NexaRustSlab-BlackShadow01.otf")) std::cout << "khong load duoc";
        BackgroundMenu.setTexture(TextBackground);

        poorSnake.setFont(font);
        poorSnake.setFillColor(sf::Color::Black);
        poorSnake.setCharacterSize(50);
        poorSnake.setString("Poor Snake");
        poorSnake.setPosition(sf::Vector2f(800, 75));

        menuKey[0].setFont(font);
        menuKey[0].setFillColor(sf::Color::White);
        menuKey[0].setCharacterSize(40);
        menuKey[0].setString("Start");
        menuKey[0].setPosition(sf::Vector2f(1200/2, 640/2 - 50));

        menuKey[1].setFont(font);
        menuKey[1].setFillColor(sf::Color::Black);
        menuKey[1].setCharacterSize(40);
        menuKey[1].setString("Exit");
        menuKey[1].setPosition(sf::Vector2f(1200/2, 640/2 + 75));
        changeKey= 0;
    }
void Menu::MoveDown()
    {
        if(changeKey - 1 >=0)
        {
            menuKey[changeKey].setFillColor(sf::Color::Black);
            changeKey--;
            menuKey[changeKey].setFillColor(sf::Color::White);
        }

    }
void Menu::MoveUp()
    {
        if(changeKey + 1 < 2)
        {
            menuKey[changeKey].setFillColor(sf::Color::Black);
            changeKey++;
            menuKey[changeKey].setFillColor(sf::Color::White);
        }

    }
void Menu::Draw()
    {   WINDOWW.clear();
        WINDOWW.draw(BackgroundMenu);
        WINDOWW.draw(poorSnake);
        for (int i=0; i < 2; i++)
            {
                WINDOWW.draw(menuKey[i]);
            }
        WINDOWW.display();
    }

void Menu::handleEvent(sf::Event event)
    {   while (WINDOWW.pollEvent(event))
        {   if (event.type == sf::Event::Closed) WINDOWW.close();
            if(event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::Down)
                MoveUp();                
            if (event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::Up)
                MoveDown();
            if ((event.key.code == sf::Keyboard::Escape) || (event.key.code == sf::Keyboard::Enter && changeKey == 1))
                WINDOWW.close();
            if (event.key.code == sf::Keyboard::Enter && changeKey == 0)
                changeState(1);

        }
        }
        
    }