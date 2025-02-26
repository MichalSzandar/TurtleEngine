#include "components/SpriteRenderer.hpp"

SpriteRenderer::SpriteRenderer(const std::string &texturePath) {
    position = sf::Vector2f(0, 0);
    scale = sf::Vector2f(1, 1);
    rotation = sf::Vector2f(0, 0);
    translate = sf::Vector2f(0, 0);
    
    if (!texture.loadFromFile(texturePath)) {
        std::cerr << "failed to load texture: " << texturePath << std::endl;
    }
    sprite.setTexture(texture);
}

std::type_index SpriteRenderer::getType() const {
    return typeid(SpriteRenderer);
}

sf::Sprite SpriteRenderer::getSprite() const {
    return sprite;
}

sf::Texture SpriteRenderer::getTexture() const {
    return texture;
}

bool SpriteRenderer::loadTexture(const std::string &filePath) {
    if(texture.loadFromFile(filePath)) {
        sprite.setTexture(texture);
        return true;
    }
    return false;
}

void SpriteRenderer::displayMenu() {
    ImGui::Text("SpriteRenderer component");

    if (ImGui::Button("Load texture ")) {
        ImGuiFileDialog::Instance()->OpenDialog("ChooseFileDlg", "Choose texture", ".png,.jpg", ".");
    }

    if (ImGuiFileDialog::Instance()->Display("ChooseFileDlg")) {
        if (ImGuiFileDialog::Instance()->IsOk()) {
            std::string filePath = ImGuiFileDialog::Instance()->GetFilePathName();
            loadTexture(filePath);
            sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
        }

        ImGuiFileDialog::Instance()->Close();
    }
}

void SpriteRenderer::setPosition(sf::Vector2f position) {
    this->position = position;
    sprite.setPosition(position.x + translate.x, position.y + translate.y);
}

void SpriteRenderer::setScale(sf::Vector2f scale) {
    this->scale = scale;
    sprite.setScale(scale);
}

void SpriteRenderer::setRotation(sf::Vector2f rotation) {
    this->rotation = rotation;
    sprite.setRotation(rotation.x);
}

void SpriteRenderer::setTranslate(sf::Vector2f translate) {
    this->translate = translate;
    sprite.setPosition(position.x + translate.x, position.y + translate.y);
}

void SpriteRenderer::drawGizmos(sf::RenderWindow &window) {
}
