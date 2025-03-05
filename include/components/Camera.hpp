#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "Transformable.hpp"

class Camera : public Transformable{
    private:
        sf::View view;
        float zoom;

    public:
        Camera();
        Camera(sf::Vector2f position, sf::Vector2f size, float rotation, float zoom);
        ~Camera() = default;

        std::type_index getType() const override;

        void displayMenu() override;

        //Transformable --------------------------------  
        void setPosition(sf::Vector2f position) override;
        void setScale(sf::Vector2f scale) override;
        void setRotation(sf::Vector2f rotation) override;
        void setTranslate(sf::Vector2f translate) override;
        void setZoom(float zoom);
        //-----------------------------------------------

        sf::View getView() const;
        float getZoom() const;

        void drawGizmos(sf::RenderWindow &window) override;
};

#endif // CAMERA_HPP