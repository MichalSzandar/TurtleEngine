#ifndef COLLIDER_HPP
#define COLLIDER_HPP    

#include "Transformable.hpp"
#include <cmath>
#include "utils/Maths.hpp"
#include <SFML/Graphics.hpp>
#include <typeindex>   

class BoxCollider;
class SphereCollider;

class Collider : public Transformable {
    public:
        Collider() = default;
        ~Collider() = default;

        bool intersects(Collider *collider);
    
        virtual bool intersectsWith(BoxCollider *collider) = 0;
        virtual bool intersectsWith(SphereCollider *collider) = 0;
};

#endif // COLLIDER_HPP