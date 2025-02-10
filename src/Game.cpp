#include "Game.h"

Game::Game() : window(sf::VideoMode(800, 600), "SFML Game") {}

void Game::run() {
    while (window.isOpen()) {
        processEvents();
        update();
        render();
    }
}

void Game::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

void Game::update() {
    // Update game logic here
}

void Game::render() {
    window.clear(sf::Color::Black);

    // Tworzymy prostokąt
    sf::RectangleShape rectangle(sf::Vector2f(200.f, 100.f));
    rectangle.setFillColor(sf::Color::Red);
    rectangle.setPosition(300.f, 250.f);

    // Rysujemy go na ekranie
    window.draw(rectangle);

    window.display();
}


