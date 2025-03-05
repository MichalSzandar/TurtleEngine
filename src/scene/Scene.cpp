#include "scene/Scene.hpp"

Scene::Scene() {
    gameObjects = std::vector<std::shared_ptr<GameObject>>();   
    std::shared_ptr<GameObject> camera = std::make_shared<GameObject>("MainCamera");
    camera->addComponent<Camera>(sf::Vector2f(0, 0), sf::Vector2f(800, 600), 0, 1);
    mainCamera = camera->findComponent<Camera>();
    addGameObject(camera);

    gameView.create(800, 600);
}

bool Scene::addGameObject(std::shared_ptr<GameObject> obj) {
    gameObjects.push_back(obj);
    return true;
}

std::shared_ptr<GameObject> Scene::createEmptyObject() {
    std::string name = "obj" + std::to_string(gameObjects.size());
    gameObjects.push_back(std::make_shared<GameObject>(name)); 
    return gameObjects.back();
}

bool Scene::removeGameObject(std::shared_ptr<GameObject> obj) {
    gameObjects.erase(std::remove(gameObjects.begin(), gameObjects.end(), obj), gameObjects.end());
    return true;
}

std::shared_ptr<GameObject> Scene::findGameObjectByName(std::string name) {
    for (auto object : gameObjects)  {
        if (object->getName() == name) {
            return object;
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

    gameView.display();
}

void Scene::applyCamera(sf::RenderWindow &window) {
    window.setView(mainCamera->getView());
}

size_t Scene::getNumOfObjects()
{
    return gameObjects.size();
}