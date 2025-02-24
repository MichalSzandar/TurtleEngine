#ifndef SCENE_HPP
#define SCENE_HPP

#include <vector>
#include "../GameObject.hpp"
#include <SFML/Graphics.hpp>
#include "components/SpriteRenderer.hpp"

class Scene {

    public:
    std::vector<std::shared_ptr<GameObject>> gameObjects;

    bool removeGameObject(std::shared_ptr<GameObject> obj);

    bool addGameObject(std::shared_ptr<GameObject> obj);

    std::shared_ptr<GameObject> createEmptyObject();

    std::shared_ptr<GameObject> findGameObjectByName(std::string name);

    void drawScene(sf::RenderWindow& window);

    size_t getNumOfObjects();
};

#endif