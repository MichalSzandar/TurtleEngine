#include <catch2/catch_test_macros.hpp>
#include "components/Collider.hpp"
#include "components/BoxCollider.hpp"
#include "components/SphereCollider.hpp"
#include <SFML/Graphics.hpp>
#include <cmath>

TEST_CASE("SphereColliders are tangent") {
    SphereCollider sphere1(1.0f);
    SphereCollider sphere2(1.0f);
    sphere1.setPosition(sf::Vector2f(0.0f, 0.0f));
    sphere2.setPosition(sf::Vector2f(2.0f, 0.0f));

    REQUIRE(sphere1.intersects(&sphere2));
}

TEST_CASE("SphereColliders intersect with each other") {
    SphereCollider sphere1(1.0f);
    SphereCollider sphere2(1.0f);
    sphere1.setPosition(sf::Vector2f(0.0f, 0.0f));
    sphere2.setPosition(sf::Vector2f(1.0f, 0.0f));

    REQUIRE(sphere1.intersects(&sphere2));

    //sphere colliders occupy same space
    sphere1.setPosition(sf::Vector2f(0.0f, 0.0f));
    REQUIRE(sphere1.intersects(&sphere2));

    //sphere collider 2 is inside sphere collider 1
    sphere1.setRadius(2.0f);
    REQUIRE(sphere1.intersects(&sphere2));
}

TEST_CASE("SphereColliders do not intersect with each other") {
    SphereCollider sphere1(1.0f);
    SphereCollider sphere2(1.0f);
    sphere1.setPosition(sf::Vector2f(0.0f, 0.0f));
    sphere2.setPosition(sf::Vector2f(3.0f, 0.0f));

    REQUIRE_FALSE(sphere1.intersects(&sphere2));
}

TEST_CASE("BoxColliders are tangent") {
    BoxCollider box1(0, 0, 2, 2);
    BoxCollider box2(2, 0, 2, 2);
    REQUIRE(box1.intersects(&box2));

    box2.setPosition(sf::Vector2f(2, 2));
    REQUIRE(box1.intersects(&box2));
}

TEST_CASE("BoxColliders intersect with each other") {
    BoxCollider box1(0, 0, 2, 2);
    BoxCollider box2(1, 1, 2, 2);
    REQUIRE(box1.intersects(&box2));

    //box collider 2 is inside box collider 1
    box2.setScale(sf::Vector2f(0.25f, 0.25f)); //height = 0.5, width = 0.5
    REQUIRE(box1.intersects(&box2));

    //box colliders occupy same space
    box2.setPosition(sf::Vector2f(0, 0));
    box2.setScale(sf::Vector2f(1, 1));
    REQUIRE(box1.intersects(&box2));
}

TEST_CASE("BoxColliders do not intersect with each other") {
    BoxCollider box1(0, 0, 2, 2);
    BoxCollider box2(3, 3, 2, 2);
    REQUIRE_FALSE(box1.intersects(&box2));
}

TEST_CASE("BoxCollider is tangent with SphereCollider") {
    BoxCollider box(1, 0, 2, 2);
    SphereCollider sphere(1.0f);
    REQUIRE(sphere.intersects(&box));

    sphere.setPosition(sf::Vector2f(2, 0));
    REQUIRE(box.intersects(&sphere));
}

TEST_CASE("BoxCollider intersects with SphereCollider") {
    BoxCollider box(0, 0, 2, 2);
    SphereCollider sphere(1.0f);
    REQUIRE(box.intersects(&sphere));

    sphere.setPosition(sf::Vector2f(2, 0));
    REQUIRE(box.intersects(&sphere));

    sphere.setPosition(sf::Vector2f(2.5f, 0.0f));
    REQUIRE(sphere.intersects(&box));
}

TEST_CASE("BoxCollider does not intersect with SphereCollider") {
    BoxCollider box(0, 0, 2, 2);
    SphereCollider sphere(1.0f);
    sphere.setPosition(sf::Vector2f(3.1f, 0));
    REQUIRE_FALSE(box.intersects(&sphere));
}