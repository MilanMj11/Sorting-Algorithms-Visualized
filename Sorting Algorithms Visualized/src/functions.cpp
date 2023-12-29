#include "..\headers\globals.h"
#include "..\headers\functions.h"
#include <SFML/Graphics.hpp>

#include <iostream>

void createLines() {
    /// this creates the shape of the rectangles.
    for (int i = 0; i < N; i++) {
        rectangle[i].setSize(sf::Vector2f(line_width, smallest_line + lines_height_diff * i)); /// dimensions of each line
        rectangle[i].setFillColor(sf::Color::White);                                           /// color
        rectangle[i].setRotation(180);                                                         /// so I draw it from base up
        rectangle[i].setPosition(10 + a[i] * lines_and_spaces, resolution_height - 10);        /// Position on the X axis
    }
}

void createButtons() {
    for (int i = 0; i < 9; i++) {
        button[i].setSize(sf::Vector2f(buttonWidth, buttonHeight));
    }
    for (int i = 0; i < 9; i++) {
        button[i].setPosition(sf::Vector2f(columnSection * (i % 3) + columnSection * 1.5 / 10.0, lineSection * (i / 3) + lineSection * 1.5 / 10.0));
    }
}

void createText() {

    
    if (!font.loadFromFile("res/fonts/coolvetica/coolvetica rg.otf")) {
        std::cout << "Font Error!";
        return;
    }
    

    text[0].setString("Bubble Sort");
    text[1].setString("Merge Sort");
    text[2].setString("Quick Sort");
    text[3].setString("Selection Sort");
    text[4].setString("Radix Sort");
    text[5].setString("Heap Sort");
    text[6].setString("Bucket Sort");
    text[7].setString("Counting Sort");
    text[8].setString("Insertion Sort");

    float centerX, centerY;
    
    for (int i = 0; i < 9; i++) {
        text[i].setFont(font);
        text[i].setCharacterSize(fontSize);
        
        sf::FloatRect textBounds = text[i].getLocalBounds();
        sf::FloatRect rectBounds = button[i].getLocalBounds();
        text[i].setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);

        centerX = button[i].getPosition().x + rectBounds.width / 2;
        centerY = button[i].getPosition().y + rectBounds.height / 2;

        text[i].setPosition(centerX, centerY);
        text[i].setFillColor(sf::Color::Black);
        
    }
    
}