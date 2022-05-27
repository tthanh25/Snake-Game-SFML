#include "include/Game.h"
#include "include/State.h"
#include "include/Menu.h"
#include <iostream>

int main ()
        {
        sf::Clock clock;
        sf::Time delayTime = sf::Time::Zero;
        sf::Time elapsedTime = sf::Time::Zero;
        sf::Time timePerFrame = sf::seconds(1.0f/60.0f);
        std::srand(time(NULL));

                // Thêm âm thanh, hiệu ứng khi chơi và ăn mồi
        sf::Music musicGame;
        sf::Music musicMenu;
        if (!musicGame.openFromFile("source/Point_the_star_music.ogg")) std::cout << "khong load duoc";
        if (!musicMenu.openFromFile("source/C418_Sweden_Trap_Remix.ogg")) std::cout << "khong load duoc";
        musicMenu.setVolume(20.0f);
        musicGame.setVolume(20.0f);
        musicGame.setLoop(true);
        musicMenu.setLoop(true);
        
        sf::RenderWindow window(sf::VideoMode(1280, 640), "Snake Game");
        window.setVerticalSyncEnabled(true);
        
        Menu menu(window);
        Game game(window);
                
        while (window.isOpen())
                {       sf::Event event;
                        delayTime+= clock.restart();
                        
                        while (delayTime > timePerFrame)
                        {
                                
                                delayTime -= timePerFrame;
                                
                                if(getCurrentState() == 0)
                                       {
                                        game.Reset();
                                        if (menu.startIn == false)
                                        {menu.handleEvent(event); menu.Draw();}
                                        else if (menu.startIn == true)
                                        {menu.handleEventMenu(event);
                                        musicMenu.play(); 
                                        menu.Draw();}
                                        }
                                        
                                if (getCurrentState() == 1) {
                                        game.Run(event);
                                        game.randomFood();
                                        game.Draw();
                                        }
                        }       
                                
                }
        
        return 0;
        }




