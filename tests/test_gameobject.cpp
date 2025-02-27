#include <catch2/catch_test_macros.hpp>
#include "GameObject.hpp"
#include "components/Transform.hpp"
#include "components/SpriteRenderer.hpp"
#include "components/BoxCollider.hpp"

TEST_CASE("GameObject can add and retrieve components") {
    GameObject obj("test");

    Transform* transform = obj.findComponent<Transform>();
    transform->setPosition(sf::Vector2f(10.0f, 20.0f));
    REQUIRE(transform != nullptr);
    REQUIRE(transform->getPosition().x == 10.0f);
    REQUIRE(transform->getPosition().y == 20.0f);

    obj.addComponent<SpriteRenderer>();
    SpriteRenderer* renderer = obj.findComponent<SpriteRenderer>();
    REQUIRE(renderer != nullptr);

    obj.addComponent<BoxCollider>(100.0f, 200.0f, 100.0f, 200.0f);
    BoxCollider* collider = obj.findComponent<BoxCollider>();
    sf::RectangleShape bounds = collider->getBounds();
    REQUIRE(collider != nullptr);
    REQUIRE(bounds.getPosition().x == 100.0f);
    REQUIRE(bounds.getPosition().y == 200.0f);
    REQUIRE(bounds.getSize() == sf::Vector2f(100.0f, 200.0f));
}

TEST_CASE("GameObject can remove components") {
    GameObject obj("test");
    obj.removeComponent<Transform>();
    REQUIRE(obj.findComponent<Transform>() == nullptr);

    obj.removeComponent<SpriteRenderer>();
    REQUIRE(obj.findComponent<SpriteRenderer>() == nullptr);

    obj.addComponent<BoxCollider>(100.0f, 200.0f, 100.0f, 200.0f);
    REQUIRE(obj.findComponent<BoxCollider>() != nullptr);
    obj.removeComponent<BoxCollider>();
    REQUIRE(obj.findComponent<BoxCollider>() == nullptr);
}

TEST_CASE("GameObject can update components") {
    GameObject obj("test");
    obj.addComponent<Transform>(10.0f, 20.0f);
    obj.addComponent<SpriteRenderer>();
    obj.addComponent<BoxCollider>(100.0f, 200.0f, 100.0f, 200.0f);
    obj.update();
    Transform* transform = obj.findComponent<Transform>();
    SpriteRenderer* renderer = obj.findComponent<SpriteRenderer>();
    BoxCollider* collider = obj.findComponent<BoxCollider>();
    sf::RectangleShape bounds = collider->getBounds();
    REQUIRE(renderer->getSprite().getPosition() == transform->getPosition());
    REQUIRE(renderer->getSprite().getScale() == transform->getScale());
    REQUIRE(renderer->getSprite().getRotation() == transform->getRotation().x);
    REQUIRE(bounds.getPosition() == transform->getPosition());
}

TEST_CASE("GameObject can add and remove children") {
    GameObject obj("test");
    obj.addChild(std::make_shared<GameObject>("child"));
    REQUIRE(obj.findChildByName("child") != nullptr);
    obj.removeChild(obj.findChildByName("child"));
    REQUIRE(obj.findChildByName("child") == nullptr);
}
