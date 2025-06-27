#include "Classes.h"
#include "ScreenState.h"
#include <iostream>
#include <vector>
#include <iostream>
#include <fstream>

//presets
screens screen = screens::MainMenu;
sf::Font arial("FONTS/arialmt.ttf");
bool random = false;

void copyFieldToBattleField(BattleCell source[10][10], BattleCell target[10][10]) {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            target[i][j].setIndex(source[i][j].getIndex());
        }
    }
}

int main()
{
    std::ofstream statFile;
    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode({ 900, 950 }), "SeaBattle");
    std::vector<std::string> statVector;
    std::string stringOfStat = " ";

    Mouse mouse;
    //ships:
    //player 1
    //one-deck
    Ship one_deck1P1(1, { 10.f, 10.f }, sf::Color(0, 170, 255));
    Ship one_deck2P1(1, { 10.f, 10.f }, sf::Color(0, 170, 255));
    Ship one_deck3P1(1, { 10.f, 10.f }, sf::Color(0, 170, 255));
    Ship one_deck4P1(1, { 10.f, 10.f }, sf::Color(0, 170, 255));
    //two-deck
    Ship two_deck1P1(2, { 10.f, 10.f }, sf::Color(0, 170, 255));
    Ship two_deck2P1(2, { 10.f, 10.f }, sf::Color(0, 170, 255));
    Ship two_deck3P1(2, { 10.f, 10.f }, sf::Color(0, 170, 255));
    //three-deck
    Ship three_deck1P1(3, { 10.f, 10.f }, sf::Color(0, 170, 255));
    Ship three_deck2P1(3, { 10.f, 10.f }, sf::Color(0, 170, 255));
    //four-deck
    Ship four_deckP1(4, { 10.f, 10.f }, sf::Color(0, 170, 255));
    std::vector<Ship*> shipsP1_container = {
        //one-deck
        &one_deck1P1,
        &one_deck2P1,
        &one_deck3P1,
        &one_deck4P1,
        //two-deck
        &two_deck1P1,
        &two_deck2P1,
        &two_deck3P1,
        //three-deck
        &three_deck1P1,
        &three_deck2P1,
        //four-deck
        &four_deckP1
    };

    //player 2
    Ship one_deck1P2(1, { 10.f, 10.f }, sf::Color(0, 170, 255));
    Ship one_deck2P2(1, { 10.f, 10.f }, sf::Color(0, 170, 255));
    Ship one_deck3P2(1, { 10.f, 10.f }, sf::Color(0, 170, 255));
    Ship one_deck4P2(1, { 10.f, 10.f }, sf::Color(0, 170, 255));
    //two-deck
    Ship two_deck1P2(2, { 10.f, 10.f }, sf::Color(0, 170, 255));
    Ship two_deck2P2(2, { 10.f, 10.f }, sf::Color(0, 170, 255));
    Ship two_deck3P2(2, { 10.f, 10.f }, sf::Color(0, 170, 255));
    //three-deck
    Ship three_deck1P2(3, { 10.f, 10.f }, sf::Color(0, 170, 255));
    Ship three_deck2P2(3, { 10.f, 10.f }, sf::Color(0, 170, 255));
    //four-deck
    Ship four_deckP2(4, { 10.f, 10.f }, sf::Color(0, 170, 255));
    std::vector<Ship*> shipsP2_container = {
        //one-deck
        &one_deck1P2,
        &one_deck2P2,
        &one_deck3P2,
        &one_deck4P2,
        //two-deck
        &two_deck1P2,
        &two_deck2P2,
        &two_deck3P2,
        //three-deck
        &three_deck1P2,
        &three_deck2P2,
        //four-deck
        &four_deckP2
    };


    Button coordinateLetters[10];
    Button coordinateNumbers[10];
    BattleCell player1Field[10][10];
    BattleCell player2Field[10][10];
    BattleCell player1CheckField[10][10];
    BattleCell player2CheckField[10][10];
    BattleCell player1BattleField[10][10];
    BattleCell player2BattleField[10][10];
    float positionX = 225;
    float positionY = 225;
    // Координаты
    for (int i = 0; i < 10; ++i) {
        coordinateLetters[i] = Button({ 50, 50 }, sf::Color(25, 25, 25), sf::Color::White);
        coordinateLetters[i].setPosition({ positionX, 175});
        positionX = positionX + 50;
    }
    for (int i = 0; i < 10; ++i) {
        coordinateNumbers[i] = Button({ 50, 50 }, sf::Color(25, 25, 25), sf::Color::White);
        coordinateNumbers[i].setPosition({ 175, positionY });
        positionY = positionY + 50;
    }
    positionY = 225;
    positionX = 225;

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            player1Field[i][j] = BattleCell({ 50, 50 }, sf::Color::Black, sf::Color::White, 0);
            player2Field[i][j] = BattleCell({ 50, 50 }, sf::Color::Black, sf::Color::White, 0);

            player1BattleField[i][j] = BattleCell({ 50, 50 }, sf::Color::Black, sf::Color::White, 0);
            player2BattleField[i][j] = BattleCell({ 50, 50 }, sf::Color::Black, sf::Color::White, 0);

            player1CheckField[i][j] = BattleCell({ 50, 50 }, sf::Color::Black, sf::Color::White, 0);
            player2CheckField[i][j] = BattleCell({ 50, 50 }, sf::Color::Black, sf::Color::White, 0);
        }
    }
    for (int i = 0; i < 10; ++i) {
        positionX = 225;
        for (int j = 0; j < 10; ++j) {
            player1Field[i][j].setPosition({ positionX, positionY });
            player2Field[i][j].setPosition({ positionX, positionY });

            player1BattleField[i][j].setPosition({ positionX, positionY });
            player2BattleField[i][j].setPosition({ positionX, positionY });

            player1CheckField[i][j].setPosition({ positionX, positionY });
            player2CheckField[i][j].setPosition({ positionX, positionY });
            positionX = positionX + 50;
        }
        positionY = positionY + 50;
    }
    positionY = 225;
    positionX = 225;

    //create a setting field
    //set ships
    //player 1
    one_deck1P1.setPosition(player1Field[9][2].getPosition());
    one_deck2P1.setPosition(player1Field[0][3].getPosition());
    one_deck3P1.setPosition(player1Field[6][4].getPosition());
    one_deck4P1.setPosition(player1Field[8][6].getPosition());


    two_deck1P1.setPosition(player1Field[6][0].getPosition());
    two_deck2P1.setPosition(player1Field[5][6].getPosition()); two_deck2P1.wasClicked = true;
    two_deck3P1.setPosition(player1Field[4][8].getPosition());

    three_deck1P1.setPosition(player1Field[2][2].getPosition()); three_deck1P1.wasClicked = true;
    three_deck2P1.setPosition(player1Field[0][7].getPosition()); three_deck2P1.wasClicked = true;

    four_deckP1.setPosition(player1Field[0][0].getPosition()); four_deckP1.wasClicked = true;

    //player 2
    one_deck1P2.setPosition(player1Field[9][2].getPosition());
    one_deck2P2.setPosition(player1Field[0][3].getPosition());
    one_deck3P2.setPosition(player1Field[6][4].getPosition());
    one_deck4P2.setPosition(player1Field[8][6].getPosition());


    two_deck1P2.setPosition(player1Field[6][0].getPosition());
    two_deck2P2.setPosition(player1Field[5][6].getPosition()); two_deck2P2.wasClicked = true;
    two_deck3P2.setPosition(player1Field[4][8].getPosition());

    three_deck1P2.setPosition(player1Field[2][2].getPosition()); three_deck1P2.wasClicked = true;
    three_deck2P2.setPosition(player1Field[0][7].getPosition()); three_deck2P2.wasClicked = true;

    four_deckP2.setPosition(player1Field[0][0].getPosition()); four_deckP2.wasClicked = true;

    //menu textures
    sf::Texture bg_texture("Textures/background_img.jpg");
    sf::Sprite bg_sprite(bg_texture);
    bg_sprite.scale({ 5, 5.5 });

    sf::Vector2f btn_size  = { 360.f, 75.f };
    sf::Vector2f center    = { 450.f, 475.f };
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
    bool PvE = false;

    Button btn_Exit(btn_size, btn_col_reg, sf::Color::Black);
    btn_Exit.setOrigin({ btn_size.x / 2, btn_size.y / 2 });
    btn_Exit.setPosition(center + step + step);

    //setting 'placing ships' buttons
    Button btn_randomPlacing({ 350, 50 }, sf::Color::Black, sf::Color::White);
    btn_randomPlacing.setOrigin({ 350 / 2, 50 / 2 });
    btn_randomPlacing.setPosition({ 450, 800 });

    Button btn_endPlacingP1({350, 50}, sf::Color::Black, sf::Color::White);
    btn_endPlacingP1.setOrigin({ 350 / 2, 50 / 2 });
    btn_endPlacingP1.setPosition({ 450, 870});

    Button btn_endPlacingP2({ 350, 50 }, sf::Color::Black, sf::Color::White);
    btn_endPlacingP2.setOrigin({ 350 / 2, 50 / 2 });
    btn_endPlacingP2.setPosition({ 450, 870 });

    Button btn_seeField({ 350, 50 }, sf::Color::Black, sf::Color::White);
    btn_seeField.setOrigin({ 350 / 2, 50 / 2 });
    btn_seeField.setPosition({ 450, 800 });

    Button btn_saveStat({ 350, 50 }, sf::Color::Black, sf::Color::White);
    btn_saveStat.setOrigin({ 350 / 2, 50 / 2 });
    btn_saveStat.setPosition({ 450, 870 });

    Button btn_saveEndStat(btn_size, btn_col_reg, sf::Color::Black);
    btn_saveEndStat.setOrigin({ btn_size.x / 2, btn_size.y / 2 });
    btn_saveEndStat.setPosition(center + step);

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

    //setting text for placing ships

    sf::Text txt_randomPlacing(arial, "Random");
    txt_bounds = txt_randomPlacing.getGlobalBounds();
    txt_randomPlacing.setFillColor(sf::Color::White);
    txt_randomPlacing.setOrigin({ txt_bounds.getCenter().x, txt_bounds.getCenter().y });
    txt_randomPlacing.setPosition({ 450, 800 });

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

    //text for coordinates
    std::vector<sf::Text> letters;
    positionX = 315;
    for (int i = 0; i < 10; i++) {
        sf::Text text(arial);
        text.setString(std::string(1, 'A' + i));
        text.setCharacterSize(50);
        text.setFillColor(sf::Color::White);
        sf::FloatRect bounds = text.getLocalBounds();
        text.setOrigin({ txt_bounds.getCenter().x, txt_bounds.getCenter().y });
        text.setPosition({ positionX, 185 });
        letters.push_back(text);
        positionX = positionX + 50;
    }
    positionX = 225;

    std::vector<sf::Text> numbers;
    positionY = 240;
    for (int i = 0; i < 9; i++) {
        sf::Text text(arial);
        text.setString(std::string(1, '1' + i));
        text.setCharacterSize(50);
        text.setFillColor(sf::Color::White);
        sf::FloatRect bounds = text.getLocalBounds();
        text.setOrigin({ txt_bounds.getCenter().x, txt_bounds.getCenter().y });
        text.setPosition({ 265, positionY });
        numbers.push_back(text);
        positionY = positionY + 50;
    }
    sf::Text text(arial);
    text.setString(std::string(1, '0'));
    text.setCharacterSize(50);
    text.setFillColor(sf::Color::White);
    sf::FloatRect bounds = text.getLocalBounds();
    text.setOrigin({ txt_bounds.getCenter().x, txt_bounds.getCenter().y });
    text.setPosition({ 265, positionY });
    numbers.push_back(text);
    positionY = 225;

    sf::Text txt_player(arial);
    txt_player.setString("Player 1");
    txt_player.setFillColor(sf::Color::White);
    txt_player.setPosition({ 10, 10 });

    sf::Text txt_placingText(arial);
    txt_placingText.setString("place your ships.");
    txt_placingText.setFillColor(sf::Color::White);
    txt_placingText.setPosition({ 128, 10 });

    sf::Text txt_turn(arial);
    int turnNumber = 1;
    txt_turn.setString("Turn " + std::to_string(turnNumber));
    txt_bounds = txt_turn.getGlobalBounds();
    txt_turn.setOrigin({ txt_bounds.getCenter().x * 2, 0 });
    txt_turn.setFillColor(sf::Color::White);
    txt_turn.setPosition({ 870, 10 });

    sf::Text txt_seeField(arial, "Check your field");
    txt_bounds = txt_seeField.getGlobalBounds();
    txt_seeField.setFillColor(sf::Color::White);
    txt_seeField.setOrigin({ txt_bounds.getCenter().x, txt_bounds.getCenter().y });
    txt_seeField.setPosition({ 450, 800 });

    sf::Text txt_saveStat(arial, "Save statistics");
    txt_bounds = txt_saveStat.getGlobalBounds();
    txt_saveStat.setFillColor(sf::Color::White);
    txt_saveStat.setOrigin({ txt_bounds.getCenter().x, txt_bounds.getCenter().y });
    txt_saveStat.setPosition({ 450, 870 });

    sf::Text txt_backToBattle(arial, "Back to battle");
    txt_bounds = txt_backToBattle.getGlobalBounds();
    txt_backToBattle.setFillColor(sf::Color::White);
    txt_backToBattle.setOrigin({ txt_bounds.getCenter().x, txt_bounds.getCenter().y });
    txt_backToBattle.setPosition({ 450, 800 });

    sf::Text txt_win(arial, "Player 1 win");
    txt_win.setCharacterSize(100);
    txt_bounds = txt_win.getGlobalBounds();
    txt_win.setFillColor(sf::Color::White);
    txt_win.setOrigin({ txt_bounds.getCenter().x, txt_bounds.getCenter().y });
    txt_win.setPosition({ 450, 225 });

    sf::Text txt_saveEndStat(arial, "Save statistics");
    txt_bounds = txt_saveEndStat.getGlobalBounds();
    txt_saveEndStat.setFillColor(sf::Color::Black);
    txt_saveEndStat.setOrigin({ txt_bounds.getCenter().x, txt_bounds.getCenter().y });
    txt_saveEndStat.setPosition(center + step);

    int shots1 = 0;
    int shots2 = 0;

    static screens lastScreen = screens::MainMenu;

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
                statFile.close();
            }
            switch (screen)
            {
            case screens::MainMenu:
            {
                //handle events onMouse
                statVector.clear();
                PvE = false;
                turnNumber = 1;
                txt_turn.setString("Turn " + std::to_string(turnNumber));
                if (btn_PvP.isMouseOver(window)) {
                    btn_PvP.setBackColor(sf::Color(btn_col_dark));
                    if (event->is<sf::Event::MouseButtonPressed>()) {
                        mouse.Reset();
                        screen = screens::FieldPlayer1;
                        shots1 = 0;
                        shots2 = 0;
                    }
                }
                else {
                    btn_PvP.setBackColor(sf::Color(btn_col_reg));
                }

                if (btn_PvE.isMouseOver(window)) {
                    btn_PvE.setBackColor(sf::Color(btn_col_dark));
                    if (event->is<sf::Event::MouseButtonPressed>()) {
                        mouse.Reset();
                        screen = screens::FieldPlayer1;
                        PvE = true;
                        shots1 = 0;
                    }
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
            case screens::FieldPlayer1:// Поле Игрока 1 этапа "Расстановка"
            {
                if (PvE)
                    txt_player.setString("Player");
                else
                    txt_player.setString("Player 1");
                if (btn_endPlacingP1.isMouseOver(window)) {
                    btn_endPlacingP1.setBackColor(sf::Color(btn_col_dark));
                    if (event->is<sf::Event::MouseButtonPressed>()) {
                        copyFieldToBattleField(player1Field, player2BattleField);
                        copyFieldToBattleField(player1Field, player1CheckField);
                        screens lastScreen = screens::FieldPlayer2;
                        if (PvE)
                        {
                            screen = screens::BattlePlayer1;
                            // Сброс позиций кораблей
                            int i = 0;
                            for (Ship* prop : shipsP2_container)
                            {
                                prop->setPosition({ 0.f + i * 250.f, 0.f });
                                if (prop->height > prop->width) prop->wasClicked = true;
                                ++i;
                                prop->color = sf::Color(0, 170, 255);
                            }

                            // Пытаемся разместить случайно
                            bool RandomSuccess = true;
                            std::sort(shipsP2_container.begin(), shipsP2_container.end(),
                                [](const Ship* a, const Ship* b) { return a->decks > b->decks; });
                            for (Ship* ship : shipsP2_container) {
                                for (int attempt = 0; attempt < 1000; ++attempt) {
                                    if (!RandomPlacing(player2Field, ship, shipsP2_container)) {
                                        // После успешного размещения обновляем индексы
                                        for (int y = 0; y < 10; ++y) {
                                            for (int x = 0; x < 10; ++x) {
                                                if (player2Field[y][x].ShipisOn(*ship)) {
                                                    player2Field[y][x].setIndex(1);  // Помечаем клетки с кораблями
                                                }
                                            }
                                        }
                                        break;
                                    }
                                    if (attempt == 999)
                                        RandomSuccess = false;
                                }
                            }

                            // Проверяем корректность
                            if (RandomSuccess) {
                                for (Ship* prop : shipsP2_container) {
                                    if (player2Field[0][0].checkBoundary(*prop) ||  // Изменено с player1Field на player2Field
                                        checkCollision(prop, shipsP2_container)) {
                                        RandomSuccess = false;
                                        break;
                                    }
                                }
                            }

                            // Если не удалось - применяем пресет
                            if (!RandomSuccess) {
                                // Сброс позиций
                                i = 0;
                                for (Ship* prop : shipsP2_container) {
                                    prop->setPosition({ 0.f + i * 250.f, 0.f });
                                    if (prop->height != 1) prop->wasClicked = true;
                                    ++i;
                                    prop->color = sf::Color(0, 170, 255);
                                }

                                // Применяем пресет
                                RandomPresets(player2Field, shipsP2_container);  // Изменено с player1Field на player2Field

                                // Обновляем индексы клеток после пресета
                                for (Ship* ship : shipsP2_container) {
                                    for (int y = 0; y < 10; ++y) {
                                        for (int x = 0; x < 10; ++x) {
                                            if (player2Field[y][x].ShipisOn(*ship)) {  // Изменено с player1Field на player2Field
                                                player2Field[y][x].setIndex(1);
                                            }
                                        }
                                    }
                                }
                            }

                            // Копируем расстановку компьютера в поле для атаки игрока
                            copyFieldToBattleField(player2Field, player1BattleField);  // Добавлено для корректной работы
                        }
                        else
                        {
                            screen = screens::FieldPlayer2;
                        }
                    }
                }
                else
                    btn_endPlacingP1.setBackColor(sf::Color());

                if (btn_randomPlacing.isMouseOver(window)) {
                    btn_randomPlacing.setBackColor(sf::Color(btn_col_dark));
                    random = true;
                    if (event->is<sf::Event::MouseButtonPressed>())
                    {
                        // Сброс позиций кораблей
                        int i = 0;
                        for (Ship* prop : shipsP1_container)
                        {
                            prop->setPosition({ 0.f + i * 250.f, 0.f });
                            if (prop->height > prop->width) prop->wasClicked = true;
                            ++i;
                            prop->color = sf::Color(0, 170, 255);
                        }

                        // Пытаемся разместить случайно
                        bool RandomSuccess = true;
                        std::sort(shipsP1_container.begin(), shipsP1_container.end(),
                            [](const Ship* a, const Ship* b) { return a->decks > b->decks; });

                        for (Ship* prop : shipsP1_container) {
                            for (int attempt = 0; attempt < 1000; ++attempt) {
                                if (!RandomPlacing(player1Field, prop, shipsP1_container)) {
                                    break;
                                }
                                if (attempt == 999)
                                    RandomSuccess = false;
                            }
                        }

                        // Проверяем корректность
                        if (RandomSuccess) {
                            for (Ship* prop : shipsP1_container) {
                                if (player1Field[0][0].checkBoundary(*prop) ||
                                    checkCollision(prop, shipsP1_container)) {
                                    RandomSuccess = false;
                                    break;
                                }
                            }
                        }

                        // Если не удалось - применяем пресет
                        if (!RandomSuccess) {
                            // Сброс позиций
                            i = 0;
                            for (Ship* prop : shipsP1_container) {
                                prop->setPosition({ 0.f + i * 250.f, 0.f });
                                if (prop->height != 1) prop->wasClicked = true;
                                ++i;
                                prop->color = sf::Color(0, 170, 255);
                            }

                            // Применяем пресет
                            RandomPresets(player1Field, shipsP1_container);

                            // Обновляем индексы клеток после пресета
                            for (Ship* ship : shipsP1_container) {
                                for (int y = 0; y < 10; ++y) {
                                    for (int x = 0; x < 10; ++x) {
                                        if (player1Field[y][x].ShipisOn(*ship)) {
                                            player1Field[y][x].setIndex(1);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                else
                    btn_randomPlacing.setBackColor(sf::Color());
                break;
            }
            case screens::FieldPlayer2:// Поле Игрока 2 этапа "Расстановка"
            {
                txt_player.setString("Player 2");
                if (btn_endPlacingP2.isMouseOver(window)) {
                    btn_endPlacingP2.setBackColor(sf::Color(btn_col_dark));
                    if (event->is<sf::Event::MouseButtonPressed>()) {
                        copyFieldToBattleField(player2Field, player1BattleField);
                        copyFieldToBattleField(player2Field, player2CheckField);
                        screen = screens::BattlePlayer1;
                        screens lastScreen = screens::FieldPlayer2;
                    }
                }
                else
                    btn_endPlacingP2.setBackColor(sf::Color());

                if (btn_randomPlacing.isMouseOver(window)) {
                    btn_randomPlacing.setBackColor(sf::Color(btn_col_dark));
                    random = true;
                    if (event->is<sf::Event::MouseButtonPressed>())
                    {
                        // Сброс позиций кораблей
                        int i = 0;
                        for (Ship* prop : shipsP2_container)
                        {
                            prop->setPosition({ 0.f + i * 250.f, 0.f });
                            if (prop->height > prop->width) prop->wasClicked = true;
                            ++i;
                            prop->color = sf::Color(0, 170, 255);
                        }

                        // Пытаемся разместить случайно
                        bool RandomSuccess = true;
                        std::sort(shipsP2_container.begin(), shipsP2_container.end(),
                            [](const Ship* a, const Ship* b) { return a->decks > b->decks; });

                        for (Ship* prop : shipsP2_container) {
                            for (int attempt = 0; attempt < 1000; ++attempt) {
                                if (!RandomPlacing(player2Field, prop, shipsP2_container)) {
                                    break;
                                }
                                if (attempt == 999)
                                    RandomSuccess = false;
                            }
                        }

                        // Проверяем корректность
                        if (RandomSuccess) {
                            for (Ship* prop : shipsP2_container) {
                                if (player2Field[0][0].checkBoundary(*prop) ||
                                    checkCollision(prop, shipsP2_container)) {
                                    RandomSuccess = false;
                                    break;
                                }
                            }
                        }

                        // Если не удалось - применяем пресет
                        if (!RandomSuccess) {
                            // Сброс позиций
                            i = 0;
                            for (Ship* prop : shipsP2_container) {
                                prop->setPosition({ 0.f + i * 250.f, 0.f });
                                if (prop->height != 1) prop->wasClicked = true;
                                ++i;
                                prop->color = sf::Color(0, 170, 255);
                            }

                            // Применяем пресет
                            RandomPresets(player2Field, shipsP2_container);

                            // Обновляем индексы клеток после пресета
                            for (Ship* ship : shipsP2_container) {
                                for (int y = 0; y < 10; ++y) {
                                    for (int x = 0; x < 10; ++x) {
                                        if (player2Field[y][x].ShipisOn(*ship)) {
                                            player2Field[y][x].setIndex(1);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                else
                    btn_randomPlacing.setBackColor(sf::Color());
                break;
            }
            case screens::BattlePlayer1:// Поле Игрока 1 этапа "Бой"
            {
                txt_turn.setString("Turn " + std::to_string(turnNumber));
                txt_player.setString("Player 1"); 
                if (lastScreen != screens::BattlePlayer1)
                {
                    stringOfStat = "Turn " + std::to_string(turnNumber) + "\n";
                    statVector.push_back(stringOfStat);
                }
                lastScreen = screens::BattlePlayer1;
                if (event->is<sf::Event::MouseMoved>())
                {
                    for (int i = 0; i < 10; ++i) {
                        for (int j = 0; j < 10; ++j) {
                            if (player1BattleField[i][j].getBackColor() == sf::Color(100, 100, 100))
                            {
                                player1BattleField[i][j].setBackColor(sf::Color::Black);
                            }
                            if (player1BattleField[i][j].isMouseOver(window) &&
                                player1BattleField[i][j].getBackColor() == sf::Color::Black)
                            {
                                player1BattleField[i][j].setBackColor(sf::Color(100, 100, 100));
                            }
                        }
                    }
                }
                if (event->is<sf::Event::MouseButtonPressed>())
                {
                    for (int i = 0; i < 10; ++i) {
                        for (int j = 0; j < 10; ++j) {
                            if (player1BattleField[i][j].isMouseOver(window) &&
                                player1BattleField[i][j].getBackColor() == sf::Color(100, 100, 100))
                            {
                                if (player1BattleField[i][j].getIndex() == 1) {
                                    player1BattleField[i][j].setBackColor(sf::Color::Red);
                                    shots1++;
                                    if (shots1 == 20)
                                    {
                                        screen = screens::EndGame;
                                        txt_win.setString("Player wins!");
                                    }
                                    // Если попали - ход остается у игрока
                                }
                                else {
                                    player1BattleField[i][j].setBackColor(sf::Color::White);
                                    // Если промахнулись - ход переходит к компьютеру
                                    if (PvE) {
                                        // Ждем немного перед ходом компьютера
                                        sf::sleep(sf::milliseconds(500));
                                        RandomShot(mouse, player2BattleField);
                                        // Обрабатываем выстрел компьютера
                                        for (int i = 0; i < 10; ++i) {
                                            for (int j = 0; j < 10; ++j) {
                                                if (player2BattleField[i][j].getPosition() == sf::Vector2f(mouse.x, mouse.y)) {
                                                    if (player2BattleField[i][j].getIndex() == 1) {
                                                        player2BattleField[i][j].setBackColor(sf::Color::Red);
                                                        shots2++;
                                                        if (shots2 == 20) {
                                                            screen = screens::EndGame;
                                                            txt_win.setString("Computer wins!");
                                                        }
                                                        // Если компьютер попал - он ходит снова
                                                        sf::sleep(sf::milliseconds(500));
                                                        RandomShot(mouse, player2BattleField);
                                                    }
                                                    else {
                                                        player2BattleField[i][j].setBackColor(sf::Color::White);
                                                        // Если компьютер промахнулся - ход переходит к игроку
                                                        turnNumber++;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                if (btn_seeField.isMouseOver(window)) {
                    btn_seeField.setBackColor(sf::Color(btn_col_dark));
                    if (event->is<sf::Event::MouseButtonPressed>()) {
                        screen = screens::CheckField1;
                    }
                }
                else
                    btn_seeField.setBackColor(sf::Color());

                if (btn_saveStat.isMouseOver(window)) {
                    btn_saveStat.setBackColor(sf::Color(btn_col_dark));
                    statFile.open("Statistics.txt", std::ios::out | std::ios::trunc);
                    if (statFile.is_open()) {
                        for (const auto& line : statVector) {
                            statFile << line;
                        }
                        statFile.close();
                    }
                    else {
                        std::cerr << "Cannot open the file.\n";
                    }
                }
                else
                    btn_saveStat.setBackColor(sf::Color());

                break;
            }
            case screens::BattlePlayer2:// Поле Игрока 2 этапа "Бой"
            {
                txt_turn.setString("Turn " + std::to_string(turnNumber));
                txt_player.setString("Player 2");
                lastScreen = screens::BattlePlayer2;
                if (event->is<sf::Event::MouseMoved>())
                {
                    for (int i = 0; i < 10; ++i) {
                        for (int j = 0; j < 10; ++j) {
                            if (player2BattleField[i][j].getBackColor() == sf::Color(100, 100, 100))
                            {
                                player2BattleField[i][j].setBackColor(sf::Color::Black);
                            }
                            if (player2BattleField[i][j].isMouseOver(window) &&
                                player2BattleField[i][j].getBackColor() == sf::Color::Black)
                            {
                                player2BattleField[i][j].setBackColor(sf::Color(100, 100, 100));
                            }
                        }
                    }
                }
                if (event->is<sf::Event::MouseButtonPressed>())
                {
                    for (int i = 0; i < 10; ++i) {
                        for (int j = 0; j < 10; ++j) {
                            if (player2BattleField[i][j].isMouseOver(window) && player2BattleField[i][j].getBackColor() == sf::Color(100, 100, 100))
                            {
                                if (player2BattleField[i][j].getIndex() == 1)
                                {
                                    player2BattleField[i][j].setBackColor(sf::Color::Red);
                                    shots2++;
                                    stringOfStat = "Player 2 [" + std::string(1, 'A' + j) + std::to_string(i + 1) + "] - hit.\n";
                                    statVector.push_back(stringOfStat);
                                    if (shots2 == 20)
                                    {
                                        screen = screens::EndGame;
                                        txt_win.setString("Player 2 win!");
                                        stringOfStat = "Player 2 win!\n";
                                        statVector.push_back(stringOfStat);
                                    }
                                }
                                else
                                {
                                    player2BattleField[i][j].setBackColor(sf::Color::White);
                                    stringOfStat = "Player 2 [" + std::string(1, 'A' + j) + std::to_string(i + 1) + "] - miss.\n";
                                    statVector.push_back(stringOfStat);
                                    stringOfStat = "=====================================\n";
                                    statVector.push_back(stringOfStat);
                                    screen = screens::BattlePlayer1;
                                    turnNumber++;
                                }
                            }
                        }
                    }
                }
                if (btn_seeField.isMouseOver(window)) {
                    btn_seeField.setBackColor(sf::Color(btn_col_dark));
                    if (event->is<sf::Event::MouseButtonPressed>()) {
                        screen = screens::CheckField2;
                    }
                }
                else
                    btn_seeField.setBackColor(sf::Color());

                if (btn_saveStat.isMouseOver(window)) {
                    btn_saveStat.setBackColor(sf::Color(btn_col_dark));
                    statFile.open("Statistics.txt", std::ios::out | std::ios::trunc);
                    if (statFile.is_open()) {
                        for (const auto& line : statVector) {
                            statFile << line;
                        }
                        statFile.close();
                    }
                    else {
                        std::cerr << "Cannot open the file.\n";
                    }
                }
                else
                    btn_saveStat.setBackColor(sf::Color());

                break;
            }
            case screens::CheckField1:
            {
                if (btn_seeField.isMouseOver(window)) {
                    btn_seeField.setBackColor(sf::Color(btn_col_dark));
                    if (event->is<sf::Event::MouseButtonPressed>()) {
                        screen = screens::BattlePlayer1;
                    }
                }
                else
                    btn_seeField.setBackColor(sf::Color());
                for (int i = 0; i < 10; ++i) {
                    for (int j = 0; j < 10; ++j) {
                        if (player1CheckField[i][j].getIndex() == 1 && !(player2BattleField[i][j].getBackColor() == sf::Color::Red))
                        {
                            player1CheckField[i][j].setBackColor(sf::Color(0, 170, 255));
                        }
                        else if (player2BattleField[i][j].getBackColor() == sf::Color::White)
                        {
                            player1CheckField[i][j].setBackColor(sf::Color::White);
                        }
                        else if (player2BattleField[i][j].getBackColor() == sf::Color::Red)
                        {
                            player1CheckField[i][j].setBackColor(sf::Color::Red);
                        }
                    }
                }
                break;
            }
            case screens::CheckField2:
            {
                if (btn_seeField.isMouseOver(window)) {
                    btn_seeField.setBackColor(sf::Color(btn_col_dark));
                    if (event->is<sf::Event::MouseButtonPressed>()) {
                        screen = screens::BattlePlayer2;
                    }
                }
                else
                    btn_seeField.setBackColor(sf::Color());
                for (int i = 0; i < 10; ++i) {
                    for (int j = 0; j < 10; ++j) {
                        if (player2CheckField[i][j].getIndex() == 1 && !(player1BattleField[i][j].getBackColor() == sf::Color::Red))
                        {
                            player2CheckField[i][j].setBackColor(sf::Color(0, 170, 255));
                        }
                        else if (player1BattleField[i][j].getBackColor() == sf::Color::White)
                        {
                            player2CheckField[i][j].setBackColor(sf::Color::White);
                        }
                        else if (player1BattleField[i][j].getBackColor() == sf::Color::Red)
                        {
                            player2CheckField[i][j].setBackColor(sf::Color::Red);
                        }
                    }
                }
                break;
            }
            case screens::EndGame:
            {
                if (btn_saveEndStat.isMouseOver(window)) {
                    btn_saveEndStat.setBackColor(sf::Color(btn_col_dark));
                    if (event->is<sf::Event::MouseButtonPressed>()) {
                        statFile.open("Statistics.txt", std::ios::out | std::ios::trunc);
                        if (statFile.is_open()) {
                            for (const auto& line : statVector) {
                                statFile << line;
                            }
                            statFile.close();
                        }
                        else {
                            std::cerr << "Cannot open the file.\n";
                        }
                    }
                }
                else {
                    btn_saveEndStat.setBackColor(sf::Color(btn_col_reg));
                }

                if (btn_Exit.isMouseOver(window)) {
                    btn_Exit.setBackColor(sf::Color(btn_col_dark));
                    if (event->is<sf::Event::MouseButtonPressed>()) {
                        statFile.open("Statistics.txt", std::ios::out | std::ios::trunc);
                        if (statFile.is_open()) {
                            statFile << "";
                            statFile.close();
                        }
                        window.close();
                    }
                }
                else {
                    btn_Exit.setBackColor(sf::Color(btn_col_reg));
                }
                break;
            }
            }
        }
        window.clear();
        if (screen == screens::MainMenu)
        {
            window.draw(bg_sprite);
            btn_PvP.drawTo(window);
            btn_PvE.drawTo(window);
            btn_Exit.drawTo(window);
            window.draw(txt_PvP);
            window.draw(txt_PvE);
            window.draw(txt_Exit);
        }

        if (screen == screens::FieldPlayer1)
        {
            if (!PvE)
            {
                window.draw(txt_player);
                window.draw(txt_placingText);
            }
            btn_endPlacingP1.drawTo(window);
            window.draw(txt_endPlacingP1);
            btn_randomPlacing.drawTo(window);
            window.draw(txt_randomPlacing);
            for (int i = 0; i < 10; ++i) {
                coordinateLetters[i].drawTo(window);
                coordinateNumbers[i].drawTo(window);
                window.draw(letters[i]);
                window.draw(numbers[i]);
                for (int j = 0; j < 10; ++j) {
                    player1Field[i][j].drawTo(window);
                }
            }

            for (int i = 0; i < 10; ++i) {
                for (int j = 0; j < 10; ++j) {
                    player1Field[i][j].setIndex(0);
                }
            }

            //update mouse
            mouse.Update(window);

            //updating ships cycle
            for (Ship* prop : shipsP1_container)
            {
                prop->Draggable(mouse);
                prop->Rotatable(mouse);
            }

            for (int i{}; i < 10; i++)
            {
                for (int j{}; j < 10; j++)
                {
                    //aligning all ships
                    for (Ship* prop : shipsP1_container)
                    {
                        player1Field[i][j].Alignbutton(mouse, *prop);
                        //setting an index to a cell if ship is not dragged
                        if (player1Field[i][j].ShipisOn(*prop) && !prop->isDragged)
                        {
                            player1Field[i][j].setIndex(1);
                        }
                    }
                }
            }

            //checking collisions
            for (Ship* prop : shipsP1_container)
            {
                if (player1Field[0][0].checkBoundary(*prop) || checkCollision(prop, shipsP1_container))
                    prop->color = sf::Color(255, 64, 64);
                else
                {
                    prop->updateLastValidPosition();
                    prop->color = sf::Color(0, 170, 255);
                }
            }

            //placing if incorrect collision during placing
            for (Ship* prop : shipsP1_container)
            {
                if (mouse.leftRelease)
                {
                    if (prop->color == sf::Color(255, 64, 64))
                        prop->revertToLastPosition();
                }
            }

            //aborting rotate if too close to other ships
            for (Ship* prop : shipsP1_container)
            {
                if (mouse.rightRelease)
                {
                    if (prop->color == sf::Color(255, 64, 64) && (mouse.x <= prop->x + 50.f && mouse.y <= prop->y + 200.f
                        && mouse.x >= prop->x && mouse.y >= prop->y || mouse.x <= prop->x + 200.f && mouse.y <= prop->y + 50.f
                        && mouse.x >= prop->x && mouse.y >= prop->y))
                    {
                        prop->wasClicked = true;
                    }
                }
            }

            //drawing
            for (Ship* prop : shipsP1_container)
            {
                prop->Draw(window);
            }

            //overlap
            for (Ship* prop : shipsP1_container)
            {
                if (prop->isDragged)
                    prop->Draw(window);
            }
        }

        if (screen == screens::FieldPlayer2)
        {
            window.draw(txt_player);
            window.draw(txt_placingText);
            btn_endPlacingP2.drawTo(window);
            window.draw(txt_endPlacingP2);
            btn_randomPlacing.drawTo(window);
            window.draw(txt_randomPlacing);
            for (int i = 0; i < 10; ++i) {
                coordinateLetters[i].drawTo(window);
                coordinateNumbers[i].drawTo(window);
                window.draw(letters[i]);
                window.draw(numbers[i]);
                for (int j = 0; j < 10; ++j) {
                    player2Field[i][j].drawTo(window);
                }
            }

            for (int i = 0; i < 10; ++i) {
                for (int j = 0; j < 10; ++j) {
                    player2Field[i][j].setIndex(0);
                }
            }

            //update mouse
            mouse.Update(window);

            //updating ships cycle
            for (Ship* prop : shipsP2_container)
            {
                prop->Draggable(mouse);
                prop->Rotatable(mouse);
            }

            for (int i{}; i < 10; i++)
            {
                for (int j{}; j < 10; j++)
                {
                    //aligning all ships
                    for (Ship* prop : shipsP2_container)
                    {
                        player2Field[i][j].Alignbutton(mouse, *prop);
                        //setting an index to a cell if ship is not dragged
                        if (player2Field[i][j].ShipisOn(*prop) && !prop->isDragged)
                        {
                            player2Field[i][j].setIndex(1);
                        }
                    }
                }
            }

            //checking collisions
            for (Ship* prop : shipsP2_container)
            {
                if (player2Field[0][0].checkBoundary(*prop) || checkCollision(prop, shipsP2_container))
                {

                    prop->color = sf::Color(255, 64, 64);
                }
                else
                {
                    prop->updateLastValidPosition();
                    prop->color = sf::Color(0, 170, 255);
                }
            }

            //placing if incorrect collision during placing
            for (Ship* prop : shipsP2_container)
            {
                if (mouse.leftRelease)
                {
                    if (prop->color == sf::Color(255, 64, 64))
                        prop->revertToLastPosition();
                }
            }

            //aborting rotate if too close to other ships
            for (Ship* prop : shipsP2_container)
            {
                if (mouse.rightRelease)
                {
                    if (prop->color == sf::Color(255, 64, 64) && (mouse.x <= prop->x + 50.f && mouse.y <= prop->y + 200.f
                        && mouse.x >= prop->x && mouse.y >= prop->y || mouse.x <= prop->x + 200.f && mouse.y <= prop->y + 50.f
                        && mouse.x >= prop->x && mouse.y >= prop->y))
                    {
                        prop->wasClicked = true;
                    }
                }
            }

            //drawing
            for (Ship* prop : shipsP2_container)
            {
                prop->Draw(window);
            }

            //overlap
            for (Ship* prop : shipsP2_container)
            {
                if (prop->isDragged)
                    prop->Draw(window);
            }
        }

        if (screen == screens::BattlePlayer1)
        {
            if (!PvE)
            {
                window.draw(txt_player);
            }
            window.draw(txt_turn);

            btn_seeField.drawTo(window);
            btn_saveStat.drawTo(window);
            window.draw(txt_seeField);
            window.draw(txt_saveStat);

            for (int i = 0; i < 10; ++i) {
                coordinateLetters[i].drawTo(window);
                coordinateNumbers[i].drawTo(window);
                window.draw(letters[i]);
                window.draw(numbers[i]);
                for (int j = 0; j < 10; ++j) {
                    player1BattleField[i][j].drawTo(window);
                }
            }
        }
        if (screen == screens::BattlePlayer2)
        {
            window.draw(txt_player);
            window.draw(txt_turn);

            btn_seeField.drawTo(window);
            btn_saveStat.drawTo(window);
            window.draw(txt_seeField);
            window.draw(txt_saveStat);

            for (int i = 0; i < 10; ++i) {
                coordinateLetters[i].drawTo(window);
                coordinateNumbers[i].drawTo(window);
                window.draw(letters[i]);
                window.draw(numbers[i]);
                for (int j = 0; j < 10; ++j) {
                    player2BattleField[i][j].drawTo(window);
                }
            }
        }
        if (screen == screens::CheckField1)
        {
            if (!PvE)
            {
                window.draw(txt_player);
            }
            window.draw(txt_turn);

            btn_seeField.drawTo(window);
            window.draw(txt_backToBattle);

            for (int i = 0; i < 10; ++i) {
                coordinateLetters[i].drawTo(window);
                coordinateNumbers[i].drawTo(window);
                window.draw(letters[i]);
                window.draw(numbers[i]);
                for (int j = 0; j < 10; ++j) {
                    player1CheckField[i][j].drawTo(window);
                }
            }
        }
        if (screen == screens::CheckField2)
        {
            window.draw(txt_player);
            window.draw(txt_turn);

            btn_seeField.drawTo(window);
            window.draw(txt_backToBattle);

            for (int i = 0; i < 10; ++i) {
                coordinateLetters[i].drawTo(window);
                coordinateNumbers[i].drawTo(window);
                window.draw(letters[i]);
                window.draw(numbers[i]);
                for (int j = 0; j < 10; ++j) {
                    player2CheckField[i][j].drawTo(window);
                }
            }
        }
        if (screen == screens::EndGame)
        {
            btn_saveEndStat.drawTo(window);
            btn_Exit.drawTo(window);
            window.draw(txt_saveEndStat);
            window.draw(txt_Exit);
            window.draw(txt_win);
        }
        window.display();
    }
}