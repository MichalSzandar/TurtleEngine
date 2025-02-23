#ifndef QUADTREENODE_HPP
#define QUADTREENODE_HPP

#include <vector>
#include <SFML/Graphics.hpp>
#include "components/Collider.hpp"

class QuadtreeNode {
    private:
    sf::FloatRect bounds;
    std::vector<Collider*> colliders;
    QuadtreeNode* children[4];
    int maxObjects;
    int maxLevels;
    int level; 

    void split();
    int getIndex(Collider* collider);

    public:
    QuadtreeNode(int level, sf::FloatRect bounds, int maxObjects, int maxLevels);
    ~QuadtreeNode();
    void clear();
    void insert(Collider* collider);
    void retrieve(std::vector<Collider*>& returnObjects, const sf::FloatRect& bounds);
};

#endif // QUADTREENODE_HPP