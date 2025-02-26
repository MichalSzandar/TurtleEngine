#ifndef MATHS_HPP
#define MATHS_HPP

#include <SFML/Graphics.hpp>    
#include <cmath>

class Maths {
    public:
        static float distance(sf::Vector2f v1, sf::Vector2f v2);
        static float length(sf::Vector2f v);
        static float product(sf::Vector2f v1, sf::Vector2f v2);
        static float distancePointToSegment(sf::Vector2f p, sf::Vector2f a, sf::Vector2f b);
        static float magnitude(sf::Vector2f v);
        static sf::Vector2f normalize(sf::Vector2f v);
};

#endif // MATHS_HPP