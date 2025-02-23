#include "utils/QuadtreeNode.hpp"

void QuadtreeNode::split() {
    float subWidth = bounds.width / 2;
    float subHeight = bounds.height / 2;
    float x = bounds.left;
    float y = bounds.top;

    children[0] = new QuadtreeNode(level + 1, sf::FloatRect(x + subWidth, y, subWidth, subHeight), maxObjects, maxLevels);
    children[1] = new QuadtreeNode(level + 1, sf::FloatRect(x, y, subWidth, subHeight), maxObjects, maxLevels);
    children[2] = new QuadtreeNode(level + 1, sf::FloatRect(x, y + subHeight, subWidth, subHeight), maxObjects, maxLevels);
    children[3] = new QuadtreeNode(level + 1, sf::FloatRect(x + subWidth, y + subHeight, subWidth, subHeight), maxObjects, maxLevels);
}

int QuadtreeNode::getIndex(Collider *collider) {
    return 0;
}

QuadtreeNode::QuadtreeNode(int level, sf::FloatRect bounds, int maxObjects, int maxLevels) {
    this->level = level;
    this->bounds = bounds;
    this->maxObjects = maxObjects;
    this->maxLevels = maxLevels;
    children[0] = nullptr;
    children[1] = nullptr;
    children[2] = nullptr;
    children[3] = nullptr;
}

QuadtreeNode::~QuadtreeNode() {
    clear();
}

void QuadtreeNode::clear() {
    colliders.clear();

    for (int i = 0; i < 4; i++) {
        if (children[i] != nullptr) {
            children[i]->clear();
            delete children[i];
            children[i] = nullptr;
        }
    }
}

void QuadtreeNode::insert(Collider *collider) {

}

void QuadtreeNode::retrieve(std::vector<Collider *> &returnObjects, const sf::FloatRect &bounds) {
    
}
