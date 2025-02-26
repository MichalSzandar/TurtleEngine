#include "components/Collider.hpp"
#include "components/BoxCollider.hpp"
#include "components/SphereCollider.hpp"

bool Collider::intersects(Collider *collider) {
    if (auto box = dynamic_cast<BoxCollider*>(collider)) {
        return intersectsWith(box);
    } else if (auto sphere = dynamic_cast<SphereCollider*>(collider)) {
        return intersectsWith(sphere);
    }
    return false;
}