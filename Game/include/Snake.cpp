#include "snake.h"

Snake:: Snake() : body(std::list <sf::Sprite> (4))
{
    
    head = --body.end();
    tail = body.begin();
};
Snake:: ~Snake()
{
};
    //Khởi tạo rắn
    void Snake::Init(const sf::Texture &texture)
    {
        float x = 0.0f;
        for (auto& piece : body)
            {   
                piece.setTexture(texture);
                piece.setPosition(sf::Vector2f(x,64.0f));
                x+=32;
            }
    }
    void Snake::loadNew(const sf::Texture &texture)
    {
        for (auto& piece : body)
            {   
                piece.setTexture(texture);
            }
    }
    //Di chuyển rắn
    void Snake::Move(const sf::Vector2f &direction)
    {
        tail->setPosition(sf::Vector2f(head->getPosition()+direction));
        head = tail;
        tail++;
        if (tail == body.end())
            {
                tail = body.begin();
            }
    }
    //Kiểm tra xem có va chạm (giao nhau)
    bool Snake::IsOn(const sf::Sprite &other)
    {
        return other.getGlobalBounds().intersects(head->getGlobalBounds());
    }
    //Khi ăn mồi, rắn dài ra
    void Snake::Grow(const sf::Vector2f &direction)
    {
        sf::Sprite new_body;
        new_body.setTexture(*(body.begin()->getTexture()));
        new_body.setPosition(sf::Vector2f(head->getPosition() + direction));
        head = body.insert( ++head, new_body);

    };

    //Vẽ rắn
    void Snake::draw(sf::RenderTarget &target, sf::RenderStates states) const 
    {
        for (auto& piece : body)
            {
                target.draw(piece);
            }
    }
    // Kiểm tra va chạm vào thân rắn
    bool Snake::selfIntersect()
    {   bool flag = false;
        for (auto piece = body.begin(); piece != body.end(); piece++ )
            {
                if (head != piece)
                    {
                        flag = IsOn(*piece);
                        if (flag) break;
                        
                    }
            }
        return flag;
    }

void Snake::Reset()
    {
        body.resize(4);
        head=--body.end();
        tail = body.begin();
    };
std::vector <sf::Vector2f> Snake::getBodyPos()
    {
        std::vector <sf::Vector2f> posBody;
        for (auto piece : body)
            {
                 posBody.push_back(sf::Vector2f(piece.getPosition().x /32, piece.getPosition().y /32));
            }
        return posBody;
    }
std::vector <sf::Vector2f> Snake::getEmpty()
    {   std::vector <sf::Vector2f> emptyCell;
        std::vector <sf::Vector2f> posBody = Snake::getBodyPos();
        for (int i = 0 ; i < 30; i++)
            for (int j = 0 ; j <20 ; j++)
                {   for (auto posEmpty : posBody)
                    if (i != posEmpty.x || j != posEmpty.y) emptyCell.push_back(sf::Vector2f(i,j));
                }
        return emptyCell;
    };
std::vector <sf::Vector2f> Snake::getEmptyWall(sf::Sprite sprite)
    {   
        std::vector <sf::Vector2f> emptyCell;
        std::vector <sf::Vector2f> posBody = Snake::getBodyPos();
        for (int i = 0 ; i < 30; i++)
            for (int j = 0 ; j <20 ; j++)
                {   for (auto posEmpty : posBody)
                    if (!sprite.getGlobalBounds().contains(sf::Vector2f(32*i,32*j)))
                    if (i != posEmpty.x || j != posEmpty.y) emptyCell.push_back(sf::Vector2f(i,j));
                }
        return emptyCell;
    };
std::vector <sf::Vector2f> Snake::getEmptyWallMove(sf::Sprite sprite1, sf::Sprite sprite2, sf::Sprite sprite3)
    {   
        std::vector <sf::Vector2f> emptyCell;
        std::vector <sf::Vector2f> posBody = Snake::getBodyPos();
        for (int i = 0 ; i < 30; i++)
            for (int j = 0 ; j <20 ; j++)
                {   for (auto posEmpty : posBody)
                    if (!sprite1.getGlobalBounds().contains(sf::Vector2f(32*i,32*j)))
                    if (!sprite2.getGlobalBounds().contains(sf::Vector2f(32*i,32*j)))
                    if (!sprite3.getGlobalBounds().contains(sf::Vector2f(32*i,32*j)))
                    if (i != posEmpty.x || j != posEmpty.y) emptyCell.push_back(sf::Vector2f(i,j));
                }
        return emptyCell;
    };