#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <unordered_set>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>
#include "Component.h"

struct ComponentHash {
    std::size_t operator()(const std::unique_ptr<Component>& comp) const {
        return comp->getType().hash_code();
    }
};

struct ComponentEqual {
    bool operator()(const std::unique_ptr<Component>& a, const std::unique_ptr<Component>& b) const {
        return a->getType() == b->getType();
    }
};

class GameObject {
    private:
    std::unordered_set<std::unique_ptr<Component>, ComponentHash, ComponentEqual> components;
    std::vector<GameObject*> children;
    std::string name;

    public:
    ~GameObject() = default;

    template <typename T>
    void addComponent() {
        components.insert(std::make_unique<T>());
    }

    template <typename T>
    bool removeComponent() {
        auto it = std::find_if(components.begin(), components.end(), [](const std::unique_ptr<Component>& comp) {
            return comp->getType() == typeid(T);
        });
        if (it != components.end()) {
            components.erase(it);
            return true;
        }
        return false;
    }

    template <typename T>
    T* findComponent() {
        for (const auto& comp : components) {
            if (comp->getType() == typeid(T)) {
                return static_cast<T*>(comp.get());
            }
        }
        return nullptr;
    }

    void addChild(GameObject* child);
    bool removeChild(GameObject* child);

    std::string getName();
    void setName(std::string newName);
    
};

#endif
