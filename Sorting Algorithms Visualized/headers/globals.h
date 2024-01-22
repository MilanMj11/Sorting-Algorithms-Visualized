#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>



extern int resolution_width;
extern int resolution_height;

extern const int INF;

extern const int SLOW;

extern const int N;
extern std::vector<int> a;
extern std::vector<int> aux;

extern sf::RectangleShape rectangle[];

extern float actual_display_width;    
extern float lines_and_spaces;
extern float line_width;
extern float space_width;

extern float actual_display_height;
extern float smallest_line;
extern float lines_height_diff;

extern sf::RectangleShape button[];

extern sf::Font font;
extern sf::Text text[];
extern unsigned int fontSize;

extern float lineSection;
extern float buttonHeight;

extern float columnSection;
extern float buttonWidth;


enum class AppState {
    Menu,
    Visualization,
    Closing
};