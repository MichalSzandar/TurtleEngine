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
    
    sf::Sprite getSprite() const;

    sf::Texture getTexture() const;
    bool loadTexture(const std::string &filePath);

    void displayMenu() override;

    void setPosition(sf::Vector2f position) override;
    void setScale(sf::Vector2f scale) override;
};

#endif