#ifndef COMPONENT_H
#define COMPONENT_H

#include <typeindex>

class Component {
    public:
    ~Component() = default;
    virtual std::type_index getType() const = 0;
};

#endif