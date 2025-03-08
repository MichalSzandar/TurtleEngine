#ifndef SPRITERENDERER_HPP
#define SPRITERENDERER_HPP

#include "Transformable.hpp"
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

/**
 * @class SpriteRenderer
 * @brief A component that renders a sprite.
 */
class SpriteRenderer : public Transformable {
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

        // Transformable --------------------------------
        void setPosition(sf::Vector2f position) override;
        void setScale(sf::Vector2f scale) override;
        void setRotation(sf::Vector2f rotation) override;
        void setTranslate(sf::Vector2f translate) override;
        //-----------------------------------------------

        void drawGizmos(sf::RenderWindow &window) override;
};

#endif