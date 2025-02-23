#include "components/SpriteRenderer.hpp"

SpriteRenderer::SpriteRenderer(const std::string &texturePath) {
    translateX   = 0;
    translateY   = 0;
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
    sprite.setPosition(position.x + translateX, position.y + translateY);
}
void SpriteRenderer::setScale(sf::Vector2f scale) {
    sprite.setScale(scale);
}

void SpriteRenderer::setRotation(sf::Vector2f rotation) {
    sprite.setRotation(rotation.x);
}

void SpriteRenderer::setTranslateX(float translateX) {
    this->translateX = translateX;
}

void SpriteRenderer::setTranslateY(float translateY) {
    this->translateY = translateY;
}

void SpriteRenderer::drawGizmos(sf::RenderWindow &window) {
}
