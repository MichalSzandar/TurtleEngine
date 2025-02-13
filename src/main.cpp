#include <SFML/Graphics.hpp>
#include <imgui/imgui.h>
#include <imgui-sfml/imgui-SFML.h>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "ImGui + SFML");
    window.setFramerateLimit(60);
    
    // Initialize ImGui
    ImGui::SFML::Init(window);

    sf::Clock deltaClock;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            ImGui::SFML::ProcessEvent(window, event); // Pass events to ImGui
            if (event.type == sf::Event::Closed)
                window.close();
        }

        ImGui::SFML::Update(window, deltaClock.restart());

        // GUI Code
        ImGui::Begin("GameObject Editor");
        if (ImGui::Button("Create GameObject")) {
            // TODO: Add a GameObject to your scene
        }
        ImGui::End();

        window.clear();
        
        // Draw your SFML game objects here

        ImGui::SFML::Render(window);
        window.display();
    }

    ImGui::SFML::Shutdown();
    return 0;
}
