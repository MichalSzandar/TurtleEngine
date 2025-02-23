#include "components/Transform.hpp"

Transform::Transform(float x, float y) {
    scale = sf::Vector2f(1.0f, 1.0f);
    position = sf::Vector2f(x, y);
    rotation = sf::Vector2f(0.0f, 0.0f);
}

std::type_index Transform::getType() const {
    return typeid(Transform);
}

void Transform::displayMenu() {

    ImGui::Text("Transform component");

    ImGui::Text("x position");
    ImGui::InputFloat("###x", &position.x);

    ImGui::Text("y position");
    ImGui::InputFloat("###y", &position.y);

    ImGui::Text("scale x");
    ImGui::InputFloat("###scaleX", &scale.x);

    ImGui::Text("scale y");
    ImGui::InputFloat("###scaleY", &scale.y);

    ImGui::Text("rotation x");
    ImGui::InputFloat("###rotationX", &rotation.x);

    this->position = position;
    this->scale = scale;
}

float Transform::getX()
{
    return position.x;
}

void Transform::setX(float x) {
    position.x = x;
}

float Transform::getY() {
    return position.y;
}

void Transform::setY(float y) {
    this->position.y = y;
}

float Transform::getScaleX() {
    return scale.x;
}

void Transform::setScaleX(float scaleX) {
    scale.x = scaleX;
}

float Transform::getScaleY() {
    return scale.y;
}

void Transform::setScaleY(float scaleY) {
    scale.y = scaleY;
}

float Transform::getRotationX() {
    return rotation.x;
}

void Transform::setRotationX(float rotateX) {
    rotation.x = rotateX;
}

void Transform::setPosition(sf::Vector2f position) {
    this->position = position;
}

void Transform::setScale(sf::Vector2f scale) {
    this->scale = scale;
}

void Transform::setRotation(sf::Vector2f rotation) {
    this->rotation = rotation;
}

void Transform::drawGizmos(sf::RenderWindow &window) {
    
}
