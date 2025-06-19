#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class BattleCell {
public:
    BattleCell() = default;
    //cunstructor of the btn setting initial size, background color and outline color
    BattleCell(sf::Vector2f size, const sf::Color bgColor, sf::Color olColor, int index)
        : index(index)
    {
        button.setSize(size);
        button.setFillColor(bgColor);
        button.setOutlineColor(olColor);
        button.setOutlineThickness(1.f);
    }

    //setting the button background color
    void setBackColor(sf::Color color)
    {
        button.setFillColor(color);
    }

    //setting the button outline color
    void setLineColor(sf::Color color)
    {
        button.setOutlineColor(color);
    }

    //setting the position of the button
    void setPosition(sf::Vector2f pos)
    {
        button.setPosition(pos);

        float xPos = (pos.x + button.getSize().x / 2);
        float yPos = (pos.y + button.getSize().y / 2);
    }

    void setOrigin(sf::Vector2f pos)
    {
        button.setOrigin(pos);
    }

    //funtion to draw button
    void drawTo(sf::RenderWindow& window)
    {
        window.draw(button);
    }

    //check if mouse is over the button
    bool isMouseOver(sf::RenderWindow& window)
    {
        int mouseX = sf::Mouse::getPosition(window).x;
        int mouseY = sf::Mouse::getPosition(window).y;

        float btnPosX = button.getPosition().x;
        float btnPosY = button.getPosition().y;

        float btnxPosWidth = button.getPosition().x + button.getSize().x;
        float btnyPosWidth = button.getPosition().y + button.getSize().y;

        if (mouseX < btnxPosWidth && mouseX > btnPosX && mouseY < btnyPosWidth && mouseY > btnPosY)
        {
            return true;
        }
        return false;
    }

    void setIndex(int newIndex)
    {
        index = newIndex;
    }

    int getIndex() const
    {
        return index;
    }
private:
    sf::RectangleShape button;
    int index;
};

class Button {
public:
    //cunstructor of the btn setting initial size, background color and outline color
    Button(sf::Vector2f size, const sf::Color bgColor, sf::Color olColor)
    {
        button.setSize(size);
        button.setFillColor(bgColor);
        button.setOutlineColor(olColor);
        button.setOutlineThickness(1.f);
    }

    //setting the button background color
    void setBackColor(sf::Color color)
    {
        button.setFillColor(color);
    }

    //setting the button outline color
    void setLineColor(sf::Color color)
    {
        button.setOutlineColor(color);
    }

    //setting the position of the button
    void setPosition(sf::Vector2f pos)
    {
        button.setPosition(pos);

        float xPos = (pos.x + button.getSize().x / 2); //NOTE: Why? For what purpose?
        float yPos = (pos.y + button.getSize().y / 2);
    }

    void setOrigin(sf::Vector2f pos)
    {
        button.setOrigin(pos);
    }

    //funtion to draw button
    void drawTo(sf::RenderWindow& window)
    {
        window.draw(button);
    }

    //check if mouse is over the button
    bool isMouseOver(sf::RenderWindow& window)
    {
        int mouseX = sf::Mouse::getPosition(window).x;
        int mouseY = sf::Mouse::getPosition(window).y;

        float btnPosX = button.getPosition().x;
        float btnPosY = button.getPosition().y;

        float btnxPosWidth = button.getPosition().x + button.getSize().x;
        float btnyPosWidth = button.getPosition().y + button.getSize().y;

        if (mouseX < btnxPosWidth && mouseX > btnPosX && mouseY < btnyPosWidth && mouseY > btnPosY)
        {
            return true;
        }
        return false;
    }
private:
    sf::RectangleShape button;
};

enum class screens {
    MainMenu,
    BattleField,
    EndGame
};