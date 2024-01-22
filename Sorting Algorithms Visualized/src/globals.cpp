#include "../headers/globals.h"

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

int resolution_width = 1920;
int resolution_height = 1080;

const int INF = (1 << 29);

const int SLOW = 21337;

const int N = 500;
std::vector<int> a(N);
std::vector<int> aux(N);



// ---------------------------------------------------- FOR RECTANGLES ----------------------------------------------------

sf::RectangleShape rectangle[N];

float actual_display_width = resolution_width - 20;     /// 20 - represents the spaces to the edge of the screen ( 10 + 10 )
float lines_and_spaces = actual_display_width / N;
float line_width = 8.0 * (lines_and_spaces / 10.0);   /// 80% line
float space_width = 2.0 * (lines_and_spaces / 10.0);  /// 20% space

float actual_display_height = resolution_height - 20;
float smallest_line = 5;
float lines_height_diff = (actual_display_height - smallest_line) / (N - 1);

// ---------------------------------------------------- FOR RECTANGLES ----------------------------------------------------


// --------------------------------------------------- BUTTONS AND TEXT ---------------------------------------------------

float lineSection = (resolution_height / 3.0);
float buttonHeight = (lineSection * 7.0 / 10.0);


float columnSection = (resolution_width / 3.0);
float buttonWidth = (columnSection * 7.0 / 10.0);

sf::RectangleShape button[9];

unsigned int fontSize = 75;
sf::Font font;
sf::Text text[9];

// --------------------------------------------------- BUTTONS AND TEXT ---------------------------------------------------