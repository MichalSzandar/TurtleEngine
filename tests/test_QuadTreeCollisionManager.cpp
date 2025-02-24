#include <catch2/catch_test_macros.hpp>
#include "components/BoxCollider.hpp"
#include "collision_managers/QuadTreeCollisionManager.hpp"
#include "components/Collider.hpp"
#include "utils/QuadtreeNode.hpp"

/**TEST_CASE("QuadTreeCollisionManager can add and remove colliders") {
    QuadTreeCollisionManager manager;
    BoxCollider collider;
    REQUIRE_NOTHROW(manager.addCollider(&collider));
    REQUIRE_NOTHROW(manager.removeCollider(&collider));
}

TEST_CASE("QuadTreeCollisionManager can clear colliders") {
    QuadTreeCollisionManager manager;
    BoxCollider collider;
    REQUIRE_NOTHROW(manager.addCollider(&collider));
    REQUIRE_NOTHROW(manager.clearColliders());
}

TEST_CASE("QuadTreeCollisionManager can check collisions between box colliders") {
    QuadTreeCollisionManager manager;
    BoxCollider collider1(0, 0, 100, 100);
    BoxCollider collider2(50, 50, 100, 100);
    manager.addCollider(&collider1);
    manager.addCollider(&collider2);
    REQUIRE_NOTHROW(manager.checkCollisions());
}*/