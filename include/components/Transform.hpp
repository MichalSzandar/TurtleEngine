#ifndef TRANSFORM_HPP
#define TRANSFORM_HPP

#include "Component.hpp"

class Transform : public Component {
    private: 
    float x, y;

    public:
    Transform(float x = 0, float y = 0);
    std::type_index getType() const override;
    float getX();
    float getY();
};

#endif