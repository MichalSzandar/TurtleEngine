#include "GameObject.hpp"

GameObject::GameObject(std::string name) {
    this->name = name;
    addComponent<Transform>(0, 0);
    addComponent<SpriteRenderer>();
}

void GameObject::addChild(std::unique_ptr<GameObject> child) {
    children.push_back(std::move(child));
}

bool GameObject::removeChild(GameObject* child) {
    auto it = std::find_if(children.begin(), children.end(),
    [child](const std::unique_ptr<GameObject>& ptr) { return ptr.get() == child; });

    if (it != children.end()) {
        children.erase(it);
        return true;
    }
    return false;
}

std::string GameObject::getName() {
    return this->name;
}

void GameObject::setName(std::string newName) {
    this->name = newName;
}

void GameObject::update() {
    Transform* transform = findComponent<Transform>();
    for (auto &component : components) {
        component->setPosition(sf::Vector2f(transform->getX(), transform->getY()));
        component->setScale(sf::Vector2f(transform->getScaleX(), transform->getScaleY()));
    }
}
