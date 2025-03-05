#include "utils/UtilVariables.hpp"

sf::Clock UtilVariables::deltaClock;
float UtilVariables::deltaTime = 0.0f;
float UtilVariables::moveSpeed = 200.0f;
float UtilVariables::zoomSpeed = 0.1f;
bool UtilVariables::isEditorView = true;

void UtilVariables::configure() {
    moveSpeed = 200.0f;
    zoomSpeed = 0.1f;
    isEditorView = true;
    deltaTime = 0.0f;
}