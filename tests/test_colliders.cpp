#include <catch2/catch_test_macros.hpp>
#include "components/Collider.hpp"
#include "components/BoxCollider.hpp"
#include "components/SphereCollider.hpp"
#include <SFML/Graphics.hpp>
#include <cmath>

TEST_CASE("test sphere-sphere collision") {
    SphereCollider sphere1(1.0f);
    SphereCollider sphere2(1.0f);
    sphere1.setPosition(sf::Vector2f(0.0f, 0.0f));
    sphere2.setPosition(sf::Vector2f(2.0f, 0.0f));
    REQUIRE(sphere1.intersects(&sphere2));
    sphere2.setPosition(sf::Vector2f(3.0f, 0.0f));
    REQUIRE_FALSE(sphere1.intersects(&sphere2));
    sphere2.setPosition(sf::Vector2f(1.0f, 0.0f));
    REQUIRE(sphere1.intersects(&sphere2));
}

TEST_CASE("test sphere-box collision") {
    SphereCollider sphere(1.0f);
    BoxCollider box(0, 0, 2, 2);
    sphere.setPosition(sf::Vector2f(0, 0));
    REQUIRE(sphere.intersects(&box));
    sphere.setPosition(sf::Vector2f(3, 0));
    REQUIRE(sphere.intersects(&box));
    sphere.setPosition(sf::Vector2f(2.5f, 0.0f));
    REQUIRE(sphere.intersects(&box));
}

TEST_CASE("test box-box collision") {
    BoxCollider box1(0, 0, 2, 2);
    BoxCollider box2(1, 1, 2, 2);
    REQUIRE(box1.intersects(&box2));
    box2.setPosition(sf::Vector2f(3, 3));
    REQUIRE_FALSE(box1.intersects(&box2));
    box2.setPosition(sf::Vector2f(2, 2));
    REQUIRE(box1.intersects(&box2));
}