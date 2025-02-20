#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include <typeindex>

class Component {
    public:
    ~Component() = default;
    virtual std::type_index getType() const = 0;
};

#endif