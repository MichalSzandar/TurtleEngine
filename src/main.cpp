#include <SFML/Graphics.hpp>
#include <imgui/imgui.h>
#include <imgui-sfml/imgui-SFML.h>
#include <scene/Scene.hpp>
#include <ImGuiFileDialog-0.6.6.1/ImGuiFileDialog.h>
#include "collision_managers/CollisionManager.hpp"
#include "collision_managers/QuadTreeCollisionManager.hpp"
#include <vector>
#include "utils/UtilVariables.hpp"
#include "scene/SceneEditor.hpp"

int main() {
    UtilVariables::configure();
    
    sf::RenderWindow window(sf::VideoMode(UtilVariables::windowWidth, UtilVariables::windowHeight), "TurtleEngine");
    window.setFramerateLimit(60);

    // Initialize ImGui
    ImGui::SFML::Init(window);
    
    SceneEditor sceneEditor(window);
    QuadTreeCollisionManager collisionManager(UtilVariables::windowWidth, UtilVariables::windowHeight, 5, 5);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            ImGui::SFML::ProcessEvent(window, event);
            if (event.type == sf::Event::Closed)
                window.close();
        }

        sf::Time dt = UtilVariables::deltaClock.restart();
        UtilVariables::deltaTime = dt.asSeconds();

        ImGui::SFML::Update(window, dt);

        sceneEditor.showSceneEditor();
        sceneEditor.showInspector(&collisionManager);

        collisionManager.checkCollisions();

        if(UtilVariables::isEditorView) {
            sceneEditor.handleEditorCameraInput(window);
        }
        
        window.clear();
        sceneEditor.renderViews(window);
        ImGui::SFML::Render(window);
        window.display();
    }

    ImGui::SFML::Shutdown();
    return 0;
}
