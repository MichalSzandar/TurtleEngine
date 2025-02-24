#ifndef COLLIDER_HPP
#define COLLIDER_HPP    

#include "Component.hpp"
#include <SFML/Graphics.hpp>
#include <typeindex>   

class Collider : public Component {
    public:
        Collider() = default;
        
        virtual void setTranslateX(float translateX) = 0;
        virtual void setTranslateY(float translateY) = 0;
};

#endif // COLLIDER_HPP