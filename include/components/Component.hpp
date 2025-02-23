#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include <typeindex>
#include "ImGuiFileDialog-0.6.6.1/ImGuiFileDialog.h"
#include <SFML/Graphics.hpp>
#include <imgui/imgui.h>
#include <imgui-sfml/imgui-SFML.h>

class Component {
    public:
    Component() = default;
    ~Component() = default;

    virtual std::type_index getType() const = 0;
    
    virtual void displayMenu() = 0;

    virtual void setPosition(sf::Vector2f position) = 0;
    virtual void setScale(sf::Vector2f scale) = 0;
    virtual void setRotation(sf::Vector2f rotation) = 0;

    virtual void drawGizmos(sf::RenderWindow &window) = 0;
};

#endif