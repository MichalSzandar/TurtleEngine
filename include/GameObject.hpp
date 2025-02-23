#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include <unordered_set>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>
#include "components/Component.hpp"
#include "components/SpriteRenderer.hpp"
#include "components/Transform.hpp"
#include "components/BoxCollider.hpp"

class GameObject {
    private:
    std::vector<std::unique_ptr<GameObject>> children;
    std::string name;

    public:
    std::vector<std::unique_ptr<Component>> components; 
    GameObject(std::string name);
    GameObject() = default;
    ~GameObject() = default;

    template <typename T, typename... Args>
    void addComponent(Args&&... args) {
        components.push_back(std::make_unique<T>(std::forward<Args>(args)...));
    }

    template <typename T>
    bool removeComponent() {
        auto it = std::remove_if(components.begin(), components.end(), [](const std::unique_ptr<Component>& comp) {
            return comp->getType() == typeid(T);
        });

        if (it != components.end()) {
            components.erase(it, components.end());
            return true;
        }
        return false;
    }


    template <typename T>
    T* findComponent() {
        for (const auto& comp : components) {
            if (comp->getType() == typeid(T)) {
                return dynamic_cast<T*>(comp.get());
            }
        }
        return nullptr;
    }


    void addChild(std::unique_ptr<GameObject> child);

    bool removeChild(GameObject *child);

    std::string getName();
    void setName(std::string newName);

    void update();

    void drawGizmos(sf::RenderWindow &window);
};


#endif
