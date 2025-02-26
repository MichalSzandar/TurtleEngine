#include "components/BoxCollider.hpp"

BoxCollider::BoxCollider() {
    position = sf::Vector2f(0, 0);
    scale = sf::Vector2f(1, 1);
    rotation = sf::Vector2f(0, 0);
    translate = sf::Vector2f(0, 0);

    width = 0;
    height = 0;
    bounds = sf::FloatRect(0, 0, width, height);
}

BoxCollider::BoxCollider(float x, float y, float width, float height) {
    position = sf::Vector2f(x, y);
    scale = sf::Vector2f(1, 1);
    rotation = sf::Vector2f(0, 0);
    translate = sf::Vector2f(0, 0);
    this->width = width;
    this->height = height;
    bounds = sf::FloatRect(x, y, width, height);
}

std::type_index BoxCollider::getType() const {
    return typeid(BoxCollider);
}

void BoxCollider::displayMenu()
{
    ImGui::Text("BoxCollider component");

    ImGui::Text("translate x");
    ImGui::InputFloat("###x_collider", &translate.x);

    ImGui::Text("translate y");
    ImGui::InputFloat("###y_collider", &translate.y);

    ImGui::Text("width");
    ImGui::InputFloat("###width_collider", &width);

    ImGui::Text("height");
    ImGui::InputFloat("###height_collider", &height);

    bounds.height = height;
    bounds.width = width;
    bounds.left = position.x + translate.x;
    bounds.top = position.y + translate.y;
}

void BoxCollider::setPosition(sf::Vector2f position) {
    this->position = position;
    bounds.left = position.x + translate.x;
    bounds.top = position.y + translate.y;
}

void BoxCollider::setScale(sf::Vector2f scale) {
    bounds.width = width * scale.x;
    bounds.height = height * scale.y;
}

void BoxCollider::setRotation(sf::Vector2f rotation) {
    this->rotation = rotation;

    sf::Transform transform;
    transform.rotate(this->rotation.x, position.x + translate.x + width / 2, position.y + translate.y + height / 2);

    sf::FloatRect rotatedBounds = transform.transformRect(bounds);
    bounds.left = rotatedBounds.left;
    bounds.top = rotatedBounds.top;
    bounds.width = rotatedBounds.width;
    bounds.height = rotatedBounds.height;
}

void BoxCollider::setTranslate(sf::Vector2f translate) {
    this->translate = translate;
    bounds.left = position.x + translate.x;
    bounds.top = position.y + translate.y;
}

sf::FloatRect BoxCollider::getBounds() const {
    return bounds;
}

void BoxCollider::setBounds(float x, float y, float width, float height) {
    bounds = sf::FloatRect(x, y, width, height);
}

void BoxCollider::setBounds(sf::FloatRect bounds) {
    this->bounds = bounds;
}

void BoxCollider::drawGizmos(sf::RenderWindow &window) {
    sf::RectangleShape rect(sf::Vector2f(bounds.width, bounds.height));
    rect.setPosition(bounds.left, bounds.top);
    rect.setFillColor(sf::Color::Transparent);
    rect.setOutlineColor(sf::Color::Red);
    rect.setOutlineThickness(1.0f);
    window.draw(rect);
}

bool BoxCollider::intersectsWith(BoxCollider *collider) {
    if(bounds.intersects(collider->getBounds())) {
        return true;
    }
    return false;
}

bool BoxCollider::intersectsWith(SphereCollider *collider) {
    sf::CircleShape circle = collider->getBounds();
    if(bounds.contains(circle.getPosition())) {
        return true;
    }
    if(Maths::distancePointToSegment(circle.getPosition(), sf::Vector2f(bounds.left, bounds.top), sf::Vector2f(bounds.left + bounds.width, bounds.top)) <= collider->getRadius()) {
        return true;
    }
    if(Maths::distancePointToSegment(circle.getPosition(), sf::Vector2f(bounds.left, bounds.top), sf::Vector2f(bounds.left, bounds.top + bounds.height)) <= collider->getRadius()) {
        return true;
    }
    if(Maths::distancePointToSegment(circle.getPosition(), sf::Vector2f(bounds.left + bounds.width, bounds.top), sf::Vector2f(bounds.left + bounds.width, bounds.top + bounds.height)) <= collider->getRadius()) {
        return true;
    }
    if(Maths::distancePointToSegment(circle.getPosition(), sf::Vector2f(bounds.left, bounds.top + bounds.height), sf::Vector2f(bounds.left + bounds.width, bounds.top + bounds.height)) <= collider->getRadius()) {
        return true;
    }
    return false;
}
