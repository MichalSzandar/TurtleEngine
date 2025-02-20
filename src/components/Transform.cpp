#include "components/Transform.hpp"

Transform::Transform(float x, float y) {
    this->x = x;
    this->y = y;
}

std::type_index Transform::getType() const {
    return typeid(Transform);
}

float Transform::getX() {
    return this->x;
}

float Transform::getY() {
    return this->y;
}
