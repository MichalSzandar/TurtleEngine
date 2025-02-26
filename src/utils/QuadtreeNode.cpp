#include "utils/QuadtreeNode.hpp"

void QuadtreeNode::split() {
    float subWidth = bounds.width / 2.0f;
    float subHeight = bounds.height / 2.0f;
    float x = bounds.left;
    float y = bounds.top;

    children[0] = new QuadtreeNode(level + 1, sf::FloatRect(x + subWidth, y, subWidth, subHeight), maxObjects, maxLevels);
    children[1] = new QuadtreeNode(level + 1, sf::FloatRect(x, y, subWidth, subHeight), maxObjects, maxLevels);
    children[2] = new QuadtreeNode(level + 1, sf::FloatRect(x, y + subHeight, subWidth, subHeight), maxObjects, maxLevels);
    children[3] = new QuadtreeNode(level + 1, sf::FloatRect(x + subWidth, y + subHeight, subWidth, subHeight), maxObjects, maxLevels);
}

int QuadtreeNode::getIndex(Collider *collider) {
    int index = -1;
    float verticalMidpoint = bounds.left + bounds.width / 2.0f;
    float horizontalMidpoint = bounds.top + bounds.height / 2.0f;

    bool topQuadrant = collider->getPosition().y < horizontalMidpoint;
    bool bottomQuadrant = collider->getPosition().y >= horizontalMidpoint;

    if (collider->getPosition().x < verticalMidpoint) {
        if (topQuadrant) {
            index = 1;
        } else if (bottomQuadrant) {
            index = 2;
        }
    } else if (collider->getPosition().x >= verticalMidpoint) {
        if (topQuadrant) {
            index = 0;
        } else if (bottomQuadrant) {
            index = 3;
        }
    }

    return index;
}

QuadtreeNode::QuadtreeNode(int level, sf::FloatRect bounds, int maxObjects, int maxLevels) {
    this->level = level;
    this->bounds = bounds;
    this->maxObjects = maxObjects;
    this->maxLevels = maxLevels;
    children.resize(4, nullptr);
}

QuadtreeNode::~QuadtreeNode() {
    clear();
}

void QuadtreeNode::clear() {
    colliders.clear();

    for(auto child : children) {
        if(child != nullptr) {
            child->clear();
            delete child;
            child = nullptr;
        }
    }   
}

void QuadtreeNode::insert(Collider *collider) {
    if (children[0] != nullptr) {
        int index = getIndex(collider);

        if (index != -1) {
            children[index]->insert(collider);
            return;
        }
    }

    colliders.push_back(collider);

    if (colliders.size() > maxObjects && level < maxLevels) {
        if (children[0] == nullptr) {
            split();
        }

        auto it = colliders.begin();
        while (it != colliders.end()) {
            int index = getIndex(*it);
            if (index != -1) {
                children[index]->insert(*it);
                it = colliders.erase(it);
            } else {
                ++it;
            }
        }
    }
}

void QuadtreeNode::retrieve(std::vector<Collider *> &returnObjects, Collider* collider) {
    int index = getIndex(collider);
    if (index != -1 && children[0] != nullptr) {
        children[index]->retrieve(returnObjects, collider);
    }

    returnObjects.insert(returnObjects.end(), colliders.begin(), colliders.end());
}
