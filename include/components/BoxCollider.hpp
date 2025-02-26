#ifndef BOXCOLLIDER_HPP
#define BOXCOLLIDER_HPP    

#include "Collider.hpp"
#include "components/SphereCollider.hpp"
#include <SFML/Graphics.hpp>
#include <typeindex>

class BoxCollider : public Collider{
    private:
        sf::FloatRect bounds;
        float width, height;

    public:
        BoxCollider();
        BoxCollider(float x, float y, float width, float height);
        ~BoxCollider() = default;

        std::type_index getType() const override;

        void displayMenu() override;

        // Transformable --------------------------------
        void setPosition(sf::Vector2f position) override;
        void setScale(sf::Vector2f scale) override;
        void setRotation(sf::Vector2f rotation) override;
        void setTranslate(sf::Vector2f translate) override;
        //-----------------------------------------------

        sf::FloatRect getBounds() const;
        void setBounds(float x, float y, float width, float height);
        void setBounds(sf::FloatRect bounds);

        void drawGizmos(sf::RenderWindow &window) override;

        bool intersectsWith(BoxCollider *collider) override;
        bool intersectsWith(SphereCollider *collider) override;
};

#endif // BOXCOLLIDER_HPP