#ifndef SPRITERENDERER_H
#define SPRITERENDERER_H

#include "Component.hpp"
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

class SpriteRenderer : public Component {
    private:
    sf::Sprite sprite;
    sf::Texture texture;

    public:
    SpriteRenderer(const std::string& texturePath);
    std::type_index getType() const override;
};

#endif