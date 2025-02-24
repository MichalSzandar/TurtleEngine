#ifndef QUADTREE_COLLISION_MANAGER_HPP
#define QUADTREE_COLLISION_MANAGER_HPP

#include "CollisionManager.hpp"
#include "utils/QuadtreeNode.hpp"
#include "components/Collider.hpp"
#include <vector>

class QuadTreeCollisionManager : public CollisionManager {
    private:
    QuadtreeNode* root;

    public:
    QuadTreeCollisionManager();
    ~QuadTreeCollisionManager();

    void checkCollisions() override;
    void addCollider(Collider* collider) override;
    void removeCollider(Collider* collider) override;
    void clearColliders() override;
};

#endif // QUADTREE_COLLISION_MANAGER_HPP