#include "../headers/globals.h"
#include "../headers/functions.h"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include <chrono>
#include <thread>

using namespace std;
using namespace sf;

int main()
{
    randomise_vector(a);
    for (int i = 0; i < N; i++) {
        aux[i] = a[i];
    }


    // ------------------------ Creating the visuals ----------------------
    createLines();
    createButtons();
    createText();
    // ------------------------ Creating the visuals ----------------------
    


    RenderWindow window(VideoMode(resolution_width, resolution_height), "Sorting Visualized");
    AppState currentState = AppState::Menu;
    int button_number = -1;
    bool solved = false;

    while (window.isOpen()) {
        
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
                currentState = AppState::Closing;
            }
            if (currentState == AppState::Menu and event.type == Event::MouseButtonReleased and event.mouseButton.button == Mouse::Left) {
                // MAYBE MOUSEBUTTONPRESSED

                Vector2i mousePosition = Mouse::getPosition(window);

                /// Check if mouse is over the button
                for (int i = 0; i < 9; i++) {
                    if (mousePosition.x > button[i].getPosition().x &&
                        mousePosition.x < button[i].getPosition().x + button[i].getSize().x &&
                        mousePosition.y > button[i].getPosition().y &&
                        mousePosition.y < button[i].getPosition().y + button[i].getSize().y) {
                        button_number = i;
                        break;
                    }
                }

                if (button_number != -1) {
                    /// Solving the pressed button;
                    currentState = AppState::Visualization;
                    continue;
                }

            }

            if (currentState == AppState::Visualization and event.type == Event::MouseButtonReleased and event.mouseButton.button == Mouse::Left) {
                currentState = AppState::Menu;
                button_number = -1;

                reset_vector(a);
                for (int i = 0; i < N; i++) {
                    rectangle[i].setSize(Vector2f(line_width, smallest_line + lines_height_diff * i)); /// dimensions of each line
                    rectangle[i].setFillColor(Color::White);         /// color
                    rectangle[i].setRotation(180);                   /// so I draw it from base up
                    rectangle[i].setPosition(10 + a[i] * lines_and_spaces, resolution_height - 10);     /// Position on the X axis
                }
            }

        }

        window.clear();
        
        
        if (currentState == AppState::Closing) {
            // destroy_references();
            return 0;
        }

        if (currentState == AppState::Menu) {
            // button_number = -1;
            /// DRAW THE MENU BUTTONS
            solved = false;
            for (int i = 0; i < 9; i++) {
                window.draw(button[i]);
                window.draw(text[i]);
            }

        }

        if (currentState == AppState::Visualization) {
            
            if (solved == false) {
                Solve(button_number, window);
                solved = true;
            }

            for (int i = 0; i < N; i++) {
                window.draw(rectangle[i]);
            }

        }

        window.display();

    }
    
    return 0;
}