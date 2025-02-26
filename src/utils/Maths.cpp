#include "utils/Maths.hpp"

float Maths::distance(sf::Vector2f v1, sf::Vector2f v2) {
    return std::sqrt(std::pow(v2.x - v1.x, 2) + std::pow(v2.y - v1.y, 2));
}

float Maths::length(sf::Vector2f v) {
    return std::sqrt(std::pow(v.x, 2) + std::pow(v.y, 2));
}

float Maths::product(sf::Vector2f v1, sf::Vector2f v2) {
    return v1.x * v2.x + v1.y * v2.y;
}

float Maths::distancePointToSegment(sf::Vector2f p, sf::Vector2f a, sf::Vector2f b) {
    sf::Vector2f ab = b - a;
    sf::Vector2f ap = p - a;
    sf::Vector2f bp = p - b;

    float e = product(ap, ab);

    if (e < 0) {
        return length(ap);
    }

    float f = product(ab, ab);

    if (e > f) {
        return length(bp);
    }

    return length(ap - ab * e / f);
}

float Maths::magnitude(sf::Vector2f v) {
    return std::sqrt(std::pow(v.x, 2) + std::pow(v.y, 2));
}

sf::Vector2f Maths::normalize(sf::Vector2f v) {
    float mag = magnitude(v);
    return sf::Vector2f(v.x / mag, v.y / mag);
}
