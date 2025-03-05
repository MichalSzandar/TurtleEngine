#ifndef SCENE_HPP
#define SCENE_HPP

#include <vector>
#include "../GameObject.hpp"
#include <SFML/Graphics.hpp>
#include "components/SpriteRenderer.hpp"
#include "components/Camera.hpp"

class Scene {
    public:
    Scene();
    ~Scene() = default;

    std::vector<std::shared_ptr<GameObject>> gameObjects;

    Camera* mainCamera;
    sf::RenderTexture gameView;

    bool removeGameObject(std::shared_ptr<GameObject> obj);

    bool addGameObject(std::shared_ptr<GameObject> obj);

    std::shared_ptr<GameObject> createEmptyObject();

    std::shared_ptr<GameObject> findGameObjectByName(std::string name);

    void drawScene(sf::RenderWindow& window);
    void applyCamera(sf::RenderWindow& window);

    size_t getNumOfObjects();
};

#endif