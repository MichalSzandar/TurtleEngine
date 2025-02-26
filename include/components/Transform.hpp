#ifndef TRANSFORM_HPP
#define TRANSFORM_HPP

#include "Transformable.hpp"

class Transform : public Transformable {
    public:
        Transform(float x = 0, float y = 0);
        std::type_index getType() const override;

        void displayMenu() override;

        void setPosition(sf::Vector2f position) override;
        void setScale(sf::Vector2f scale) override;
        void setRotation(sf::Vector2f rotation) override;
        void setTranslate(sf::Vector2f translate) override;

        void drawGizmos(sf::RenderWindow &window) override;
};

#endif