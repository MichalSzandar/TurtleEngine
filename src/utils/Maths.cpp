#include "utils/Maths.hpp"

float Maths::distance(sf::Vector2f v1, sf::Vector2f v2) {
    return std::sqrt(std::pow(v2.x - v1.x, 2) + std::pow(v2.y - v1.y, 2));
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
        return magnitude(ap);
    }

    float f = product(ab, ab);

    if (e > f) {
        return magnitude(bp);
    }

    return magnitude(ap - ab * e / f);
}

float Maths::magnitude(sf::Vector2f v) {
    return std::sqrt(std::pow(v.x, 2) + std::pow(v.y, 2));
}

sf::Vector2f Maths::normalize(sf::Vector2f v) {
    float mag = magnitude(v);
    return sf::Vector2f(v.x / mag, v.y / mag);
}

bool Maths::isOverlapping(float minA, float maxA, float minB, float maxB) {
    return maxA >= minB && maxB >= minA;
}

sf::Vector2f Maths::perpendicular(sf::Vector2f v1, sf::Vector2f v2) {
    sf::Vector2f v = v2 - v1;
    return sf::Vector2f(-v.y, v.x);
}

void Maths::projectOnAxis(std::vector<sf::Vector2f> vertices, sf::Vector2f axis, float& min, float& max) {
    min = max = Maths::product(vertices[0], axis);

    for(auto vertex : vertices) {
        float projection = Maths::product(vertex, axis);
        if(projection < min) {
            min = projection;
        }
        if(projection > max) {
            max = projection;
        }
    }
}

