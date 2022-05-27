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
        changeLevel =0;

        // Level
        textLevel[0].setFont(font);
        textLevel[0].setFillColor(sf::Color::White);
        textLevel[0].setCharacterSize(40);
        textLevel[0].setString("level 1");
        textLevel[0].setPosition(sf::Vector2f(1200/2, 640/2 - 150));

        textLevel[1].setFont(font);
        textLevel[1].setFillColor(sf::Color::Black);
        textLevel[1].setCharacterSize(40);
        textLevel[1].setString("level 2");
        textLevel[1].setPosition(sf::Vector2f(1200/2, 640/2));

        textLevel[2].setFont(font);
        textLevel[2].setFillColor(sf::Color::Black);
        textLevel[2].setCharacterSize(40);
        textLevel[2].setString("level 3");
        textLevel[2].setPosition(sf::Vector2f(1200/2, 640/2 + 150));
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
    {   if (startIn)
        {
            WINDOWW.clear();
        WINDOWW.draw(BackgroundMenu);
        for (int i=0; i < 3; i++)
            {
                WINDOWW.draw(textLevel[i]);
            }
        WINDOWW.display();}
        else if (startIn == false)
        {
            WINDOWW.clear();
        WINDOWW.draw(BackgroundMenu);
        WINDOWW.draw(poorSnake);
        for (int i=0; i < 2; i++)
            {
                WINDOWW.draw(menuKey[i]);
            }
        WINDOWW.display();}
    }

void Menu::handleEvent(sf::Event &event)
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
                startIn = true;

        }
        }
        
    }
void Menu::handleEventMenu(sf::Event &event)
{
    while (WINDOWW.pollEvent(event))
        {   if (event.type == sf::Event::Closed) WINDOWW.close();
            if(event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::Down)
                MoveUpLevel();
            if (event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::Up)
                MoveDownLevel();
            if ((event.key.code == sf::Keyboard::Escape) || (event.key.code == sf::Keyboard::Enter && changeKey == 1))
                WINDOWW.close();
            if (event.key.code == sf::Keyboard::Enter && changeLevel == 0)
                {startLevel(1);
                 changeState(1);}
            if (event.key.code == sf::Keyboard::Enter && changeLevel == 1)
                {startLevel(2);
                 changeState(1);}
            if (event.key.code == sf::Keyboard::Enter && changeLevel == 2)
                {startLevel(3);
                 changeState(1);}

        }
        }

};
void Menu::MoveUpLevel()
{   if (changeLevel + 1 <= 2)
    {
        textLevel[changeLevel].setFillColor(sf::Color::Black);
        changeLevel++;
        textLevel[changeLevel].setFillColor(sf::Color::White);
    }
}
void Menu::MoveDownLevel()
{
    if (changeLevel -1 >= 0)
    {
        textLevel[changeLevel].setFillColor(sf::Color::Black);
        changeLevel--;
        textLevel[changeLevel].setFillColor(sf::Color::White);
    }
}
