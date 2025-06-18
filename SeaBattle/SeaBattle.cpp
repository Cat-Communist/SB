#include "Classes.h"
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 850, 900 }), "BattleField");
    //battlefield
    /*CLEANED the code*/


    Button btn1({ 49, 49 }, sf::Color::Red, sf::Color::White);
    btn1.setPosition({ 175, 175 });
    Button btn2({ 49, 49 }, sf::Color::Red, sf::Color::White);
    btn2.setPosition({ 225, 175 });
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
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
            if (event->is<sf::Event::MouseMoved>())
            {
                if (btn1.isMouseOver(window))
                {
                    btn1.setBackColor(sf::Color::White);

                }
                else if (btn2.isMouseOver(window))
                {
                    btn2.setBackColor(sf::Color::White);
                }
                else
                {
                    btn1.setBackColor(sf::Color::Red);
                    btn2.setBackColor(sf::Color::Red);
                }
            }
            if (const auto* clicked = event->getIf<sf::Event::MouseButtonPressed>())
            {
                if (clicked->button == sf::Mouse::Button::Left && btn1.isMouseOver(window))
                    std::cout << "button 1 was clicked\n";
            }
        }

        window.clear();
        window.draw(lineGorizontal);
        window.draw(lineVertical);
        btn1.drawTo(window);
        btn2.drawTo(window);
        window.display();
    }
}