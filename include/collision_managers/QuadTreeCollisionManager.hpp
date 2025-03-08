#ifndef QUADTREE_COLLISION_MANAGER_HPP
#define QUADTREE_COLLISION_MANAGER_HPP

#include "CollisionManager.hpp"
#include "utils/QuadtreeNode.hpp"
#include "components/Collider.hpp"
#include <vector>

/**
 * @class QuadTreeCollisionManager
 * @brief Manages collision detection using a quadtree structure.
 */
class QuadTreeCollisionManager : public CollisionManager {
    private:
    QuadtreeNode root; ///< The root node of the quadtree.
    std::vector<Collider*> colliders; ///< List of colliders managed by the quadtree.

    public:
    QuadTreeCollisionManager() = default;

    /**
     * @brief Parameterized constructor.
     * @param width The width of the quadtree.
     * @param height The height of the quadtree.
     * @param maxObjects The maximum number of objects per node.
     * @param maxLevels The maximum number of levels in the quadtree.
     */
    QuadTreeCollisionManager(float width, float height, int maxObjects, int maxLevels);

    ~QuadTreeCollisionManager() = default;

    /**
     * @brief Checks for collisions between colliders.
     */
    void checkCollisions() override;

    /**
     * @brief Adds a collider to the quadtree.
     * @param collider The collider to add.
     */
    void addCollider(Collider* collider) override;

    /**
     * @brief Removes a collider from the quadtree.
     * @param collider The collider to remove.
     */
    void removeCollider(Collider* collider) override;

    /**
     * @brief Clears all colliders from the quadtree.
     */
    void clearColliders() override;
};

#endif // QUADTREE_COLLISION_MANAGER_HPP