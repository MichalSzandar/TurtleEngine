#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include <typeindex>
#include "ImGuiFileDialog-0.6.6.1/ImGuiFileDialog.h"
#include <SFML/Graphics.hpp>
#include <imgui/imgui.h>
#include <imgui-sfml/imgui-SFML.h>

class Component {
    public:
    ~Component() = default;
    virtual std::type_index getType() const = 0;
    virtual void displayMenu();
};

#endif