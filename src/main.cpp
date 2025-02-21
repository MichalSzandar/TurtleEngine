#include <SFML/Graphics.hpp>
#include <imgui/imgui.h>
#include <imgui-sfml/imgui-SFML.h>
#include <scene/Scene.hpp>
#include <ImGuiFileDialog-0.6.6.1/ImGuiFileDialog.h>
#include <vector>

//ticks away the moments that make up a dull day
sf::Clock deltaClock;

//deltaClock in seconds between each clock restart
float deltaTime;

//vector of available scenes
std::vector<Scene*> scenes;

Scene* currentScene = nullptr;

GameObject* selectedGameObject = nullptr;

void createScene() {
    scenes.push_back(new Scene());
    currentScene = scenes.back();
}

void showSceneEditor() {
    if (currentScene == nullptr) {
        createScene();
    }

    ImGui::Begin("SceneEditor");

    if (ImGui::Button("Create empty")) {
        selectedGameObject = currentScene->createEmptyObject();
    }

    for (auto obj : currentScene->gameObjects) {
        if(obj == nullptr) continue;
        if (ImGui::Selectable(obj->getName().c_str(), selectedGameObject == currentScene->findGameObjectByName(obj->getName()))) {
            selectedGameObject = currentScene->findGameObjectByName(obj->getName());
        }
    }

    ImGui::End();
}

void showInspector() {
    if (selectedGameObject == nullptr) return;

    ImGui::Begin("Inspector");

    for (auto& component : selectedGameObject->components) {
        component->displayMenu();
    }

    ImGui::End();
}

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "ThomasEngine");
    window.setFramerateLimit(60);

    // Initialize ImGui
    ImGui::SFML::Init(window);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            ImGui::SFML::ProcessEvent(window, event);
            if (event.type == sf::Event::Closed)
                window.close();
        }

        sf::Time dt = deltaClock.restart();
        deltaTime = dt.asSeconds();

        ImGui::SFML::Update(window, dt);

        showSceneEditor();
        showInspector();

        if(currentScene != nullptr)
            currentScene->update();

        window.clear();
        currentScene->drawScene(window);
        ImGui::SFML::Render(window);
        window.display();
    }

    ImGui::SFML::Shutdown();
    return 0;
}
