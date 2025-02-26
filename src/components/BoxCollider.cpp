#include "components/BoxCollider.hpp"

BoxCollider::BoxCollider() {
    rotation = 0;
    translateX = 0; 
    translateY = 0;
    x = 0;
    y = 0;
    width = 0;
    height = 0;
    bounds = sf::FloatRect(x, y, width, height);
}

BoxCollider::BoxCollider(float x, float y, float width, float height) {
    translateX = 0;
    translateY = 0;
    rotation = 0;
    this->x = x;
    this->y = y;    
    this->width = width;
    this->height = height;
    bounds = sf::FloatRect(x, y, width, height);
}

std::type_index BoxCollider::getType() const{
    return typeid(BoxCollider);
}

void BoxCollider::displayMenu()
{
    ImGui::Text("BoxCollider component");

    ImGui::Text("translate x");
    ImGui::InputFloat("###x_collider", &translateX);

    ImGui::Text("translate y");
    ImGui::InputFloat("###y_collider", &translateY);

    ImGui::Text("width");
    ImGui::InputFloat("###width_collider", &width);

    ImGui::Text("height");
    ImGui::InputFloat("###height_collider", &height);

    bounds.height = height;
    bounds.width = width;
    bounds.left = x + translateX;
    bounds.top = y + translateY;
}

sf::Vector2f BoxCollider::getPosition() {
    return bounds.getPosition();
}
void BoxCollider::setPosition(sf::Vector2f position)
{
    x = position.x;
    y = position.y;
    bounds.left = x + translateX;
    bounds.top = y + translateY;
}

void BoxCollider::setScale(sf::Vector2f scale) {
    bounds.width = width * scale.x;
    bounds.height = height * scale.y;
}

void BoxCollider::setRotation(sf::Vector2f rotation) {
    this->rotation = rotation.x;

    // Calculate the rotated bounding box
    sf::Transform transform;
    transform.rotate(this->rotation, x + translateX + width / 2, y + translateY + height / 2);

    sf::FloatRect rotatedBounds = transform.transformRect(bounds);
    bounds.left = rotatedBounds.left;
    bounds.top = rotatedBounds.top;
    bounds.width = rotatedBounds.width;
    bounds.height = rotatedBounds.height;
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

void BoxCollider::setTranslateX(float translateX) {
    this->translateX = translateX;
    bounds.left = x + translateX;
}

void BoxCollider::setTranslateY(float translateY) {
    this->translateY = translateY;
    bounds.top = y + translateY;
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
