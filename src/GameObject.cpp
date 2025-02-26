#include "GameObject.hpp"

GameObject::GameObject(std::string name) {
    this->name = name;
    addComponent<Transform>(0, 0);
    addComponent<SpriteRenderer>();
}

void GameObject::addChild(std::shared_ptr<GameObject> child) {
    children.push_back(child);
}

bool GameObject::removeChild(std::shared_ptr<GameObject> child) {
    auto it = std::find_if(children.begin(), children.end(),
    [child](const std::shared_ptr<GameObject>& ptr) { return ptr == child; });

    if (it != children.end()) {
        children.erase(it);
        return true;
    }
    return false;
}

std::shared_ptr<GameObject> GameObject::findChildByName(std::string name) {
    auto it = std::find_if(children.begin(), children.end(),
    [name](const std::shared_ptr<GameObject>& ptr) { return ptr->getName() == name; });

    if (it != children.end()) {
        return *it;
    }
    return nullptr;
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
        if(Transformable* transformable = dynamic_cast<Transformable*>(component.get())){
            transformable->setPosition(transform->getPosition());
            transformable->setScale(transform->getScale());
            transformable->setRotation(transform->getRotation());
        }
    }
}

void GameObject::drawGizmos(sf::RenderWindow &window) {
    for (auto &component: components) {
        component->drawGizmos(window);
    }
}
