#ifndef MATHS_HPP
#define MATHS_HPP

#include <SFML/Graphics.hpp>    
#include <cmath>

class Maths {
    public:
        static float distance(sf::Vector2f v1, sf::Vector2f v2);
        static float product(sf::Vector2f v1, sf::Vector2f v2);
        static float distancePointToSegment(sf::Vector2f p, sf::Vector2f a, sf::Vector2f b);
        static float magnitude(sf::Vector2f v);
        static sf::Vector2f normalize(sf::Vector2f v);
        static bool isOverlapping(float minA, float maxA, float minB, float maxB);
        static sf::Vector2f perpendicular(sf::Vector2f v1, sf::Vector2f v2);
        static void projectOnAxis(std::vector<sf::Vector2f> vertices, sf::Vector2f axis, float& min, float& max);
};

#endif // MATHS_HPP