#include "components/BoxCollider.hpp"

BoxCollider::BoxCollider() {
    position = sf::Vector2f(0, 0);
    scale = sf::Vector2f(1, 1);
    rotation = sf::Vector2f(0, 0);
    translate = sf::Vector2f(0, 0);

    width = 0;
    height = 0;

    bounds = sf::RectangleShape();
    bounds.setSize(sf::Vector2f(width, height));
    bounds.setFillColor(sf::Color::Transparent);
    bounds.setOutlineColor(sf::Color::Red);
    bounds.setOutlineThickness(1.0f);
}

BoxCollider::BoxCollider(float x, float y, float width, float height) {
    position = sf::Vector2f(x, y);
    scale = sf::Vector2f(1, 1);
    rotation = sf::Vector2f(0, 0);
    translate = sf::Vector2f(0, 0);
    this->width = width;
    this->height = height;

    bounds = sf::RectangleShape();
    bounds.setSize(sf::Vector2f(width, height));
    bounds.setOrigin(width / 2, height / 2);
    bounds.setFillColor(sf::Color::Transparent);
    bounds.setOutlineColor(sf::Color::Red);
    bounds.setOutlineThickness(1.0f);
    bounds.setPosition(position.x + translate.x, position.y + translate.y);
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

    bounds.setSize(sf::Vector2f(width, height));
    bounds.setOrigin(width / 2, height / 2);
    bounds.setPosition(position.x + translate.x, position.y + translate.y);
}

void BoxCollider::setPosition(sf::Vector2f position) {
    this->position = position;
    bounds.setPosition(position.x + translate.x, position.y + translate.y);
}

void BoxCollider::setScale(sf::Vector2f scale) {
    bounds.setScale(scale);
    this->scale = scale;
}

void BoxCollider::setRotation(sf::Vector2f rotation) {
    this->rotation = rotation;
    bounds.setRotation(rotation.x);
}

void BoxCollider::setTranslate(sf::Vector2f translate) {
    this->translate = translate;
    bounds.setPosition(position.x + translate.x, position.y + translate.y);
}

sf::RectangleShape BoxCollider::getBounds() const {
    return bounds;
}

void BoxCollider::setBounds(float x, float y, float width, float height) {
    bounds = sf::RectangleShape(sf::Vector2f(width, height));
    bounds.setPosition(x, y);
    this->width = width;
    this->height = height; 
    this->position = sf::Vector2f(x, y);
}

void BoxCollider::setBounds(sf::FloatRect bounds) {
    this->bounds = sf::RectangleShape(sf::Vector2f(bounds.width, bounds.height));
    this->bounds.setPosition(bounds.left, bounds.top);
    this->width = bounds.width;
    this->height = bounds.height;
    this->position = sf::Vector2f(bounds.left, bounds.top);
}

std::vector<sf::Vector2f> BoxCollider::getVertices() const{
    std::vector<sf::Vector2f> corners;
    sf::Transform transform = bounds.getTransform();

    for(short i = 0; i < 4; i++) {
        corners.push_back(transform.transformPoint(bounds.getPoint(i)));
    }

    return corners;
}

void BoxCollider::drawGizmos(sf::RenderWindow &window)
{
    window.draw(bounds);
}

bool BoxCollider::intersectsWith(BoxCollider *collider) {
    std::vector<sf::Vector2f> vertices1 = getVertices();
    std::vector<sf::Vector2f> vertices2 = collider->getVertices();

    std::vector<sf::Vector2f> axes = {
        Maths::perpendicular(vertices1[0], vertices1[1]),
        Maths::perpendicular(vertices1[0], vertices1[3]),
        Maths::perpendicular(vertices2[1], vertices2[2]),
        Maths::perpendicular(vertices2[2], vertices2[3])
    };

    for(auto axis : axes) {
        float minA, maxA, minB, maxB;
        Maths::projectOnAxis(vertices1, axis, minA, maxA);
        Maths::projectOnAxis(vertices2, axis, minB, maxB);

        if(!Maths::isOverlapping(minA, maxA, minB, maxB)) {
            return false;
        }
    }

    return true;
}

bool BoxCollider::intersectsWith(SphereCollider *collider) {
    sf::CircleShape circle = collider->getBounds();

    sf::Vector2f boxPoints[4];
    for (int i = 0; i < 4; ++i) {
        boxPoints[i] = bounds.getTransform().transformPoint(bounds.getPoint(i));
    }


    if(Maths::distancePointToSegment(circle.getPosition(), boxPoints[0], boxPoints[1]) <= collider->getRadius()) {
        return true;
    }
    if(Maths::distancePointToSegment(circle.getPosition(), boxPoints[0], boxPoints[3]) <= collider->getRadius()) {
        return true;
    }
    if(Maths::distancePointToSegment(circle.getPosition(), boxPoints[1], boxPoints[2]) <= collider->getRadius()) {
        return true;
    }
    if(Maths::distancePointToSegment(circle.getPosition(), boxPoints[2], boxPoints[3]) <= collider->getRadius()) {
        return true;
    }

    return false;
}
