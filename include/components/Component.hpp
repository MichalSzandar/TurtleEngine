#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include <typeindex>
#include "ImGuiFileDialog-0.6.6.1/ImGuiFileDialog.h"
#include <SFML/Graphics.hpp>
#include <imgui/imgui.h>
#include <imgui-sfml/imgui-SFML.h>

/**
 * @class Component
 * @brief Abstract base class for all components in the game engine.
 */
class Component {
    public:
        Component() = default;
        ~Component() = default;

        virtual std::type_index getType() const = 0;
        
        /**
         * @brief Displays the ImGui menu for the component.
         */
        virtual void displayMenu() = 0;

        /**
         * @brief Draws the gizmos for the component in the given window.
         * @param window The window to draw the gizmos in.
         */
        virtual void drawGizmos(sf::RenderWindow &window) = 0;
};

#endif