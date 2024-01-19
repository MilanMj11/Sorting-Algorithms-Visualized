#pragma once
#include <SFML/Graphics.hpp>

void init_vector(std::vector<int>& a);
void randomise_vector(std::vector<int>& a);
void print_vector(std::vector<int>& a);
void reset_vector(std::vector<int>& a);
bool CheckSorted(std::vector<int>& a);

void destroy_references();

void slow_down();

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

void Draw_RadixSort(sf::RenderWindow& window);
void radixsort(std::vector<int>& a, int n, int base, sf::RenderWindow& window);

void Draw_InsertionSort(sf::RenderWindow& window);
void insertionsort(std::vector<int>& a, int n, sf::RenderWindow& window);

void Draw_ShellSort(sf::RenderWindow& window);
void shellsort(std::vector<int>& a, int n, sf::RenderWindow& window);

void Draw_HeapSort(sf::RenderWindow& window);
void heapify_arb(std::vector<int>& a, int n, int node, sf::RenderWindow& window);
void heapsort(std::vector<int>& a, int n, sf::RenderWindow& window);

void selectionsort(std::vector<int>& a, int n, sf::RenderWindow& window);
void Draw_SelectionSort(sf::RenderWindow& window);

void cocktailsort(std::vector<int>& a, int n, sf::RenderWindow& window);
void Draw_CocktailSort(sf::RenderWindow& window);