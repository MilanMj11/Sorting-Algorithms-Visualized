#pragma once
#include <SFML/Graphics.hpp>

void init_vector(std::vector<int>& a);
void randomise_vector(std::vector<int>& a);
void print_vector(std::vector<int>& a);
void reset_vector(std::vector<int>& a);
bool CheckSorted(std::vector<int>& a);

void destroy_references();

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

int partitie(std::vector<int>& a, int low, int high, sf::RenderWindow& window);
void quicksort(std::vector<int>& a, int low, int high, sf::RenderWindow& window);
void Draw_QuickSort(sf::RenderWindow& window);