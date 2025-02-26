#include <catch2/catch_test_macros.hpp>
#include "utils/Maths.hpp"
#include <SFML/Graphics.hpp>
#include <cmath>

TEST_CASE("test math distance") {
    REQUIRE(Maths::distance(sf::Vector2f(0, 0), sf::Vector2f(0, 0)) == 0.0f);
    REQUIRE(Maths::distance(sf::Vector2f(0, 0), sf::Vector2f(1, 0)) == 1.0f);
    REQUIRE(Maths::distance(sf::Vector2f(0, 0), sf::Vector2f(0, 1)) == 1.0f);
    REQUIRE(Maths::distance(sf::Vector2f(0, 0), sf::Vector2f(1, 1)) == std::sqrt(2.0f));
    REQUIRE(Maths::distance(sf::Vector2f(0, 0), sf::Vector2f(2, 2)) == std::sqrt(8.0f));
    REQUIRE(Maths::distance(sf::Vector2f(0, 0), sf::Vector2f(3, 4)) == 5.0f);
    REQUIRE(Maths::distance(sf::Vector2f(0, 0), sf::Vector2f(5, 12)) == 13.0f);
}

TEST_CASE("test distance point to segment") {
    //REQUIRE(Maths::distancePointToSegment(sf::Vector2f(0, 0), sf::Vector2f(0, 0), sf::Vector2f(0, 0)) == 0.0f);
    REQUIRE(Maths::distancePointToSegment(sf::Vector2f(0, 0), sf::Vector2f(0, 0), sf::Vector2f(1, 0)) == 0.0f);
    REQUIRE(Maths::distancePointToSegment(sf::Vector2f(0, 0), sf::Vector2f(0, 0), sf::Vector2f(0, 1)) == 0.0f);
    REQUIRE(Maths::distancePointToSegment(sf::Vector2f(0, 0), sf::Vector2f(0, 0), sf::Vector2f(1, 1)) == 0.0f);
    REQUIRE(Maths::distancePointToSegment(sf::Vector2f(0, 0), sf::Vector2f(1, 0), sf::Vector2f(2, 2)) == 1.0f);
    REQUIRE(Maths::distancePointToSegment(sf::Vector2f(0, 0), sf::Vector2f(-1, 1), sf::Vector2f(1, 1)) == 1.0f);
}