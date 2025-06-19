#include "Classes.h"
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 850, 900 }), "BattleField");
    //battlefield
    BattleCell testBattleField[10][10];
    float positionX = 175;
    float positionY = 175;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            testBattleField[i][j] = BattleCell({ 49, 49 }, sf::Color::Black, sf::Color::White, 0);
        }
    }
    for (int i = 0; i < 10; ++i) {
        positionX = 175;
        for (int j = 0; j < 10; ++j) {
            testBattleField[i][j].setPosition({ positionX, positionY });
            positionX = positionX + 50;
        }
        positionY = positionY + 50;
    }
    positionY = 175;
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
                for (int i = 0; i < 10; ++i) {
                    for (int j = 0; j < 10; ++j) {
                        if (testBattleField[i][j].isMouseOver(window) && testBattleField[i][j].getIndex() == 0)
                        {
                            testBattleField[i][j].setBackColor(sf::Color::White);
                        }
                        else if (testBattleField[i][j].getIndex() == 0)
                        {
                            testBattleField[i][j].setBackColor(sf::Color::Black);
                        }
                    }
                }
            }
            if (event->is<sf::Event::MouseButtonPressed>())
            {
                for (int i = 0; i < 10; ++i) {
                    for (int j = 0; j < 10; ++j) {
                        if (testBattleField[i][j].isMouseOver(window))
                        {
                            if (testBattleField[i][j].getIndex() == 1)
                            {
                                testBattleField[i][j].setIndex(0);
                                testBattleField[i][j].setBackColor(sf::Color::Black);
                            }
                            else
                            {
                                testBattleField[i][j].setIndex(1);
                                testBattleField[i][j].setBackColor(sf::Color::Red);
                            }
                        }
                    }
                }
            }
        }

        window.clear();
        window.draw(lineGorizontal);
        window.draw(lineVertical);
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                testBattleField[i][j].drawTo(window);
            }
        }
        window.display();
    }
}