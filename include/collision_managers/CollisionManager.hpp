#ifndef COLLISIONMANAGER_HPP
#define COLLISIONMANAGER_HPP

#include "components/Collider.hpp"

/**
 * @class CollisionManager
 * @brief Abstract class for collision managers
 */
class CollisionManager {
    public:
    CollisionManager() = default;
    ~CollisionManager() = default;

    virtual void checkCollisions() = 0;
    virtual void addCollider(Collider* collider) = 0;
    virtual void removeCollider(Collider* collider) = 0;
    virtual void clearColliders() = 0;
};

#endif // COLLISIONMANAGER_HPP