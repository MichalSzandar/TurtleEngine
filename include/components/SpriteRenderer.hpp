#ifndef SPRITERENDERER_HPP
#define SPRITERENDERER_HPP

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
    SpriteRenderer() = default;
    std::type_index getType() const override;
    sf::Sprite getSprite();
    sf::Texture getTexture();
    bool loadTexture(const std::string &filePath);
};

#endif