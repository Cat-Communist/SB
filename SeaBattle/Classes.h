#pragma once

#include <SFML/Graphics.hpp>
#include "Classes.h"

class BattleCell {
public:
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

    bool isMouseOver(sf::RenderWindow& window)
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