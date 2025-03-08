#ifndef COLLIDER_HPP
#define COLLIDER_HPP    

#include "Transformable.hpp"
#include <cmath>
#include "utils/Maths.hpp"
#include <SFML/Graphics.hpp>
#include <typeindex>   

class BoxCollider;
class SphereCollider;

/**
 * @class Collider
 * @brief Abstract base class for all colliders in the game engine.
 */
class Collider : public Transformable {
    public:
        Collider() = default;
        ~Collider() = default;

        /**
         * @brief Returns true if this collider collides with another collider.
         * @param collider The collider to check for collision with.
         * @return true if there is a collision, false otherwise.
         */
        bool intersects(Collider *collider);
    
        virtual bool intersectsWith(BoxCollider *collider) = 0;
        virtual bool intersectsWith(SphereCollider *collider) = 0;
};

#endif // COLLIDER_HPP