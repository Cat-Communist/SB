#pragma once
#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>

class Mouse
{
public:
    //mouse position
    float x, y;

    //states
    bool left_click;
    bool right_click;
    bool leftPress;
    bool leftRelease;
    bool rightPress;
    bool rightRelease;
    bool rightisDown;

public:
    void Update(sf::RenderWindow& window)
    {

        //reset states
        leftPress = false;
        leftRelease = false;
        rightPress = false;
        rightRelease = false;

        x = sf::Mouse::getPosition(window).x;
        y = sf::Mouse::getPosition(window).y;

        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        {
            if (!left_click)
                leftPress = true;
            left_click = true;
        }
        else
        {
            if (left_click)
                leftRelease = true;
            left_click = false;
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right))
        {
            if (!right_click)
            {
                rightPress = true;
                rightisDown = true;
            }
            else
            {
                rightPress = false;
                rightisDown = true;
            }
            right_click = true;
        }
        else
        {
            if (right_click)
            {
                rightRelease = true;
                rightisDown = false;
            }
            right_click = false;
        }

    }
};

class Ship
{
public:
    //position 
    float x = 0.f;
    float y = 0.f;

    //last valid position
    sf::Vector2f last;

    //size
    int decks; //amount of cells
    int height = 1;
    float cell = 50.f; //one cell size

    //offsets
    float offset_x = 0.f;
    float offset_y = 0.f;

    //states
    bool isDragged = false;
    bool wasClicked = false;
    sf::Clock collisionFlashClock; // Таймер для мигания красным цветом
    bool isCollisionFlash = false;

    //decor
    sf::Color color;
private:
    sf::RectangleShape rect;
public:
    //constructor
    Ship(int decks, sf::Vector2f pos, sf::Color col)
        : decks(decks), x(pos.x), y(pos.y), color(col), last(pos)
    {
        rect.setSize({ decks * cell, height * cell });
        rect.setFillColor(color);
        rect.setPosition({x, y});
    }

    bool isInside(float x, float y)
    {
        if (x > this->x && x < this->x + decks * cell
            && y > this->y && y < this->y + height * cell)
            return true;
        return false;
    }

    //makes shape draggable
    void Draggable(Mouse& mouse)
    {
        if (mouse.leftPress && isInside(mouse.x, mouse.y))
        {
            offset_x = mouse.x - x;
            offset_y = mouse.y - y;

            isDragged = true;
        }
        else if (mouse.leftRelease)
            isDragged = false;
        if (isDragged)
        {
            x = mouse.x - offset_x;
            y = mouse.y - offset_y;
        }
        rect.setPosition({ x,y });
    }

    //draws shape and refreshes its position 
    void Draw(sf::RenderWindow& window)
    {
        rect.setSize({ decks * cell, height * cell });
        rect.setFillColor(color);
        rect.setPosition({ x,y });
        window.draw(rect);
    }

    //swaps sides of a shape
    void swapSides(int& w, int& h)
    {
        int temp = w;
        w = h;
        h = temp;
    }

    //makes shape rotatable
    void Rotatable(Mouse& mouse)
    {
        if (!isDragged) //if not dragged
        {
            if (wasClicked)
            {
                swapSides(decks, height);
                wasClicked = false;
            }
            if (mouse.rightRelease && isInside(mouse.x, mouse.y))
            {
                swapSides(decks, height);
            }
        }
    }

    //gets origin of shape
    sf::Vector2f getOrigin()
    {
        return rect.getOrigin();
    }

    //sets position of shape
    void setPosition(sf::Vector2f pos)
    {
        x = pos.x;
        y = pos.y;
        rect.setPosition({ x,y });
    }

    //updating last valid position
    void updateLastValidPosition()
    {
        if (color == sf::Color(0, 170, 255))
        {
            last = { rect.getPosition().x, rect.getPosition().y };
        }
    }
    
    bool waiting = false;

    //Flash
    void wait()
    {
        color = sf::Color(255, 64, 64);
        waiting = true;
        sf::Clock cl;
        cl.restart();
        if (waiting && cl.getElapsedTime() >= sf::seconds(2))
        {
            waiting = false;
            color = sf::Color(0, 170, 255);
            std::cout << "it works\n";
        }
        std::cout << "clock: " << cl.getElapsedTime().asSeconds() << "\n";
    }

