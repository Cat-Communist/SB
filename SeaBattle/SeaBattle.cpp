#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 850, 900 }), "BattleField");
    //battlefield
    class BattleCell
    {
    public:
        BattleCell()
        {

        }
        BattleCell(sf::Vector2f size, sf::Color bgColor, sf::Color olColor)
        {
            battlecell.setSize(size);
            battlecell.setFillColor(bgColor);
            battlecell.setOutlineColor(olColor);
            battlecell.setOutlineThickness(1.f);
        }

        void setBackColor(sf::Color color)
        {
            battlecell.setFillColor(color);
        }

        void setLineColor(sf::Color color)
        {
            battlecell.setOutlineColor(color);
        }

        void setPosition(sf::Vector2f pos)
        {
            battlecell.setPosition(pos);

            float xPos = (pos.x + battlecell.getSize().x / 2);
            float yPos = (pos.y + battlecell.getSize().y / 2);
        }

        void drawTo(sf::RenderWindow& window)
        {
            window.draw(battlecell);
        }

        bool isMouseOver(sf::RenderWindow &window)
        {
            int mouseX = sf::Mouse::getPosition(window).x;
            int mouseY = sf::Mouse::getPosition(window).y;

            float bcPosX = battlecell.getPosition().x;
            float bcPosY = battlecell.getPosition().y;

            float bcxPosWidth = battlecell.getPosition().x + battlecell.getSize().x;
            float bcyPosWidth = battlecell.getPosition().y + battlecell.getSize().y;

            if (mouseX < bcxPosWidth && mouseX > bcPosX && mouseY < bcyPosWidth && mouseY > bcPosY)
            {
                return true;
            }
            return false;
        }
    private:
        sf::RectangleShape battlecell;
    };


    BattleCell bc1({ 49, 49 }, sf::Color::Red, sf::Color::White);
    bc1.setPosition({ 175, 175 });
    BattleCell bc2({ 49, 49 }, sf::Color::Red, sf::Color::White);
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