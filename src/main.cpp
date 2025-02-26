#include <SFML/Graphics.hpp>
#include <imgui/imgui.h>
#include <imgui-sfml/imgui-SFML.h>
#include <scene/Scene.hpp>
#include <ImGuiFileDialog-0.6.6.1/ImGuiFileDialog.h>
#include <components/Transform.hpp>
#include <components/SpriteRenderer.hpp>
#include <components/BoxCollider.hpp>
#include <components/SphereCollider.hpp>
#include "collision_managers/CollisionManager.hpp"
#include "collision_managers/QuadTreeCollisionManager.hpp"
#include <vector>

//ticks away the moments that make up a dull day
sf::Clock deltaClock;

//deltaClock in seconds between each clock restart
float deltaTime;

//vector of available scenes
std::vector<Scene*> scenes;

Scene* currentScene = nullptr;

std::shared_ptr<GameObject> selectedGameObject = nullptr;

QuadTreeCollisionManager collisionManager;

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

void showComponentMenu() {
    if (selectedGameObject == nullptr) return;

    if (ImGui::BeginPopup("AddComponent")) {
        if (ImGui::MenuItem("Transform")) {
            selectedGameObject->addComponent<Transform>(0, 0);
        }
        if (ImGui::MenuItem("SpriteRenderer")) {
            selectedGameObject->addComponent<SpriteRenderer>();
        }
        if (ImGui::MenuItem("BoxCollider")) {
            selectedGameObject->addComponent<BoxCollider>(0, 0, 0, 0);
            collisionManager.addCollider(selectedGameObject->findComponent<BoxCollider>());
        }
        if(ImGui::MenuItem("SphereCollider")) {
            selectedGameObject->addComponent<SphereCollider>(0);
            collisionManager.addCollider(selectedGameObject->findComponent<SphereCollider>());
        }
        ImGui::EndPopup();
    }
}

void showInspector() {
    if (selectedGameObject == nullptr) return;

    ImGui::Begin("Inspector");

    for (auto& component : selectedGameObject->components) {
        component->displayMenu();
    }

    if(ImGui::Button("Add Component")) {
        ImGui::OpenPopup("AddComponent");
    }

    showComponentMenu();

    ImGui::End();
}

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "ThomasEngine");
    window.setFramerateLimit(60);

    // Initialize ImGui
    ImGui::SFML::Init(window);

    collisionManager = QuadTreeCollisionManager(800, 600, 5, 5);

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

        collisionManager.checkCollisions();
        
        window.clear();
        currentScene->drawScene(window);
        ImGui::SFML::Render(window);
        window.display();
    }

    ImGui::SFML::Shutdown();
    return 0;
}
