#ifndef TRANSFORMABLE_HPP
#define TRANSFORMABLE_HPP

#include <SFML/Graphics.hpp>
#include "Component.hpp"

class Transformable : public Component {
    protected:
        sf::Vector2f position, translate, scale, rotation;

    public:
        virtual void setPosition(sf::Vector2f position) = 0;
        virtual void setScale(sf::Vector2f scale) = 0;
        virtual void setRotation(sf::Vector2f rotation) = 0;
        virtual void setTranslate(sf::Vector2f translate) = 0;

        sf::Vector2f getPosition();
        sf::Vector2f getScale();
        sf::Vector2f getRotation();
        sf::Vector2f getTranslate();
};

#endif // TRANSFORMABLE_HPP