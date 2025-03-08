#ifndef UTIL_VARIABLES_HPP
#define UTIL_VARIABLES_HPP

#include <SFML/Graphics.hpp>

class UtilVariables {
    public:
        static sf::Clock deltaClock;
        static float deltaTime;
        static float moveSpeed;
        static float zoomSpeed;
        static bool isEditorView;
        static float windowHeight;
        static float windowWidth;
        static bool drawGizmos;
        static bool drawGrid;
        static void configure();
};

#endif // UTIL_VARIABLES_HPP