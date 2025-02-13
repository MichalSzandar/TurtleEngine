#include "components/SpriteRenderer.hpp"

SpriteRenderer::SpriteRenderer(const std::string &texturePath)
{
    if (!texture.loadFromFile(texturePath)) {
        std::cerr << "failed to load texture: " << texturePath << std::endl;
    }
    sprite.setTexture(texture);
}

std::type_index SpriteRenderer::getType() const
{
    return typeid(SpriteRenderer);
}
