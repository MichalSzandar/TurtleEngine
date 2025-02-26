#ifndef COLLIDER_HPP
#define COLLIDER_HPP    

#include "Component.hpp"
#include <cmath>
#include "utils/Maths.hpp"
#include <SFML/Graphics.hpp>
#include <typeindex>   

class BoxCollider;
class SphereCollider;

class Collider : public Component {
    protected:
        float translateX, translateY, x, y;

    public:
        Collider() = default;
        ~Collider() = default;

        virtual sf::Vector2f getPosition() = 0;
        
        virtual void setTranslateX(float translateX) = 0;
        virtual void setTranslateY(float translateY) = 0;

        bool intersects(Collider *collider);
    
        virtual bool intersectsWith(BoxCollider *collider) = 0;
        virtual bool intersectsWith(SphereCollider *collider) = 0;

};

#endif // COLLIDER_HPP