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

void SpriteRenderer::displayMenu() {
    ImGui::Text("SpriteRenderer component");

    if (ImGui::Button("Load texture ")) {
        ImGuiFileDialog::Instance()->OpenDialog("ChooseFileDlg", "Choose texture", ".png,.jpg", ".");
    }

    if (ImGuiFileDialog::Instance()->Display("ChooseFileDlg")) {
        if (ImGuiFileDialog::Instance()->IsOk()) {
            std::string filePath = ImGuiFileDialog::Instance()->GetFilePathName();
            loadTexture(filePath);
        }

        ImGuiFileDialog::Instance()->Close();
    }

    sf::Vector2f position = sprite.getPosition();
    sf::Vector2f scale = sprite.getScale();

    ImGui::Text("Transform component");

    ImGui::Text("x position");
    ImGui::InputFloat("###x", &position.x);

    ImGui::Text("y position");
    ImGui::InputFloat("###y", &position.y);

    ImGui::Text("scale x");
    ImGui::InputFloat("###scaleX", &scale.x);

    ImGui::Text("scale y");
    ImGui::InputFloat("###scaleY", &scale.y);

    sprite.setPosition(position);
    sprite.setScale(scale);
}
