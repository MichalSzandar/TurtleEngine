#include "components/SphereCollider.hpp"
#include <iostream>

SphereCollider::SphereCollider() {
    position = sf::Vector2f(0, 0);
    scale = sf::Vector2f(1, 1);
    rotation = sf::Vector2f(0, 0);
    translate = sf::Vector2f(0, 0);

    radius = 0.0f;
    bounds = sf::CircleShape();
    bounds.setFillColor(sf::Color::Transparent);
    bounds.setOutlineColor(sf::Color::Red);
    bounds.setOutlineThickness(1.0f);
    bounds.setOrigin(radius, radius); 
}

SphereCollider::SphereCollider(float radius) {
    position = sf::Vector2f(0, 0);
    scale = sf::Vector2f(1, 1);
    rotation = sf::Vector2f(0, 0);
    translate = sf::Vector2f(0, 0);

    this->radius = radius;
    bounds = sf::CircleShape(radius);
    bounds.setFillColor(sf::Color::Transparent);
    bounds.setOutlineColor(sf::Color::Red);
    bounds.setOutlineThickness(1.0f);
    bounds.setOrigin(radius, radius); 
}

std::type_index SphereCollider::getType() const {
    return typeid(SphereCollider);
}

void SphereCollider::displayMenu() {
    ImGui::Text("SphereCollider component");

    ImGui::Text("translate x");
    ImGui::InputFloat("###x_spherecollider", &translate.x);

    ImGui::Text("translate y");
    ImGui::InputFloat("###y_spherecollider", &translate.y);

    ImGui::Text("radius");
    ImGui::InputFloat("###radius_spherecollider", &radius);

    bounds.setRadius(radius);
    bounds.setPosition(position.x + translate.x, position.y + translate.y);
    bounds.setOrigin(radius, radius);
}

void SphereCollider::setPosition(sf::Vector2f position) {
    this->position = position;
    bounds.setPosition(position.x + translate.x, position.y + translate.y);
}

void SphereCollider::setScale(sf::Vector2f scale) {
    bounds.setScale(scale);
    this->scale = scale;
}

void SphereCollider::setRotation(sf::Vector2f rotation) {
    bounds.setRotation(rotation.x);
    this->rotation = rotation;
}

void SphereCollider::setTranslate(sf::Vector2f translate) {
    this->translate = translate;
    bounds.setPosition(position.x + translate.x, position.y + translate.y);
}

void SphereCollider::drawGizmos(sf::RenderWindow &window) {
    window.draw(bounds);
}

sf::CircleShape SphereCollider::getBounds() const {
    return bounds;
}

float SphereCollider::getRadius() const {
    return bounds.getRadius();
}

void SphereCollider::setRadius(float radius) {
    this->radius = radius;
    bounds.setRadius(radius);
    bounds.setOrigin(radius, radius);
    bounds.setPosition(position.x + translate.x, position.y + translate.y);
}

bool SphereCollider::intersectsWith(BoxCollider *collider) {
    sf::RectangleShape box = collider->getBounds();
    sf::Vector2f boxPosition = box.getPosition();
    sf::Vector2f boxSize = box.getSize();
    sf::Vector2f boxHalfSize = boxSize / 2.0f;
    sf::Vector2f boxCenter = boxPosition + boxHalfSize;

    sf::Vector2f sphereCenter = bounds.getPosition();
    float sphereRadius = bounds.getRadius();

    // Calculate the closest point on the box to the sphere center
    sf::Vector2f closestPoint;
    closestPoint.x = std::max(boxPosition.x, std::min(sphereCenter.x, boxPosition.x + boxSize.x));
    closestPoint.y = std::max(boxPosition.y, std::min(sphereCenter.y, boxPosition.y + boxSize.y));

    // Calculate the distance from the sphere center to the closest point
    float distance = std::sqrt(std::pow(closestPoint.x - sphereCenter.x, 2) + std::pow(closestPoint.y - sphereCenter.y, 2));

    // Check if the distance is less than or equal to the sphere radius
    return distance <= sphereRadius;
}

bool SphereCollider::intersectsWith(SphereCollider *collider) {
    if(Maths::distance(bounds.getPosition(), collider->getBounds().getPosition()) <= radius + collider->getRadius()) {
        return true;
    }
    return false;
}
