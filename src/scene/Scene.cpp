#include "scene/Scene.hpp"

bool Scene::addGameObject(std::shared_ptr<GameObject> obj) {
    gameObjects.push_back(obj);
    return true;
}

GameObject* Scene::createEmptyObject() {
    std::string name = "obj" + std::to_string(gameObjects.size());
    gameObjects.push_back(std::make_shared<GameObject>(name)); 
    return gameObjects.back().get();
}

bool Scene::removeGameObject(std::shared_ptr<GameObject> obj) {
    gameObjects.erase(std::remove(gameObjects.begin(), gameObjects.end(), obj), gameObjects.end());
    return true;
}

GameObject* Scene::findGameObjectByName(std::string name) {
    for (auto object : gameObjects)  {
        if (object->getName() == name) {
            return object.get();
        }
    }
    return nullptr;
}

void Scene::drawScene(sf::RenderWindow &window) {
    for (auto obj : gameObjects) {
        obj->update();
        window.draw(obj->findComponent<SpriteRenderer>()->getSprite());
    }

    for (auto obj : gameObjects) {
        obj->drawGizmos(window);
    }
}

size_t Scene::getNumOfObjects() {
    return gameObjects.size();
}