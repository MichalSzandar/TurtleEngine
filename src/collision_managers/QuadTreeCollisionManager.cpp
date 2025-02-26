#include "collision_managers/QuadTreeCollisionManager.hpp"
#include <iostream>

QuadTreeCollisionManager::QuadTreeCollisionManager(float width, float height, int maxObjects, int maxLevels) : root(0, sf::FloatRect(0, 0, width, height), maxObjects, maxLevels) {

}

void QuadTreeCollisionManager::checkCollisions() {
    root.clear();
    for (auto collider : colliders) {
        root.insert(collider);
    }
    for (auto collider : colliders) {
        std::vector<Collider*> returnObjects;
        root.retrieve(returnObjects, collider);
        for (auto returnObject : returnObjects) {
            if (collider != returnObject && collider->intersects(returnObject)) {
                std::cout << "Collision detected" << std::endl;
            }
        }
    }
}

void QuadTreeCollisionManager::addCollider(Collider *collider)  {
    colliders.push_back(collider);
}

void QuadTreeCollisionManager::removeCollider(Collider *collider) {
    colliders.erase(std::remove(colliders.begin(), colliders.end(), collider), colliders.end());
}

void QuadTreeCollisionManager::clearColliders() {
    colliders.clear();
}
