#include "components/Transformable.hpp"

sf::Vector2f Transformable::getPosition() {
    return position + translate;
}

sf::Vector2f Transformable::getScale() {
    return scale;
}

sf::Vector2f Transformable::getRotation() {
    return rotation;
}

sf::Vector2f Transformable::getTranslate() {
    return translate;
}
