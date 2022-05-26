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
        sf::SoundBuffer eatSound;
        sf::Sound eat;
        if (!musicGame.openFromFile("source/Point_the_star_music.ogg")) std::cout << "khong load duoc";
        if (!musicMenu.openFromFile("source/C418_Sweden_Trap_Remix.ogg")) std::cout << "khong load duoc";
        if (!eatSound.loadFromFile("source/EatSound_CC0_by_EugeneLoza.ogg")) std::cout << "khong load duoc";
        eat.setBuffer(eatSound);
        eat.setVolume(100.0f);
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
                                        menu.handleEvent(event);
                                        menu.Draw();
                                        break;}
                                        
                                if (getCurrentState() == 1) {
                                        game.Run(event);
                                        game.randomFood();
                                        game.Draw();
                                        break;
                                        }
                        }       
                                if (getCurrentState() != 1){
                                        musicMenu.play(); 
                                        // musicGame.play();
                                        }
                                if (game.checkEat) if (game.CheckGameOver == 0) eat.play();
                                if (game.CheckGameOver) eat.stop();
                                
                }
        
        return 0;
        }




