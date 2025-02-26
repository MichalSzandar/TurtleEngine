#include "components/SphereCollider.hpp"
#include <iostream>

SphereCollider::SphereCollider() {
    radius = 0.0f;
    translateX = 0.0f;
    translateY = 0.0f;
    x = 0.0f;
    y = 0.0f;
    bounds = sf::CircleShape();
    bounds.setFillColor(sf::Color::Transparent);
    bounds.setOutlineColor(sf::Color::Red);
    bounds.setOutlineThickness(1.0f);
    bounds.setOrigin(radius, radius); 
}

SphereCollider::SphereCollider(float radius) {
    this->radius = radius;
    translateX = 0.0f;  
    translateY = 0.0f;
    x = 0.0f;
    y = 0.0f;
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
    ImGui::InputFloat("###x_spherecollider", &translateX);

    ImGui::Text("translate y");
    ImGui::InputFloat("###y_spherecollider", &translateY);

    ImGui::Text("radius");
    ImGui::InputFloat("###radius_spherecollider", &radius);

    bounds.setRadius(radius);
    bounds.setPosition(x + translateX, y + translateY);
    bounds.setOrigin(radius, radius);
}

sf::Vector2f SphereCollider::getPosition() {
    return bounds.getPosition();
}

void SphereCollider::setPosition(sf::Vector2f position) {
    x = position.x;
    y = position.y;
    bounds.setPosition(sf::Vector2f(x + translateX, y + translateY));
}

void SphereCollider::setScale(sf::Vector2f scale) {
    bounds.setScale(scale);
}

void SphereCollider::setRotation(sf::Vector2f rotation) {
    // Do nothing
}

void SphereCollider::drawGizmos(sf::RenderWindow &window) {
    window.draw(bounds);
}

void SphereCollider::setTranslateX(float translateX) {
    this->translateX = translateX;
    bounds.setPosition(x + translateX, bounds.getPosition().y);
}

void SphereCollider::setTranslateY(float translateY) {
    this->translateY = translateY;
    bounds.setPosition(bounds.getPosition().x, y + translateY);
}

sf::CircleShape SphereCollider::getBounds() const {
    return bounds;
}

float SphereCollider::getRadius() const
{
    return bounds.getRadius();
}

void SphereCollider::setRadius(float radius) {
    this->radius = radius;
    bounds.setRadius(radius);
    bounds.setOrigin(radius, radius);
    bounds.setPosition(x + translateX, y + translateY);
}

bool SphereCollider::intersectsWith(BoxCollider *collider)
{
    sf::FloatRect box = collider->getBounds();
    if(box.contains(bounds.getPosition())) {
        return true;
    }
    if(Maths::distancePointToSegment(bounds.getPosition(), sf::Vector2f(box.left, box.top), sf::Vector2f(box.left + box.width, box.top)) <= radius) {
        return true;
    }
    if(Maths::distancePointToSegment(bounds.getPosition(), sf::Vector2f(box.left, box.top), sf::Vector2f(box.left, box.top + box.height)) <= radius) {
        return true;
    }
    if(Maths::distancePointToSegment(bounds.getPosition(), sf::Vector2f(box.left + box.width, box.top), sf::Vector2f(box.left + box.width, box.top + box.height)) <= radius) {
        return true;
    }
    if(Maths::distancePointToSegment(bounds.getPosition(), sf::Vector2f(box.left, box.top + box.height), sf::Vector2f(box.left + box.width, box.top + box.height)) <= radius) {
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
