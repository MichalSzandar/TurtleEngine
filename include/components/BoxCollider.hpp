#ifndef BOXCOLLIDER_HPP
#define BOXCOLLIDER_HPP    

#include "Collider.hpp"
#include <SFML/Graphics.hpp>
#include <typeindex>

class BoxCollider : public Collider {
    private:
        sf::FloatRect bounds;
        float translateX, translateY, x, y, width, height, rotation;

    public:
        BoxCollider();
        BoxCollider(float x, float y, float width, float height);

        std::type_index getType() const override;

        void displayMenu() override;

        void setPosition(sf::Vector2f position) override;
        void setScale(sf::Vector2f scale) override;
        void setRotation(sf::Vector2f rotation) override;

        sf::FloatRect getBounds() const;
        void setBounds(float x, float y, float width, float height);
        void setBounds(sf::FloatRect bounds);

        void drawGizmos(sf::RenderWindow &window) override;
        
        void setTranslateX(float translateX) override;
        void setTranslateY(float translateY) override;
};

#endif // BOXCOLLIDER_HPP