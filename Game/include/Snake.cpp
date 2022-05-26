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
        float x = 320.0f;
        for (auto& piece : body)
            {   
                piece.setTexture(texture);
                piece.setPosition(sf::Vector2f(x,160.0f));
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
                posBody.push_back(piece.getPosition());
            }
        return posBody;
    }
std::vector <sf::Vector2f> Snake::getBodyPosEnd()
    {
        std::vector <sf::Vector2f> posBodyEnd;
        for (auto piece = body.end(); piece != body.begin(); piece++ )
        {
            posBodyEnd.push_back(piece->getPosition());
        }
        return posBodyEnd;
    }