#ifndef SPHERECOLLIDER_HPP
#define SPHERECOLLIDER_HPP

#include "Collider.hpp"
#include "components/BoxCollider.hpp"

/**
 * @class SphereCollider
 * @brief A collider that has a circular shape.
 */
class SphereCollider : public Collider {
    private:
        sf::CircleShape bounds;
        float radius;

    public:
        SphereCollider();
        SphereCollider(float radius);
        ~SphereCollider() = default;

        std::type_index getType() const override;

        void displayMenu() override;

        // Transformable --------------------------------
        void setPosition(sf::Vector2f position) override;
        void setScale(sf::Vector2f scale) override;
        void setRotation(sf::Vector2f rotation) override;
        void setTranslate(sf::Vector2f translate) override;
        //-----------------------------------------------

        void drawGizmos(sf::RenderWindow &window) override;

        sf::CircleShape getBounds() const;
        float getRadius() const;
        void setRadius(float radius);
        
        bool intersectsWith(BoxCollider *collider) override;
        bool intersectsWith(SphereCollider *collider) override;
};

#endif // SPHERECOLLIDER_HPP