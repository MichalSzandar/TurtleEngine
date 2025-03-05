#ifndef SCENE_EDITOR_HPP
#define SCENE_EDITOR_HPP

#include <scene/Scene.hpp>
#include <SFML/Graphics.hpp>
#include "utils/UtilVariables.hpp"
#include "collision_managers/CollisionManager.hpp"

class SceneEditor {
    public:
    SceneEditor() = default;
    SceneEditor(sf::RenderWindow &window);
    ~SceneEditor() = default;
    void showSceneEditor();
    void handleEditorCameraInput(sf::RenderWindow &window);
    void drawEditorScene(sf::RenderWindow &window);
    void drawGameScene(sf::RenderWindow &window);
    void drawGrid(sf::RenderWindow &window);
    void showInspector(CollisionManager* collisionManager);
    void showComponentMenu(CollisionManager* collisionManager);
    void setCurrentScene(Scene* scene);
    void setEditorCamera(sf::View editorCamera);
    Scene* getCurrentScene() const;
    sf::View getEditorCamera() const;

    sf::View editorCamera;
    Scene* currentScene;
    std::shared_ptr<GameObject> selectedGameObject = nullptr;

};

#endif // SCENE_EDITOR_HPP