#include "GameObject.h"

void GameObject::addChild(GameObject* child)
{
    children.push_back(child);
}

bool GameObject::removeChild(GameObject* child)
{
    for(int i = 0; i < children.size(); i++) {
        if(children.at(i) == child) {
            children.erase(children.begin() + i);
            return true;
        }
    }
    return false;
}

std::string GameObject::getName()
{
    return this->name;
}

void GameObject::setName(std::string newName)
{
    this->name = newName;
}
