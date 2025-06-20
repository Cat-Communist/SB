#include "Classes.h"
#include <iostream>

int screen = static_cast<int>(screens::MainMenu);
sf::Font arial("FONTS/arialmt.ttf");

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 900, 950 }), "SeaBattle");
    BattleCell coordinateLetters = BattleCell({ 500, 49 }, sf::Color::Black, sf::Color::White, 0);
    coordinateLetters.setPosition({ 225, 175 });
    BattleCell coordinateNumbers = BattleCell({ 50, 500 }, sf::Color::Black, sf::Color::White, 0);
    coordinateNumbers.setPosition({ 175, 225 });
    BattleCell player1BattleField[10][10];
    BattleCell player2BattleField[10][10];
    float positionX = 225;
    float positionY = 225;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            player1BattleField[i][j] = BattleCell({ 49, 49 }, sf::Color::Black, sf::Color::White, 0);
        }
    }
    for (int i = 0; i < 10; ++i) {
        positionX = 225;
        for (int j = 0; j < 10; ++j) {
            player1BattleField[i][j].setPosition({ positionX, positionY });
            positionX = positionX + 50;
        }
        positionY = positionY + 50;
    }
    positionY = 225;
    positionX = 225;

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            player2BattleField[i][j] = BattleCell({ 49, 49 }, sf::Color::Black, sf::Color::White, 0);
        }
    }
    for (int i = 0; i < 10; ++i) {
        positionX = 225;
        for (int j = 0; j < 10; ++j) {
            player2BattleField[i][j].setPosition({ positionX, positionY });
            positionX = positionX + 50;
        }
        positionY = positionY + 50;
    }
    positionY = 225;
    positionX = 225;

    sf::Texture bg_texture("Textures/background_img.jpg");
    sf::Sprite bg_sprite(bg_texture);
    bg_sprite.scale({ 5, 5.5 });

    sf::Vector2f btn_size = { 360.f, 75.f };
    sf::Vector2f center = { 450.f, 475.f };
    sf::Vector2f step = { 0.f, 105.f };
    sf::Color btn_col_reg = sf::Color(5, 89, 250, 120);
    sf::Color btn_col_dark = sf::Color(5, 89, 250, 160);

    //setting buttons 
    Button btn_PvP(btn_size, btn_col_reg, sf::Color::Black);
    btn_PvP.setOrigin({ btn_size.x / 2, btn_size.y / 2 });
    btn_PvP.setPosition(center);

    Button btn_PvE(btn_size, btn_col_reg, sf::Color::Black);
    btn_PvE.setOrigin({ btn_size.x / 2, btn_size.y / 2 });
    btn_PvE.setPosition(center + step);

    Button btn_Exit(btn_size, btn_col_reg, sf::Color::Black);
    btn_Exit.setOrigin({ btn_size.x / 2, btn_size.y / 2 });
    btn_Exit.setPosition(center + step + step);

    //setting text
    sf::FloatRect txt_bounds;
    sf::Text txt_PvP(arial, "Player vs Player");
    txt_bounds = txt_PvP.getGlobalBounds();
    txt_PvP.setFillColor(sf::Color::Black);
    txt_PvP.setOrigin({ txt_bounds.getCenter().x, txt_bounds.getCenter().y });
    txt_PvP.setPosition(center);

    sf::Text txt_PvE(arial, "Player vs Computer");
    txt_bounds = txt_PvE.getGlobalBounds();
    txt_PvE.setFillColor(sf::Color::Black);
    txt_PvE.setOrigin({ txt_bounds.getCenter().x, txt_bounds.getCenter().y });
    txt_PvE.setPosition(center + step);

    sf::Text txt_Exit(arial, "Exit");
    txt_bounds = txt_Exit.getGlobalBounds();
    txt_Exit.setFillColor(sf::Color::Black);
    txt_Exit.setOrigin({ txt_bounds.getCenter().x, txt_bounds.getCenter().y });
    txt_Exit.setPosition(center + step + step);

    while (window.isOpen())
    {
        //TODO: Events onMouseClick on different items of menu (screen must be changed then)

        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
            switch (screen)
            {
                case static_cast<int>(screens::MainMenu):
                {
                    //handle events onMouse
                    if (btn_PvP.isMouseOver(window)) {
                        btn_PvP.setBackColor(sf::Color(btn_col_dark));
                        if (event->is<sf::Event::MouseButtonPressed>()) {
                            btn_PvP.invertBgCol(btn_col_dark);
                            screen = static_cast<int>(screens::BattleFieldPlayer1);
                        }
                    }

                    else if (btn_PvE.isMouseOver(window)) {
                        btn_PvE.setBackColor(sf::Color(btn_col_dark));
                    }

                    else if (btn_Exit.isMouseOver(window)) {
                        btn_Exit.setBackColor(sf::Color(btn_col_dark));
                    }

                    break;
                }
                case static_cast<int>(screens::BattleFieldPlayer1):
                {
                    if (event->is<sf::Event::MouseMoved>())
                    {
                        for (int i = 0; i < 10; ++i) {
                            for (int j = 0; j < 10; ++j) {
                                if (player1BattleField[i][j].isMouseOver(window) && player1BattleField[i][j].getIndex() == 0)
                                {
                                    player1BattleField[i][j].setBackColor(sf::Color::White);
                                }
                                else if (player1BattleField[i][j].getIndex() == 0)
                                {
                                    player1BattleField[i][j].setBackColor(sf::Color::Black);
                                }
                            }
                        }
                    }
                    if (event->is<sf::Event::MouseButtonPressed>())
                    {
                        for (int i = 0; i < 10; ++i) {
                            for (int j = 0; j < 10; ++j) {
                                if (player1BattleField[i][j].isMouseOver(window))
                                {
                                    if (player1BattleField[i][j].getIndex() == 1)
                                    {
                                        player1BattleField[i][j].setIndex(0);
                                        player1BattleField[i][j].setBackColor(sf::Color::Black);
                                    }
                                    else
                                    {
                                        player1BattleField[i][j].setIndex(1);
                                        player1BattleField[i][j].setBackColor(sf::Color::Red);
                                    }
                                }
                            }
                        }
                    }
                    break;
                }
                case static_cast<int>(screens::BattleFieldPlayer2):
                {
                    if (event->is<sf::Event::MouseMoved>())
                    {
                        for (int i = 0; i < 10; ++i) {
                            for (int j = 0; j < 10; ++j) {
                                if (player2BattleField[i][j].isMouseOver(window) && player2BattleField[i][j].getIndex() == 0)
                                {
                                    player2BattleField[i][j].setBackColor(sf::Color::White);
                                }
                                else if (player2BattleField[i][j].getIndex() == 0)
                                {
                                    player2BattleField[i][j].setBackColor(sf::Color::Black);
                                }
                            }
                        }
                    }
                    if (event->is<sf::Event::MouseButtonPressed>())
                    {
                        for (int i = 0; i < 10; ++i) {
                            for (int j = 0; j < 10; ++j) {
                                if (player2BattleField[i][j].isMouseOver(window))
                                {
                                    if (player2BattleField[i][j].getIndex() == 1)
                                    {
                                        player2BattleField[i][j].setIndex(0);
                                        player2BattleField[i][j].setBackColor(sf::Color::Black);
                                    }
                                    else
                                    {
                                        player2BattleField[i][j].setIndex(1);
                                        player2BattleField[i][j].setBackColor(sf::Color::Red);
                                    }
                                }
                            }
                        }
                    }
                    break;
                }
            }
        }
        window.clear();
        //help
        if (screen == static_cast<int>(screens::MainMenu))
        {
            window.draw(bg_sprite);
            btn_PvP.drawTo(window);
            btn_PvE.drawTo(window);
            btn_Exit.drawTo(window);
            window.draw(txt_PvP);
            window.draw(txt_PvE);
            window.draw(txt_Exit);
        }
        else if (screen == static_cast<int>(screens::BattleFieldPlayer1))
        {
            coordinateLetters.drawTo(window);
            coordinateNumbers.drawTo(window);
            for (int i = 0; i < 10; ++i) {
                for (int j = 0; j < 10; ++j) {
                    player1BattleField[i][j].drawTo(window);
                }
            }
        }
        else if (screen == static_cast<int>(screens::BattleFieldPlayer2))
        {
            coordinateLetters.drawTo(window);
            coordinateNumbers.drawTo(window);
            for (int i = 0; i < 10; ++i) {
                for (int j = 0; j < 10; ++j) {
                    player2BattleField[i][j].drawTo(window);
                }
            }
        }

        window.display();
    }
}