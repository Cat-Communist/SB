#include "Classes.h"
#include <iostream>


int screen = static_cast<int>(screens::MainMenu);
sf::Font arial("FONTS/arialmt.ttf");

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 850, 900 }), "SeaBattle");
    while (window.isOpen())
    {
        //TODO: Events onMouseClick on different items of menu (screen must be changed then)

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
                
                sf::Vector2f btn_size = { 360.f, 75.f };
                sf::Vector2f center = { 425.f, 450.f };
                sf::Vector2f step = { 0.f, 105.f };

                Button btn_PvP(btn_size, sf::Color(5, 89, 250, 1), sf::Color::Black);
                btn_PvP.setOrigin({ btn_size.x/2, btn_size.y/2 });
                btn_PvP.setPosition(center);
                btn_PvP.drawTo(window);

                Button btn_PvE(btn_size, sf::Color(5, 89, 250, 1), sf::Color::Black);
                btn_PvE.setOrigin({ btn_size.x / 2, btn_size.y / 2 });
                btn_PvE.setPosition(center + step);
                btn_PvE.drawTo(window);

                Button btn_Exit(btn_size, sf::Color(5, 89, 250, 1), sf::Color::Black);
                btn_Exit.setOrigin({ btn_size.x / 2, btn_size.y / 2 });
                btn_Exit.setPosition(center + step + step);
                btn_Exit.drawTo(window);

                break;
            }
            case static_cast<int>(screens::BattleField):
            {
                //old version of 
                Button bc1({ 49, 49 }, sf::Color::Red, sf::Color::White);
                bc1.setPosition({ 175, 175 });
                Button bc2({ 49, 49 }, sf::Color::Red, sf::Color::White);
                bc2.setPosition({ 225, 175 });
                sf::VertexArray lineGorizontal(sf::PrimitiveType::Lines, 11 * 2);
                sf::VertexArray lineVertical(sf::PrimitiveType::Lines, 11 * 2);
                int linePosGorizontal = 175;
                int linePosVertical = 175;
                for (int i = 0; i < 11; i++)
                {

                    lineGorizontal[i * 2].position = sf::Vector2f(175, linePosGorizontal);
                    lineGorizontal[i * 2 + 1].position = sf::Vector2f(675, linePosGorizontal);

                    lineGorizontal[i * 2].color = sf::Color::White;
                    lineGorizontal[i * 2 + 1].color = sf::Color::White;

                    linePosGorizontal += 50;
                }
                for (int i = 0; i < 11; i++)
                {

                    lineVertical[i * 2].position = sf::Vector2f(linePosVertical, 175);
                    lineVertical[i * 2 + 1].position = sf::Vector2f(linePosVertical, 675);

                    lineVertical[i * 2].color = sf::Color::White;
                    lineVertical[i * 2 + 1].color = sf::Color::White;

                    linePosVertical += 50;
                }
                      
                if (event->is<sf::Event::Closed>())
                    window.close();
                if (event->is<sf::Event::MouseMoved>())
                {
                    if (bc1.isMouseOver(window))
                    {
                        bc1.setBackColor(sf::Color::White);
                    }
                    else if (bc2.isMouseOver(window))
                    {
                        bc2.setBackColor(sf::Color::White);
                    }
                    else
                    {
                        bc1.setBackColor(sf::Color::Red);
                        bc2.setBackColor(sf::Color::Red);
                    }
                }
                    
                window.draw(lineGorizontal);
                window.draw(lineVertical);
                bc1.drawTo(window);
                bc2.drawTo(window);
               
                break;
            }
            case static_cast<int>(screens::EndGame):
            {
                break;
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