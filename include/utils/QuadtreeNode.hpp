#ifndef QUADTREENODE_HPP
#define QUADTREENODE_HPP

#include <vector>
#include <SFML/Graphics.hpp>
#include "components/Collider.hpp"

class QuadtreeNode {
    private:
    sf::FloatRect bounds;
    std::vector<Collider*> colliders;
    std::vector<QuadtreeNode*> children;
    int maxObjects;
    int maxLevels;
    int level; 

    void split();
    int getIndex(Collider* collider);

    public:
    QuadtreeNode() = default;
    QuadtreeNode(int level, sf::FloatRect bounds, int maxObjects, int maxLevels);
    ~QuadtreeNode();
    void clear();
    void insert(Collider* collider);
    void retrieve(std::vector<Collider*>& returnObjects, Collider* collider);
};

#endif // QUADTREENODE_HPP