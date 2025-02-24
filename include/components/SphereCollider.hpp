#ifndef SPHERECOLLIDER_HPP
#define SPHERECOLLIDER_HPP

#include "Collider.hpp"
#include <SFML/Graphics.hpp>

class SphereCollider : public Collider {
    private:
    float radius;
    float translateX, translateY;
    sf::CircleShape shape;

    public:
    SphereCollider();;
    SphereCollider(float radius);
    ~SphereCollider() = default;

    std::type_index getType() const override;

    void displayMenu() override;

    void setPosition(sf::Vector2f position) override;
    void setScale(sf::Vector2f scale) override;
    void setRotation(sf::Vector2f rotation) override;
};

#endif // SPHERECOLLIDER_HPP