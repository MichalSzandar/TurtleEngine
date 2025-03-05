#include "components/Camera.hpp"

Camera::Camera() {
    position = sf::Vector2f(0, 0);
    scale = sf::Vector2f(1, 1);
    rotation = sf::Vector2f(0, 0);
    translate = sf::Vector2f(0, 0);

    view = sf::View();
    zoom = 1.0f; 
}

Camera::Camera(sf::Vector2f position, sf::Vector2f size, float rotation, float zoom) {
    this->position = position;
    this->scale = size;
    this->rotation = sf::Vector2f(rotation, 0);
    this->translate = sf::Vector2f(0, 0);

    view = sf::View(position, size);
    this->zoom = zoom;
}

std::type_index Camera::getType() const {
    return typeid(Camera);
}

void Camera::displayMenu() {
    ImGui::Text("Camera component");

    ImGui::Text("position x");
    ImGui::InputFloat("###x_camera", &translate.x);

    ImGui::Text("position y");
    ImGui::InputFloat("###y_camera", &translate.y);

    ImGui::Text("size x");
    ImGui::InputFloat("###size_x_camera", &scale.x);

    ImGui::Text("size y");
    ImGui::InputFloat("###size_y_camera", &scale.y);

    ImGui::Text("rotation");
    ImGui::InputFloat("###rotation_camera", &rotation.x);

    ImGui::Text("zoom");
    ImGui::InputFloat("###zoom_camera", &zoom);

    view.setCenter(position + translate);
    view.setRotation(rotation.x);
    view.setSize(scale.x / zoom, scale.y / zoom);
}

void Camera::setPosition(sf::Vector2f position) {
    this->position = position;
    view.setCenter(position + translate);
}

void Camera::setScale(sf::Vector2f scale) {
    this->scale = scale;
    view.setSize(scale);
}

void Camera::setRotation(sf::Vector2f rotation) {
    this->rotation = rotation;
    view.setRotation(rotation.x);
}

void Camera::setTranslate(sf::Vector2f translate) {
    this->translate = translate;
    view.setCenter(position + translate);
}

void Camera::setZoom(float zoom) {
    this->zoom = zoom;
    view.zoom(zoom);
}

sf::View Camera::getView() const {
    return view;
}

float Camera::getZoom() const {
    return zoom;
}

void Camera::drawGizmos(sf::RenderWindow &window) {
    sf::RectangleShape rect;
    rect.setSize(view.getSize());
    rect.setOrigin(view.getSize() / 2.0f);
    rect.setPosition(view.getCenter()); 
    rect.setRotation(view.getRotation());
    rect.setFillColor(sf::Color::Transparent);
    rect.setOutlineColor(sf::Color::Green);
    rect.setOutlineThickness(1.0f);
    window.draw(rect);
}
