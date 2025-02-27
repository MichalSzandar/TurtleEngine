#ifndef GAMESCRIPT_HPP
#define GAMESCRIPT_HPP

#include "Component.hpp"
#include <typeindex>

class GameScript : public Component {
    public:
        GameScript() = default;
        ~GameScript() = default;

        virtual std::type_index getType() const = 0;

        virtual void start() = 0;
        virtual void update() = 0;
        virtual void onTriggerEnter() = 0;
        virtual void onTriggerExit() = 0;
        virtual void onCollisionEnter() = 0;
        virtual void onCollisionExit() = 0;
};

#endif // GAMESCRIPT_HPP