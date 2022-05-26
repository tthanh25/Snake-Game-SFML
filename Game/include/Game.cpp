#include "Game.h"

Game::Game(sf::RenderWindow &window): WINDOW(window)
    {   
            // Khởi tạo hướng đi, điểm số
        snake_direction = sf::Vector2f (32.0f , 0.0f);
        z=0;
        score = 0;    
        FLAG=false;

                // Tạo bảng
        if (!BOARD.loadFromFile("source/back_ground.png")) std::cout << "khong load duoc";
        BOARD.setRepeated(true);
        board.setTexture(BOARD);
        board.setTextureRect(sf::IntRect(0,0,960,640));

                // Khởi tạo thức ăn
        if (!FOOD[1].loadFromFile("source/apple2.png",sf::IntRect(0,0,32,32))) std::cout << "khong load duoc";
        food[1].setTexture(FOOD[1]);
        if (!FOOD[0].loadFromFile("source/apple.png",sf::IntRect(0,0,32,32))) std::cout << "khong load duoc";
        food[0].setTexture(FOOD[0]);
        food[0].setPosition(sf::Vector2f(window.getSize().x / 2 ,window.getSize().y / 2));

                // Khởi tạo rắn
        if (!SNAKE[0].loadFromFile("source/circle-32.png")) std::cout << "khong load duoc";
        SNAKE[0].setSmooth(true);
        if (!SNAKE[1].loadFromFile("source/circle-32 (2).png")) std::cout << "khong load duoc";
        SNAKE[1].setSmooth(true);
        if (!SNAKE[2].loadFromFile("source/circle3.png")) std::cout << "khong load duoc";
        SNAKE[2].setSmooth(true);
        snake.Init(SNAKE[0]);

                // Khởi tạo điểm số
        if (!fontScore.loadFromFile("source/MIDNSBRG.ttf")) std::cout << "khong load duoc";
        scoreText[0].setFont(fontScore);
        scoreText[0].setString("Score: " + std::to_string(score));
        scoreText[0].setCharacterSize(30);
        scoreText[0].setFillColor(sf::Color::Black);
        scoreText[0].setPosition(sf::Vector2f(1000,50));

        scoreText[1].setFont(fontScore);
        scoreText[1].setFillColor(sf::Color::Black);
        scoreText[1].setCharacterSize(40);
        scoreText[1].setString("Your Score: " + std::to_string(score));
        scoreText[1].setPosition(sf::Vector2f(900/2, 640/2 + 75));

                // Tạo chữ pause
        if (!fontPause.loadFromFile("source/NexaRustSlab-BlackShadow01.otf")) std::cout << "khong load duoc";
        textPause.setFont(fontPause);
        textPause.setFillColor(sf::Color::Black);
        textPause.setCharacterSize(100);
        textPause.setString("Game Pause");
        textPause.setPosition(sf::Vector2f(600/2, 640/2 - 100));

                // Tạo chữ over
        textGameOver.setFont(fontPause);
        textGameOver.setFillColor(sf::Color::Black);
        textGameOver.setCharacterSize(100);
        textGameOver.setString("Game Over");
        textGameOver.setPosition(sf::Vector2f(600/2, 640/2 - 100));

                     // Hướng dẫn chơi, em add vào cho đỡ trống
        if (!WASD.loadFromFile("source/wasd.png")) std::cout << "khong load duoc";
        wasd.setTexture(WASD);
        wasd.setPosition(sf::Vector2f(1015,490));

                // Thêm Best Score
        if (!font.loadFromFile("source/NexaRustSans-Black.otf")) std::cout << "khong load duoc";
        fileIN.open("BestScore.txt");
        if (fileIN.is_open())
        fileIN >> bestScore;
        fileIN.close();
        if(!font.loadFromFile("source/NexaRustSans-Black.otf")) std::cout << "khong load duoc";
        highestScore.setFont(font);
        highestScore.setString("Best Score \n\n   " + std::to_string(bestScore));
        highestScore.setCharacterSize(25);
        highestScore.setFillColor(sf::Color::Black);
        highestScore.setPosition(sf::Vector2f(1000,250));


        window.setPosition(sf::Vector2i(43,50));
        
    }

        // Bắt các sự kiện, tạo logic game
