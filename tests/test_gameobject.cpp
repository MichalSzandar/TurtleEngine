#define CATCH_CONFIG_MAIN
#include "../include/catch.hpp"
#include "../include/GameObject.h"
#include "../include/components/Transform.h"

TEST_CASE("GameObject can add and retrieve components") {
    GameObject obj;
    obj.addComponent<Transform>(10, 20);

    Transform* transform = obj.findComponent<Transform>();
    REQUIRE(transform != nullptr);
    REQUIRE(transform->getX() == (float)10.0);
    REQUIRE(transform->getY() == (float)20.0);
}

TEST_CASE("GameObject can remove components") {
    GameObject obj;
    obj.addComponent<Transform>(10, 20);
    obj.removeComponent<Transform>();

    REQUIRE(obj.findComponent<Transform>() == nullptr);
}
