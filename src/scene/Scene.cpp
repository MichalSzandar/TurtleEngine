#include "scene/Scene.hpp"

bool Scene::addGameObject(std::shared_ptr<GameObject> obj) {
    gameObjects.push_back(obj);
    return true;
}

GameObject* Scene::createEmptyObject() {
    gameObjects.push_back(std::make_shared<GameObject>("obj")); 
    return gameObjects.back().get(); // Pobieramy wskaźnik do nowego obiektu
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
        window.draw(obj->findComponent<SpriteRenderer>()->getSprite());
    }
}

size_t Scene::getNumOfObjects() {
    return gameObjects.size();
}