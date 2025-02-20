#include "components/SpriteRenderer.hpp"

SpriteRenderer::SpriteRenderer(const std::string &texturePath) {
    if (!texture.loadFromFile(texturePath)) {
        std::cerr << "failed to load texture: " << texturePath << std::endl;
    }
    sprite.setTexture(texture);
}

std::type_index SpriteRenderer::getType() const {
    return typeid(SpriteRenderer);
}

sf::Sprite SpriteRenderer::getSprite() {
    return sprite;
}

sf::Texture SpriteRenderer::getTexture() {
    return texture;
}

bool SpriteRenderer::loadTexture(const std::string &filePath) {
    if(texture.loadFromFile(filePath)) {
        sprite.setTexture(texture);

        return true;
    }
    return false;
}
