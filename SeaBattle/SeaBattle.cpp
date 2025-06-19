#include "Classes.h"
#include <iostream>


int screen = static_cast<int>(screens::MainMenu);

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 850, 900 }), "SeaBattle");
    while (window.isOpen())
    {
        while (std::optional event = window.pollEvent())
        {
            switch (screen)
            {
            case static_cast<int>(screens::MainMenu):
            {
                sf::Texture bg_texture("Textures/background_img.jpg");
                sf::Sprite bg_sprite(bg_texture);
                bg_sprite.scale({ 4.5, 5.f });
                window.draw(bg_sprite);
                
                Button btn_PvP({120.f, 50.f}, sf::Color(64, 64, 64, 120), sf::Color::Black);
                btn_PvP.setPosition({ 400.f, 400.f });
                btn_PvP.drawTo(window);
            }
            }

            //close Event
            if (event->is<sf::Event::Closed>())
                window.close();

            //refresh window
            window.display();
            window.clear(sf::Color::Black);
        }
    }

}