void Game::Run( sf::Event &event)
    {   while (WINDOW.pollEvent(event))
        {
                delayMove+= timeDelayMove; 
                if (event.type == sf::Event::Closed) WINDOW.close();
        else if (event.type == sf::Event::KeyPressed && delayMove.asSeconds() >= 0.0025)
                {       
                        sf::Vector2f newDirection;
                        if (((event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::Left)))
                        
                        {       
                                newDirection = {-32.0f, 0.0f};                
                                   if (std::abs(snake_direction.x) != std::abs(newDirection.x) || std::abs(snake_direction.y) != std::abs(newDirection.y)) 
                        {snake_direction = newDirection; delayMove = sf::Time::Zero;}
                                }
                                
                        if (((event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::Up)))
                        {       
                                newDirection = {0.0f, -32.0f};
                              if (std::abs(snake_direction.x) != std::abs(newDirection.x) || std::abs(snake_direction.y) != std::abs(newDirection.y)) 
                        {snake_direction = newDirection; delayMove = sf::Time::Zero;}
                                }

                        if (((event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::Down))  )
                        {       
                                newDirection = {0.0f, 32.0f};
                                if (std::abs(snake_direction.x) != std::abs(newDirection.x) || std::abs(snake_direction.y) != std::abs(newDirection.y)) 
                        {snake_direction = newDirection; delayMove = sf::Time::Zero;}
                                }

                        if (((event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::Right))   )
                        {       
                                newDirection = {32.0f, 0.0f};
                                if (std::abs(snake_direction.x) != std::abs(newDirection.x) || std::abs(snake_direction.y) != std::abs(newDirection.y))
                        {snake_direction = newDirection; delayMove = sf::Time::Zero;}
                        }
                        if (event.key.code == sf::Keyboard::Space) 
                        {       if (CheckGameOver ==1 )  {CheckGamePause == 0; break;}
                                if (CheckGamePause == 0) {CheckGamePause =1; break;}
                                if (CheckGamePause == 1) {CheckGamePause =0; break;}
                        }
                        if (event.key.code == sf::Keyboard::Enter) 
                        {
                                if (CheckGameOver)
                                {       
                                        Game::Reset();
                                        CheckGameOver=0;
                                }
                        }

                        if (event.key.code == sf::Keyboard::Escape) WINDOW.close();
            
                
        }}
    }
        // Tạo mới vị trí thức ăn, cho rắn chạy
void Game::randomFood()
    {   elapsedTime += timePerFrame;
        if (!CheckGamePause && !CheckGameOver) { checkEat = false;
        if (elapsedTime.asSeconds() > 0.1)
        {       
        if (snake.Snake::IsOn(Game::food[0]) || snake.Snake::IsOn(Game::food[1]))
                {    checkEat = true;   
                        if (snake.Snake::IsOn(food[0])) {score++;
                                scoreText[0].setString("Score: " + std::to_string(score));
                                FLAG=false;
                                if (score >= 50) snake.loadNew(SNAKE[1]);
                                else snake.loadNew(SNAKE[0]);
                                }
                        if (snake.Snake::IsOn(food[1])) {score +=5;
                                scoreText[0].setString("Score: " + std::to_string(score));
                                snake.loadNew(SNAKE[2]);
                                FLAG = true;
                                }
                        snake.Snake::Grow(snake_direction);
                        int x = 0; int y = 0;
                        z = rand() % 4;
                        std::vector <sf::Vector2f> newFoodPos;
                        newFoodPos = snake.getBodyPos();
                        std::vector <sf::Vector2f> newFoodPos2;
                        newFoodPos2 = snake.getBodyPosEnd();
                        x = rand() % 30;
                        y = rand() % 20;
                        for (auto k : newFoodPos)
                        {       
                                if (x == k.x && y == k.y)
                                {
                                for (auto h : newFoodPos2)
                                {
                                x = rand() % 30;
                                y = rand() % 20;  
                                if (x != h.x || y != h.y) break;    
                                
                                if (x != k.x || y != k.y) break;
                                }    
                                }
                        }
                        
                        if (z == 2) {
                                food[1].setPosition(sf::Vector2f(x*32.0f,y*32.0f));
                        }
                        else food[0].setPosition(sf::Vector2f(x*32.0f,y*32.0f));
                        
                        
                }
                else snake.Snake::Move(snake_direction);
                if ((snake.selfIntersect() || !snake.IsOn(board)) && FLAG == false) {scoreText[1].setString("Your Score: " + std::to_string(score));
                        CheckGameOver=true;
                }
        elapsedTime = sf::Time::Zero;
        }}
    }
void Game::Draw()
{       
                        WINDOW.clear(sf::Color( 230, 230, 250, 1 ));
                        WINDOW.draw(board);
                        if (z==2) WINDOW.draw(food[1]);
                        else WINDOW.draw(food[0]);
                        WINDOW.draw(snake);
                        WINDOW.draw(scoreText[0]);
                        WINDOW.draw(wasd);
                        WINDOW.draw(highestScore);
                        if (CheckGamePause) WINDOW.draw(textPause);
                        if (CheckGameOver){ 
                                 WINDOW.draw(textGameOver);
                                 WINDOW.draw(scoreText[1]);
                                 if (score > bestScore )
                                        {
                                                fileOUT.open("BestScore.txt");
                                                if (fileOUT.is_open());
                                                fileOUT << score;
                                                fileOUT.close();
                                        }
                        }

                        WINDOW.display();
}
void Game::Reset()
{
        srand(time(NULL));
        z=0;
        score = 0;
        fileIN.open("BestScore.txt");
        if (fileIN.is_open())
        fileIN >> bestScore;
        fileIN.close();
        scoreText[0].setString("Score: " + std::to_string(score));
        scoreText[1].setString("Your Score: " + std::to_string(score));
        food[0].setPosition(sf::Vector2f(WINDOW.getSize().x / 2 ,WINDOW.getSize().y / 2));
        snake.Reset();
        snake.Init(SNAKE[0]);
        snake_direction = sf::Vector2f(32.0f,0.0f);
        FLAG=false;
};

