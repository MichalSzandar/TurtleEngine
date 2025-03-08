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

        /**
         * @brief displays inspector menu and list of scene objects
         */
        void showSceneEditor();

        /**
         * @brief function responsible for moving around the editor camera
         * @param window The window to handle input for
         */
        void handleEditorCameraInput(sf::RenderWindow &window);

        /**
         * @brief draws the editor scene (generates grid, gizmos and draws game objects)
         * @param window The window to draw the scene in
         */
        void drawEditorScene(sf::RenderWindow &window);

        /**
         * @brief draws the game scene (draws game objects and sets view to mainCamera view)
         * @param window The window to draw the scene in
         */
        void drawGameScene(sf::RenderWindow &window);

        /**
         * @brief draws a grid in the editor scene
         * @param window The window to draw the grid in
         */
        void drawGrid(sf::RenderWindow &window);

        /**
         * @brief shows the inspector for the selected game object
         * @param collisionManager The collision manager to add colliders to
         */
        void showInspector(CollisionManager* collisionManager);

        /**
         * @brief shows the component menu for the selected game object
         * @param collisionManager The collision manager to add colliders to
         */
        void showComponentMenu(CollisionManager* collisionManager);

        /**
         * @brief renders the scene editor view if UtilVariables::isEditorView is true, game view otherwise
         * @param window The window to render the views in
         */
        void renderViews(sf::RenderWindow &window);

        void setCurrentScene(Scene* scene);
        void setEditorCamera(sf::View editorCamera);
        Scene* getCurrentScene() const;
        sf::View getEditorCamera() const;

        sf::View editorCamera;
        Scene* currentScene;
        std::shared_ptr<GameObject> selectedGameObject = nullptr;
    
    private:
        bool drawGizmos = true;
};

#endif // SCENE_EDITOR_HPP