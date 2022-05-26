#pragma once 

#include <list>
#include <queue>

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Drawable.hpp>

class Snake : public sf::Drawable
{
    private:
    std::list <sf::Sprite> body;
    std::list <sf::Sprite>::iterator head;
    std::list <sf::Sprite>::iterator tail;
    sf::Vector2f snake_direction;
    
    public:
    Snake();
    ~Snake();

    void Init(const sf::Texture &texture);
    void loadNew(const sf::Texture &texture);
    void Move(const sf::Vector2f &direction);
    bool IsOn(const sf::Sprite &other);
    void Grow(const sf::Vector2f &direction);
    bool selfIntersect();
    void Reset();
    std::vector <sf::Vector2f> getBodyPos();
    std::vector <sf::Vector2f> getBodyPosEnd();

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};