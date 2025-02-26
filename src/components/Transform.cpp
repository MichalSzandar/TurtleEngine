#include "components/Transform.hpp"

Transform::Transform(float x, float y) {
    scale = sf::Vector2f(1.0f, 1.0f);
    position = sf::Vector2f(x, y);
    rotation = sf::Vector2f(0.0f, 0.0f);
    translate = sf::Vector2f(0.0f, 0.0f);
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

void Transform::setPosition(sf::Vector2f position) {
    this->position = position;
}

void Transform::setScale(sf::Vector2f scale) {
    this->scale = scale;
}

void Transform::setRotation(sf::Vector2f rotation) {
    this->rotation = rotation;
}

void Transform::setTranslate(sf::Vector2f translate) {
    this->translate = translate;
}

void Transform::drawGizmos(sf::RenderWindow &window)
{
}