    // go back to last
    void revertToLastPosition() 
    {
        x = last.x;
        y = last.y;
        rect.setPosition(last); 
        color = sf::Color(0, 170, 255); 
    }
};

class BattleCell {
public:
    //position
    float x = 0.f;
    float y = 0.f;

    //size of button
    int button_size = 50.f;
public:
    BattleCell() = default;
    //cunstructor of the battlecel, setting initial size, background color and outline color
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
        x = pos.x;
        y = pos.y;
    }

    void setOrigin(sf::Vector2f pos)
    {
        button.setOrigin(pos);
    }

    sf::Vector2f getPosition()
    {
        return button.getPosition();
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

    bool MouseisInside(float x, float y)
    {
        if (x > this->x && x < this->x + button_size
            && y > this->y && y < this->y + button_size)
        {
            return true;
        }
        return false;
    }

    void Alignbutton(Mouse& mouse, Ship& rect)
    {
        if (rect.isDragged && MouseisInside(mouse.x, mouse.y))
        {
            if (rect.height >= rect.decks)
            {
                rect.setPosition(button.getPosition() - sf::Vector2f{ 0, floor(rect.offset_y / 50) * button_size });
            }
            else
                rect.setPosition(button.getPosition() - sf::Vector2f{ floor(rect.offset_x / 50) * button_size, 0 });
        }
    }
    //use only with battle_cell[0][0]
    bool checkBoundary(Ship& ship)
    {
        float global_border_x0 = button.getPosition().x;
        float global_border_y0 = button.getPosition().y;

        float global_border_x1 = global_border_x0 + 10 * button_size;
        float global_border_y1 = global_border_y0 + 10 * button_size;

        float ship_border_x1 = ship.x + ship.cell * ship.decks;
        float ship_border_y1 = ship.y + ship.cell * ship.height;


        if (ship.x < global_border_x0 || ship.y < global_border_y0
            || ship_border_x1 > global_border_x1 || ship_border_y1 > global_border_y1)
            return true;
        return false;
    }

    bool ShipisOn(Ship rect)
    {
        if (button.getPosition().x >= rect.x && button.getPosition().x < rect.x + rect.decks * rect.cell
            && button.getPosition().y >= rect.y && button.getPosition().y < rect.y + rect.height * rect.cell)
            return true;
        return false;
    }
private:
    sf::RectangleShape button;
    int index;
};

class Button {
public:
    //cunstructor of the btn setting initial size, background color and outline color
    Button() = default;
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

    sf::Vector2f getPosition()
    {
        return button.getPosition();
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

        float btnPosX = button.getPosition().x - button.getSize().x / 2;
        float btnPosY = button.getPosition().y - button.getSize().y / 2;

        float btnxPosWidth = btnPosX + button.getSize().x;
        float btnyPosWidth = btnPosY + button.getSize().y;

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
    FieldPlayer1,
    FieldPlayer2,
    BattlePlayer1,
    BattlePlayer2,
    EndGame
};

//functions
bool checkCollision(Ship* currentShip, const std::vector<Ship*>& otherShips) {
    for (const Ship* otherShip : otherShips) {
        if (currentShip == otherShip)
            continue;

        // Проверка пересечения (прямое наложение)
        bool isOverlapping =
            currentShip->x < otherShip->x + otherShip->decks * currentShip->cell &&
            currentShip->x + currentShip->decks * currentShip->cell > otherShip->x &&
            currentShip->y < otherShip->y + otherShip->height * currentShip->cell &&
            currentShip->y + currentShip->height * currentShip->cell > otherShip->y;

        if (isOverlapping) {
            return true;
        }

        // Проверка расстояния (минимум 1 клетка между кораблями)
        // Расширенная область проверки (текущий корабль + 1 клетка вокруг)
        float expandedLeft = currentShip->x - currentShip->cell;
        float expandedRight = currentShip->x + currentShip->decks * currentShip->cell + currentShip->cell;
        float expandedTop = currentShip->y - currentShip->cell;
        float expandedBottom = currentShip->y + currentShip->height * currentShip->cell + currentShip->cell;

        // Проверяем, попадает ли другой корабль в расширенную область
        bool isTooClose =
            otherShip->x < expandedRight &&
            otherShip->x + otherShip->decks * otherShip->cell > expandedLeft &&
            otherShip->y < expandedBottom &&
            otherShip->y + otherShip->height * otherShip->cell > expandedTop;

        if (isTooClose) {
            return true;
        }
    }
    return false;
}