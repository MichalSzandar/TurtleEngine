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
    if(Maths::distancePointToSegment(bounds.getPosition(), box.getPoint(0), box.getPoint(1)) <= radius) {
        return true;
    }
    if(Maths::distancePointToSegment(bounds.getPosition(), box.getPoint(1), box.getPoint(2)) <= radius) {
        return true;
    }
    if(Maths::distancePointToSegment(bounds.getPosition(), box.getPoint(2), box.getPoint(3)) <= radius) {
        return true;
    }
    if(Maths::distancePointToSegment(bounds.getPosition(), box.getPoint(0), box.getPoint(3)) <= radius) {
        return true;
    }
    return false;
}

bool SphereCollider::intersectsWith(SphereCollider *collider) {
    std::cout<<"sphere intersects with sphere: "<<std::endl;
    std::cout<<bounds.getPosition().x<<", "<<bounds.getPosition().y<<" , "<<radius<<std::endl;
    std::cout<<collider->getBounds().getPosition().x<<", "<<collider->getBounds().getPosition().y<<" , "<<collider->getRadius()<<std::endl;
    if(Maths::distance(bounds.getPosition(), collider->getBounds().getPosition()) <= radius + collider->getRadius()) {
        return true;
    }
    return false;
}
