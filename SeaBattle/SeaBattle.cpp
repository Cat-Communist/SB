#include "Classes.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 850, 900 }), "BattleField");
    //battlefield
    /*CLEANED the code*/


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
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
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
        }

        window.clear();
        window.draw(lineGorizontal);
        window.draw(lineVertical);
        bc1.drawTo(window);
        bc2.drawTo(window);
        window.display();
    }
}