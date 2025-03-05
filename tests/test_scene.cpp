#include <catch2/catch_test_macros.hpp>
#include "scene/Scene.hpp"
#include "GameObject.hpp"

TEST_CASE("Scene can add and remove GameObjects") {
    //by default scene creates a camera object so object count should be 1
    Scene scene;
    REQUIRE(scene.getNumOfObjects() == 1);

    //try adding new objects
    std::shared_ptr<GameObject> obj = std::make_shared<GameObject>("test");
    REQUIRE(scene.addGameObject(obj));
    REQUIRE(scene.getNumOfObjects() == 2);
    //try removing object
    REQUIRE(scene.removeGameObject(obj));
    REQUIRE(scene.getNumOfObjects() == 1);
}

TEST_CASE("Scene can create empty GameObjects") {
    Scene scene;
    std::shared_ptr<GameObject> obj = scene.createEmptyObject();
    REQUIRE(obj != nullptr);
    REQUIRE(scene.getNumOfObjects() == 2);
}

TEST_CASE("Scene can find GameObjects by name") {
    Scene scene;
    std::shared_ptr<GameObject> obj = std::make_shared<GameObject>("test");
    scene.addGameObject(obj);
    std::shared_ptr<GameObject> foundObj = scene.findGameObjectByName("test");
    REQUIRE(foundObj != nullptr);
    REQUIRE(foundObj->getName() == "test");
}