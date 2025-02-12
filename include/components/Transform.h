#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "components/Component.h"

class Transform : Component {
    private: 
    float x, y;

    public:
    Transform(float x = 0, float y = 0);
    std::type_index getType() const override;
    float getX();
    float getY();
};

#endif