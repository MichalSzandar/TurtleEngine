#ifndef TRANSFORM_HPP
#define TRANSFORM_HPP

#include "Component.hpp"

class Transform : public Component {
    private: 
    sf::Vector2f position, scale, rotation;
    
    public:

    Transform(float x = 0, float y = 0);
    std::type_index getType() const override;

    void displayMenu() override;

    float getX();
    void setX(float x);

    float getY();
    void setY(float y);

    float getScaleX();
    void setScaleX(float scaleX);

    float getScaleY();
    void setScaleY(float scaleY);

    float getRotationX();
    void setRotationX(float rotateX);

    void setPosition(sf::Vector2f position) override;
    void setScale(sf::Vector2f scale) override;
};

#endif