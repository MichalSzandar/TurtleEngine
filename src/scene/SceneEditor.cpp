#include "scene/SceneEditor.hpp"

SceneEditor::SceneEditor(sf::RenderWindow &window) {
    currentScene = new Scene();
    editorCamera = window.getView();
}

void SceneEditor::showSceneEditor() {
    if (currentScene == nullptr) {
        currentScene = new Scene();
    }

    ImGui::Begin("SceneEditor");

    if (ImGui::Button("Create empty")) {
        selectedGameObject = currentScene->createEmptyObject();
    }

    if (ImGui::Button(UtilVariables::isEditorView ? "Switch to Game View" : "Switch to Editor View")) {
        UtilVariables::isEditorView = !UtilVariables::isEditorView;
    }

    for (auto obj : currentScene->gameObjects) {
        if(obj == nullptr) continue;
        if (ImGui::Selectable(obj->getName().c_str(), selectedGameObject == currentScene->findGameObjectByName(obj->getName()))) {
            selectedGameObject = currentScene->findGameObjectByName(obj->getName());
        }
    }

    ImGui::End();
}

void SceneEditor::handleEditorCameraInput(sf::RenderWindow &window) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        editorCamera.move(0, -UtilVariables::moveSpeed * UtilVariables::deltaTime);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        editorCamera.move(0, UtilVariables::moveSpeed * UtilVariables::deltaTime);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        editorCamera.move(-UtilVariables::moveSpeed * UtilVariables::deltaTime, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        editorCamera.move(UtilVariables::moveSpeed * UtilVariables::deltaTime, 0);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
        editorCamera.zoom(1.0f + UtilVariables::zoomSpeed * UtilVariables::deltaTime);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
        editorCamera.zoom(1.0f - UtilVariables::zoomSpeed * UtilVariables::deltaTime);
    }
}

void SceneEditor::drawEditorScene(sf::RenderWindow &window) {
    window.setView(editorCamera);

    drawGrid(window);
    currentScene->drawScene(window);
}

void SceneEditor::drawGameScene(sf::RenderWindow &window) {
    window.setView(currentScene->mainCamera->getView());
    currentScene->drawScene(window);
}

void SceneEditor::drawGrid(sf::RenderWindow &window) {
    const float gridSize = 0.10f*window.getView().getSize().x;
    const sf::Color gridColor = sf::Color(200, 200, 200, 100);

    sf::Vector2f viewSize = window.getView().getSize();
    sf::Vector2f viewCenter = window.getView().getCenter();
    sf::Vector2f viewTopLeft = viewCenter - viewSize / 2.0f;

    for (float x = viewTopLeft.x - fmod(viewTopLeft.x, gridSize); x < viewTopLeft.x + viewSize.x; x += gridSize) {
        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(x, viewTopLeft.y), gridColor),
            sf::Vertex(sf::Vector2f(x, viewTopLeft.y + viewSize.y), gridColor)
        };
        window.draw(line, 2, sf::Lines);
    }
    
    for (float y = viewTopLeft.y - fmod(viewTopLeft.y, gridSize); y < viewTopLeft.y + viewSize.y; y += gridSize) {
        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(viewTopLeft.x, y), gridColor),
            sf::Vertex(sf::Vector2f(viewTopLeft.x + viewSize.x, y), gridColor)
        };
        window.draw(line, 2, sf::Lines);
    }
}

void SceneEditor::showComponentMenu(CollisionManager *collisionManager)
{
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
            collisionManager->addCollider(selectedGameObject->findComponent<BoxCollider>());
        }
        if(ImGui::MenuItem("SphereCollider")) {
            selectedGameObject->addComponent<SphereCollider>(0);
            collisionManager->addCollider(selectedGameObject->findComponent<SphereCollider>());
        }
        ImGui::EndPopup();
    }
}

void SceneEditor::showInspector(CollisionManager* collisionManager) {
    if (selectedGameObject == nullptr) return;

    ImGui::Begin("Inspector");

    for (auto& component : selectedGameObject->components) {
        component->displayMenu();
    }

    if(ImGui::Button("Add Component")) {
        ImGui::OpenPopup("AddComponent");
    }

    showComponentMenu(collisionManager);

    ImGui::End();
}

void SceneEditor::setCurrentScene(Scene *scene) {
    currentScene = scene;
}

void SceneEditor::setEditorCamera(sf::View editorCamera) {
    this->editorCamera = editorCamera;
}

Scene *SceneEditor::getCurrentScene() const {
    return currentScene;
}

sf::View SceneEditor::getEditorCamera() const {
    return editorCamera;
}
