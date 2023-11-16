#include <SFML/Graphics.hpp>
#include <vector>
#include <unordered_map>

#include "features.hpp"
#include "display.hpp"
#include "Matrix.hpp"


void display_placement(Matrix placement, int width, int height) {
    // Initialize the SFML window (size is variable to the inputted room size)
    sf::RenderWindow window(sf::VideoMode(15 * width, 15 * height), "Placement");
    // Define the size and position of each box
    sf::Vector2f box_size(10, 10);
    sf::Vector2f box_position(10, 10);
    // Define the colors for each label
    std::unordered_map<char, sf::Color> colors = { {'B', sf::Color::Red}, 
            {'M', sf::Color(204, 73, 73)}, {'H', sf::Color::Green}, {'F', sf::Color(5, 135, 66)}, 
            {'K', sf::Color::Blue}, {'P', sf::Color(5, 48, 135)}, {'C', sf::Color(88, 63, 186)}, 
            {'W', sf::Color::Yellow}, {'D', sf::Color::Magenta}, {'L', sf::Color(245, 154, 56)}, 
            {'Z', sf::Color::White}, {'Q', sf::Color(64, 64, 0)}};

    // Draw the boxes in the SFML window
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        // all boxes start as black
        window.clear(sf::Color::Black);
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (placement.at(i, j) != 'E') {
                    sf::RectangleShape box(box_size);
                    // Draws a Bedroom
                    if (placement.at(i, j) == 'B') {
                        box.setFillColor(colors['B']);
                        box.setPosition(box_position.x + j * box_size.x, 
                            box_position.y + i * box_size.y);
                        box.setOutlineThickness(1.f);
                        box.setOutlineColor(sf::Color::Black);
                        window.draw(box);
                    }
                    // Draws a master bedroom
                    else if (placement.at(i, j) == 'M') {
                        box.setFillColor(colors['M']);
                        box.setPosition(box_position.x + j * box_size.x, 
                            box_position.y + i * box_size.y);
                        box.setOutlineThickness(1.f);
                        box.setOutlineColor(sf::Color::Black);
                        window.draw(box);
                    }
                    // Draws a Half Bathroom
                    else if (placement.at(i, j) == 'H') {
                        box.setFillColor(colors['H']);
                        box.setPosition(box_position.x + j * box_size.x, 
                            box_position.y + i * box_size.y);
                        box.setOutlineThickness(1.f);
                        box.setOutlineColor(sf::Color::Black);
                        window.draw(box);
                    }
                    // Draws a Full Bathroom
                    else if (placement.at(i, j) == 'F') {
                        box.setFillColor(colors['F']);
                        box.setPosition(box_position.x + j * box_size.x, 
                            box_position.y + i * box_size.y);
                        box.setOutlineThickness(1.f);
                        box.setOutlineColor(sf::Color::Black);
                        window.draw(box);
                    }
                    // Draws a kitchen
                    else if (placement.at(i, j) == 'K') {
                        box.setFillColor(colors['K']);
                        box.setPosition(box_position.x + j * box_size.x, 
                            box_position.y + i * box_size.y);
                        box.setOutlineThickness(1.f);
                        box.setOutlineColor(sf::Color::Black);
                        window.draw(box);
                    }
                    // Draws a pantry
                    else if (placement.at(i, j) == 'P') {
                        box.setFillColor(colors['P']);
                        box.setPosition(box_position.x + j * box_size.x, 
                            box_position.y + i * box_size.y);
                        box.setOutlineThickness(1.f);
                        box.setOutlineColor(sf::Color::Black);
                        window.draw(box);
                    }
                    // Draws a closet
                    else if (placement.at(i, j) == 'C') {
                        box.setFillColor(colors['C']);
                        box.setPosition(box_position.x + j * box_size.x, 
                            box_position.y + i * box_size.y);
                        box.setOutlineThickness(1.f);
                        box.setOutlineColor(sf::Color::Black);
                        window.draw(box);
                    }
                    // Draws a hallway
                    else if (placement.at(i, j) == 'W') {
                        box.setFillColor(colors['W']);
                        box.setPosition(box_position.x + j * box_size.x, 
                            box_position.y + i * box_size.y);
                        box.setOutlineThickness(1.f);
                        box.setOutlineColor(sf::Color::Black);
                        window.draw(box);
                    }
                    // Draws a dining room
                    else if (placement.at(i, j) == 'D') {
                        box.setFillColor(colors['D']);
                        box.setPosition(box_position.x + j * box_size.x, 
                            box_position.y + i * box_size.y);
                        box.setOutlineThickness(1.f);
                        box.setOutlineColor(sf::Color::Black);
                        window.draw(box);
                    }
                    // Draws a living room
                    else if (placement.at(i, j) == 'L') {
                        box.setFillColor(colors['L']);
                        box.setPosition(box_position.x + j * box_size.x, 
                            box_position.y + i * box_size.y);
                        box.setOutlineThickness(1.f);
                        box.setOutlineColor(sf::Color::Black);
                        window.draw(box);
                    }
                    //Draws Walls
                    else if (placement.at(i, j) == 'Z') {
                        box.setFillColor(colors['Z']);
                        box.setPosition(box_position.x + j * box_size.x, 
                            box_position.y + i * box_size.y);
                        box.setOutlineThickness(1.f);
                        box.setOutlineColor(sf::Color::Black);
                        window.draw(box);
                    }
                    // Draws Doors
                    else if (placement.at(i, j) == 'Q') {
                        box.setFillColor(colors['Q']);
                        box.setPosition(box_position.x + j * box_size.x, 
                            box_position.y + i * box_size.y);
                        box.setOutlineThickness(1.f);
                        box.setOutlineColor(sf::Color::Black);
                        window.draw(box);
                    }
                }
            }
        }
        window.display();
    }
}