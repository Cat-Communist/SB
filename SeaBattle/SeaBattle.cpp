#include "Classes.h"
#include <iostream>
#include <string>

//presets
int screen = static_cast<int>(screens::MainMenu); 
int curShip = static_cast<int>(list_of_ships::four);
sf::Font arial("FONTS/arialmt.ttf");

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 850, 900 }), "SeaBattle");
    Mouse mouse;
    //ships:
    //one-deck
    Ship one_deck1(1, { 10.f, 10.f }, sf::Color(0, 170, 255));
    Ship one_deck2(1, { 10.f, 10.f }, sf::Color(0, 170, 255));
    Ship one_deck3(1, { 10.f, 10.f }, sf::Color(0, 170, 255));
    Ship one_deck4(1, { 10.f, 10.f }, sf::Color(0, 170, 255));
    //two-deck
    Ship two_deck1(2, { 10.f, 10.f }, sf::Color(0, 170, 255));
    Ship two_deck2(2, { 10.f, 10.f }, sf::Color(0, 170, 255));
    Ship two_deck3(2, { 10.f, 10.f }, sf::Color(0, 170, 255));
    //trhre-deck
    Ship three_deck1(3, { 10.f, 10.f }, sf::Color(0, 170, 255));
    Ship three_deck2(3, { 10.f, 10.f }, sf::Color(0, 170, 255));
    //four-deck
    Ship four_deck(4, { 10.f, 10.f }, sf::Color(0, 170, 255));


    //create a Battle field
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
            positionX += 50;
        }
        positionY += 50;
    }
    positionY = 175;

    //create a setting field
    BattleCell setShips[10][10];
    for (int i{}; i < 10; i++)
    {
        for (int j{}; j < 10; j++)
        {
            setShips[i][j] = BattleCell({49, 49}, sf::Color::Black, sf::Color::White, 0);
        }
    }
    for (int i = 0; i < 10; ++i) {
        positionX = 175;
        for (int j = 0; j < 10; ++j) {
            setShips[i][j].setPosition({ positionX, positionY });
            positionX += 50;
        }
        positionY += 50;
    }
    positionY = 175;

    //set ships
    one_deck1.setPosition(setShips[9][2].getPosition());
    one_deck2.setPosition(setShips[0][3].getPosition());
    one_deck3.setPosition(setShips[6][4].getPosition());
    one_deck4.setPosition(setShips[8][6].getPosition());


    two_deck1.setPosition(setShips[6][0].getPosition());
    two_deck2.setPosition(setShips[5][6].getPosition()); two_deck2.wasClicked = true;
    two_deck3.setPosition(setShips[4][8].getPosition());

    three_deck1.setPosition(setShips[2][2].getPosition()); three_deck1.wasClicked = true;
    three_deck2.setPosition(setShips[0][7].getPosition()); three_deck2.wasClicked = true;

    four_deck.setPosition(setShips[0][0].getPosition()); four_deck.wasClicked = true;
    //menu textures
    sf::Texture bg_texture("Textures/background_img.jpg");
    sf::Sprite bg_sprite(bg_texture);
    bg_sprite.scale({ 4.5, 5.f });

    sf::Vector2f btn_size  = { 360.f, 75.f };
    sf::Vector2f center    = { 425.f, 450.f };
    sf::Vector2f step      = { 0.f, 105.f };
    sf::Color btn_col_reg  = sf::Color(5, 89, 250, 120);
    sf::Color btn_col_dark = sf::Color(5, 89, 250, 160);

    //setting menu buttons 
    Button btn_PvP(btn_size, btn_col_reg, sf::Color::Black);
    btn_PvP.setOrigin({ btn_size.x / 2, btn_size.y / 2 });
    btn_PvP.setPosition(center);

    Button btn_PvE(btn_size, btn_col_reg, sf::Color::Black);
    btn_PvE.setOrigin({ btn_size.x / 2, btn_size.y / 2 });
    btn_PvE.setPosition(center + step);

    Button btn_Exit(btn_size, btn_col_reg, sf::Color::Black);
    btn_Exit.setOrigin({ btn_size.x / 2, btn_size.y / 2 });
    btn_Exit.setPosition(center + step + step);

    //setting menu text
    sf::FloatRect txt_bounds;
    sf::Text txt_PvP(arial, L"Play");
    txt_bounds = txt_PvP.getGlobalBounds();
    txt_PvP.setFillColor(sf::Color::Black);
    txt_PvP.setOrigin({ txt_bounds.getCenter().x, txt_bounds.getCenter().y });
    txt_PvP.setPosition(center);

    sf::Text txt_PvE(arial, L"Игрок против компьютера");
    txt_bounds = txt_PvE.getGlobalBounds();
    txt_PvE.setFillColor(sf::Color::Black);
    txt_PvE.setOrigin({ txt_bounds.getCenter().x, txt_bounds.getCenter().y });
    txt_PvE.setPosition(center + step);

    sf::Text txt_Exit(arial, L"Выход");
    txt_bounds = txt_Exit.getGlobalBounds();
    txt_Exit.setFillColor(sf::Color::Black);
    txt_Exit.setOrigin({ txt_bounds.getCenter().x, txt_bounds.getCenter().y });
    txt_Exit.setPosition(center + step + step);

    //setting battlefield text
    sf::Text txt_curShip(arial);
    txt_curShip.setFillColor(sf::Color::White);

    while (window.isOpen())
    {

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
                            screen = static_cast<int>(screens::SettingShips);
                        }
                    }
                    else {
                        btn_PvP.setBackColor(sf::Color(btn_col_reg));
                    }

                    if (btn_PvE.isMouseOver(window)) {
                        btn_PvE.setBackColor(sf::Color(btn_col_dark));
                    }
                    else {
                        btn_PvE.setBackColor(sf::Color(btn_col_reg));
                    }

                    if (btn_Exit.isMouseOver(window)) {
                        btn_Exit.setBackColor(sf::Color(btn_col_dark));
                        if (event->is<sf::Event::MouseButtonPressed>()) {
                            window.close();
                        }
                    }
                    else {
                        btn_Exit.setBackColor(sf::Color(btn_col_reg));
                    }

                    break;
                }
                case static_cast<int>(screens::SettingShips):
                {
                    if (const auto* Key = event->getIf<sf::Event::KeyPressed>())
                    {
                        if (Key->scancode == sf::Keyboard::Scancode::Enter)
                        {
                            screen = static_cast<int>(screens::BattleField);
                        }
                    }
                    break;
                }
                case static_cast<int>(screens::BattleField):
                {
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

                    if (const auto* key = event->getIf<sf::Event::KeyPressed>())
                    {

                    }
                    break;
                }
            }
        }
        window.clear();
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

        if (screen == static_cast<int>(screens::BattleField))
        {
            for (int i = 0; i < 10; ++i) {
                for (int j = 0; j < 10; ++j) {
                    testBattleField[i][j].drawTo(window);
                }
            }
            window.draw(txt_curShip);
        }

        if (screen == static_cast<int>(screens::SettingShips))
        {
            //update mouse
            mouse.Update(window);

            //update ships
            one_deck1.Draggable(mouse);
            one_deck1.Rotatable(mouse);
            one_deck2.Draggable(mouse);
            one_deck2.Rotatable(mouse);
            one_deck3.Draggable(mouse);
            one_deck3.Rotatable(mouse);
            one_deck4.Draggable(mouse);
            one_deck4.Rotatable(mouse);

            two_deck1.Draggable(mouse);
            two_deck1.Rotatable(mouse);
            two_deck2.Draggable(mouse);
            two_deck2.Rotatable(mouse);
            two_deck3.Draggable(mouse);
            two_deck3.Rotatable(mouse);

            three_deck1.Draggable(mouse);
            three_deck1.Rotatable(mouse);
            three_deck2.Draggable(mouse);
            three_deck2.Rotatable(mouse);

            four_deck.Draggable(mouse);
            four_deck.Rotatable(mouse);

            for (int i{}; i < 10; i++)
            {
                for (int j{}; j < 10; j++)
                {
                    setShips[i][j].Alignbutton(mouse, one_deck1);
                    setShips[i][j].Alignbutton(mouse, one_deck2);
                    setShips[i][j].Alignbutton(mouse, one_deck3);
                    setShips[i][j].Alignbutton(mouse, one_deck4);

                    setShips[i][j].Alignbutton(mouse, two_deck1);
                    setShips[i][j].Alignbutton(mouse, two_deck2);
                    setShips[i][j].Alignbutton(mouse, two_deck3);

                    setShips[i][j].Alignbutton(mouse, three_deck1);
                    setShips[i][j].Alignbutton(mouse, three_deck2);

                    setShips[i][j].Alignbutton(mouse, four_deck);
                    setShips[i][j].drawTo(window);
                    //1 one-deck
                    if (setShips[i][j].ShipisOn(one_deck1))
                    {
                        setShips[i][j].setIndex(1);
                    }
                    else
                        setShips[i][j].setIndex(0);
                    //2 one-deck
                    if (setShips[i][j].ShipisOn(one_deck2))
                    {
                        setShips[i][j].setIndex(1);
                    }
                    else
                        setShips[i][j].setIndex(0);
                    //3 one-deck
                    if (setShips[i][j].ShipisOn(one_deck3))
                    {
                        setShips[i][j].setIndex(1);
                    }
                    else
                        setShips[i][j].setIndex(0);
                    //4 one-deck
                    if (setShips[i][j].ShipisOn(one_deck4))
                    {
                        setShips[i][j].setIndex(1);
                    }
                    else
                        setShips[i][j].setIndex(0);
                    //1 two-deck
                    if (setShips[i][j].ShipisOn(two_deck1))
                    {
                        setShips[i][j].setIndex(1);
                    }
                    else
                        setShips[i][j].setIndex(0);
                    //2 two-deck
                    if (setShips[i][j].ShipisOn(two_deck2))
                    {
                        setShips[i][j].setIndex(1);
                    }
                    else
                        setShips[i][j].setIndex(0);
                    //3 two-deck
                    if (setShips[i][j].ShipisOn(two_deck3))
                    {
                        setShips[i][j].setIndex(1);
                    }
                    else
                        setShips[i][j].setIndex(0);
                    //1 three-deck
                    if (setShips[i][j].ShipisOn(three_deck1))
                    {
                        setShips[i][j].setIndex(1);
                    }
                    else
                        setShips[i][j].setIndex(0);
                    //2 three-deck
                    if (setShips[i][j].ShipisOn(three_deck2))
                    {
                        setShips[i][j].setIndex(1);
                    }
                    else
                        setShips[i][j].setIndex(0);

                    //1 four-deck
                    if (setShips[i][j].ShipisOn(four_deck))
                    {
                        setShips[i][j].setIndex(1);
                    }
                    else
                        setShips[i][j].setIndex(0);

                    for (int i{}; i < 10; i++)
                    {
                        for (int j{}; j < 10; j++)
                        {
                            std::cout << setShips[i][j].getIndex() << " ";
                        }
                        std::cout << std::endl;
                    }
                    std::cout << std::endl;

                }
            }

            one_deck1.Draw(window);
            one_deck2.Draw(window);
            one_deck3.Draw(window);
            one_deck4.Draw(window);

            two_deck1.Draw(window);
            two_deck2.Draw(window);
            two_deck3.Draw(window);

            three_deck1.Draw(window);
            three_deck2.Draw(window);

            four_deck.Draw(window);
        }

        window.display();
    }
}