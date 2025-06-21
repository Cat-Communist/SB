#include "Classes.h"
#include <iostream>

int screen = static_cast<int>(screens::MainMenu);
sf::Font arial("FONTS/arialmt.ttf");

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 900, 950 }), "SeaBattle");
    Button coordinateLetters[10];
    Button coordinateNumbers[10];
    BattleCell player1Field[10][10];
    BattleCell player2Field[10][10];
    BattleCell player1BattleField[10][10];
    BattleCell player2BattleField[10][10];
    float positionX = 225;
    float positionY = 225;
    // Координаты
    for (int i = 0; i < 10; ++i) {
        coordinateLetters[i] = Button({ 50, 50 }, sf::Color(25, 25, 25), sf::Color::White);
        coordinateLetters[i].setPosition({positionX, 175});

        positionX = positionX + 50;
    }
    positionX = 225;
    for (int i = 0; i < 10; ++i) {
        coordinateNumbers[i] = Button({ 50, 50 }, sf::Color(25, 25, 25), sf::Color::White);
        coordinateNumbers[i].setPosition({ 175, positionY });
        positionY = positionY + 50;
    }
    positionY = 225;
    // Поле Игрока 1 этапа "Расстановка"
    positionX = 225;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            player1Field[i][j] = BattleCell({ 50, 50 }, sf::Color::Black, sf::Color::White, 0);
        }
    }
    for (int i = 0; i < 10; ++i) {
        positionX = 225;
        for (int j = 0; j < 10; ++j) {
            player1Field[i][j].setPosition({ positionX, positionY });
            positionX = positionX + 50;
        }
        positionY = positionY + 50;
    }
    positionY = 225;
    positionX = 225;
    // Поле Игрока 2 этапа "Расстановка"
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            player2Field[i][j] = BattleCell({ 50, 50 }, sf::Color::Black, sf::Color::White, 0);
        }
    }
    for (int i = 0; i < 10; ++i) {
        positionX = 225;
        for (int j = 0; j < 10; ++j) {
            player2Field[i][j].setPosition({ positionX, positionY });
            positionX = positionX + 50;
        }
        positionY = positionY + 50;
    }
    positionY = 225;
    positionX = 225;
    // Поле Игрока 1 этапа "Бой"
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            player1BattleField[i][j] = BattleCell({ 50, 50 }, sf::Color::Black, sf::Color::White, 0);
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

    Button btn_endPlacingP1({350, 50}, sf::Color::Black, sf::Color::White);
    btn_endPlacingP1.setOrigin({ 350 / 2, 50 / 2 });
    btn_endPlacingP1.setPosition({ 450, 870});

    Button btn_endPlacingP2({ 350, 50 }, sf::Color::Black, sf::Color::White);
    btn_endPlacingP2.setOrigin({ 350 / 2, 50 / 2 });
    btn_endPlacingP2.setPosition({ 450, 870 });

    Button btn_randomPlacing({ 350, 50 }, sf::Color::Black, sf::Color::White);
    btn_randomPlacing.setOrigin({ 350 / 2, 50 / 2 });
    btn_randomPlacing.setPosition({ 450, 800 });

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

    sf::Text txt_endPlacingP1(arial, "End placing");
    txt_bounds = txt_endPlacingP1.getGlobalBounds();
    txt_endPlacingP1.setFillColor(sf::Color::White);
    txt_endPlacingP1.setOrigin({ txt_bounds.getCenter().x, txt_bounds.getCenter().y });
    txt_endPlacingP1.setPosition({450, 870});

    sf::Text txt_endPlacingP2(arial, "End placing");
    txt_bounds = txt_endPlacingP2.getGlobalBounds();
    txt_endPlacingP2.setFillColor(sf::Color::White);
    txt_endPlacingP2.setOrigin({ txt_bounds.getCenter().x, txt_bounds.getCenter().y });
    txt_endPlacingP2.setPosition({ 450, 870 });

    sf::Text txt_randomPlacing(arial, "Random");
    txt_bounds = txt_randomPlacing.getGlobalBounds();
    txt_randomPlacing.setFillColor(sf::Color::White);
    txt_randomPlacing.setOrigin({ txt_bounds.getCenter().x, txt_bounds.getCenter().y });
    txt_randomPlacing.setPosition({ 450, 800 });

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
                            screen = static_cast<int>(screens::FieldPlayer1);
                        }
                    }

                    else if (btn_PvE.isMouseOver(window)) {
                        btn_PvE.setBackColor(sf::Color(btn_col_dark));
                        if (event->is<sf::Event::MouseButtonPressed>()) {
                            btn_PvE.invertBgCol(btn_col_dark);
                            screen = static_cast<int>(screens::FieldPlayer1);
                        }
                    }

                    else if (btn_Exit.isMouseOver(window)) {
                        btn_Exit.setBackColor(sf::Color(btn_col_dark));
                    }

                    break;
                }
                case static_cast<int>(screens::FieldPlayer1):// Поле Игрока 1 этапа "Расстановка"
                {
                    if (btn_endPlacingP1.isMouseOver(window)) {
                        btn_endPlacingP1.setBackColor(sf::Color(btn_col_dark));
                        if (event->is<sf::Event::MouseButtonPressed>()) {
                            btn_endPlacingP1.invertBgCol(btn_col_dark);
                            screen = static_cast<int>(screens::FieldPlayer2);
                        }
                    }

                    if (event->is<sf::Event::MouseMoved>())
                    {
                        for (int i = 0; i < 10; ++i) {
                            for (int j = 0; j < 10; ++j) {
                                if (player1Field[i][j].isMouseOver(window) && player1Field[i][j].getIndex() == 0)
                                {
                                    player1Field[i][j].setBackColor(sf::Color::White);
                                }
                                else if (player1Field[i][j].getIndex() == 0)
                                {
                                    player1Field[i][j].setBackColor(sf::Color::Black);
                                }
                            }
                        }
                    }
                    if (event->is<sf::Event::MouseButtonPressed>())
                    {
                        for (int i = 0; i < 10; ++i) {
                            for (int j = 0; j < 10; ++j) {
                                if (player1Field[i][j].isMouseOver(window))
                                {
                                    if (player1Field[i][j].getIndex() == 1)
                                    {
                                        player1Field[i][j].setIndex(0);
                                        player1Field[i][j].setBackColor(sf::Color::Black);
                                    }
                                    else
                                    {
                                        player1Field[i][j].setIndex(1);
                                        player1Field[i][j].setBackColor(sf::Color::Red);
                                    }
                                }
                            }
                        }
                    }
                    break;
                }
                case static_cast<int>(screens::FieldPlayer2):// Поле Игрока 2 этапа "Расстановка"
                {
                    if (btn_endPlacingP2.isMouseOver(window)) {
                        btn_endPlacingP2.setBackColor(sf::Color(btn_col_dark));
                        if (event->is<sf::Event::MouseButtonPressed>()) {
                            btn_endPlacingP2.invertBgCol(btn_col_dark);
                            screen = static_cast<int>(screens::BattlePlayer1);
                        }
                    }

                    if (event->is<sf::Event::MouseMoved>())
                    {
                        for (int i = 0; i < 10; ++i) {
                            for (int j = 0; j < 10; ++j) {
                                if (player2Field[i][j].isMouseOver(window) && player2Field[i][j].getIndex() == 0)
                                {
                                    player2Field[i][j].setBackColor(sf::Color::White);
                                }
                                else if (player2Field[i][j].getIndex() == 0)
                                {
                                    player2Field[i][j].setBackColor(sf::Color::Black);
                                }
                            }
                        }
                    }
                    if (event->is<sf::Event::MouseButtonPressed>())
                    {
                        for (int i = 0; i < 10; ++i) {
                            for (int j = 0; j < 10; ++j) {
                                if (player2Field[i][j].isMouseOver(window))
                                {
                                    if (player2Field[i][j].getIndex() == 1)
                                    {
                                        player2Field[i][j].setIndex(0);
                                        player2Field[i][j].setBackColor(sf::Color::Black);
                                    }
                                    else
                                    {
                                        player2Field[i][j].setIndex(1);
                                        player2Field[i][j].setBackColor(sf::Color::Red);
                                    }
                                }
                            }
                        }
                    }
                    break;
                }
                case static_cast<int>(screens::BattlePlayer1):// Поле Игрока 1 этапа "Бой"
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
        else if (screen == static_cast<int>(screens::FieldPlayer1))
        {
            for (int i = 0; i < 10; ++i) {
                coordinateLetters[i].drawTo(window);
                coordinateNumbers[i].drawTo(window);
            }
            btn_endPlacingP1.drawTo(window);
            window.draw(txt_endPlacingP1);
            btn_randomPlacing.drawTo(window);
            window.draw(txt_randomPlacing);
            for (int i = 0; i < 10; ++i) {
                for (int j = 0; j < 10; ++j) {
                    player1Field[i][j].drawTo(window);
                }
            }
        }
        else if (screen == static_cast<int>(screens::FieldPlayer2))
        {
            for (int i = 0; i < 10; ++i) {
                coordinateLetters[i].drawTo(window);
                coordinateNumbers[i].drawTo(window);
            }
            btn_endPlacingP2.drawTo(window);
            window.draw(txt_endPlacingP2);
            btn_randomPlacing.drawTo(window);
            window.draw(txt_randomPlacing);
            for (int i = 0; i < 10; ++i) {
                for (int j = 0; j < 10; ++j) {
                    player2Field[i][j].drawTo(window);
                }
            }
        }
        else if (screen == static_cast<int>(screens::BattlePlayer1))
        {
            for (int i = 0; i < 10; ++i) {
                coordinateLetters[i].drawTo(window);
                coordinateNumbers[i].drawTo(window);
            }
            for (int i = 0; i < 10; ++i) {
                for (int j = 0; j < 10; ++j) {
                    player1BattleField[i][j].drawTo(window);
                }
            }
        }
        window.display();
    }
}