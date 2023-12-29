#pragma once
#include <SFML/Graphics.hpp>

void createLines();
void createButtons();
void createText();
void Solve(int buttonNumber, sf::RenderWindow& window);
void Draw_SortedAnimation(sf::RenderWindow& window);
void Draw_BubbleSort(sf::RenderWindow& window);

void Draw_MergeSort(sf::RenderWindow& window);
void merge_sort(std::vector<int>& a, int st, int dr, sf::RenderWindow& window);
void printVisualization(sf::RenderWindow& window);
void concat(std::vector<int>& a, int st, int dr, sf::RenderWindow& window);