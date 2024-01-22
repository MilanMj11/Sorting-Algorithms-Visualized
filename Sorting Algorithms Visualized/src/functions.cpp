#include "..\headers\globals.h"
#include "..\headers\functions.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include <chrono>
#include <thread>
#include <list>

#include <iostream>

// ----------------------------------------- VECTOR RELATED ----------------------------------------------

void slow_down() {
    for (volatile int slow = 0; slow < SLOW; ++slow);
}

void init_vector(std::vector<int>& a) {
    for (int i = 0; i < N; i++)
        a[i] = i + 1;
}

void randomise_vector(std::vector<int>& a) {
    for (int i = 0; i < N; i++)
        a[i] = i + 1;

    std::random_device rd;
    std::mt19937 g(rd());

    shuffle(a.begin(), a.end(), g);
}

void print_vector(std::vector<int>& a) {
    for (int i = 0; i < N; i++)
        std::cout << a[i] << ' ';
}

void reset_vector(std::vector<int>& a) {
    for (int i = 0; i < N; i++) {
        a[i] = aux[i];
    }
}

bool CheckSorted(std::vector<int>& a) {
    bool ok = true;
    for (int i = 1; i < N; i++) {
        if (a[i] <= a[i - 1]) {
            ok = false;
            break;
        }
    }
    return ok;
}

// ----------------------------------------- VECTOR RELATED ----------------------------------------------


// --------------------------------------------- FOR VISUALIZATION ---------------------------------------

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

    if (!font.loadFromFile("res/fonts/bodoni/BodoniflfRoman-vmAD.ttf")) {
        std::cout << "Font Error!";
        return;
    }

    text[0].setString("Bubble Sort");
    text[1].setString("Merge Sort");
    text[2].setString("Quick Sort");
    text[3].setString("Selection Sort");
    text[4].setString("Radix Sort");
    text[5].setString("Heap Sort");
    text[6].setString("Shell Sort");
    text[7].setString("Cocktail Sort");
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

void destroy_references(){
    for (int i = 0; i < 9; i++) {
        text[i].setFont(sf::Font());
    }
}

void printVisualization(sf::RenderWindow& window) {
    window.clear();
    for (int t = 0; t < N; t++) {
        rectangle[t].setFillColor(sf::Color::White);
        rectangle[t].setPosition(10 + a[t] * lines_and_spaces, resolution_height - 10);
        window.draw(rectangle[t]);
    }
    window.display();
}

void printSlowVisualization(sf::RenderWindow& window) {
    window.clear();
    for (int t = 0; t < N; t++) {
        slow_down();
        rectangle[t].setFillColor(sf::Color::White);
        rectangle[t].setPosition(10 + a[t] * lines_and_spaces, resolution_height - 10);
        window.draw(rectangle[t]);
    }
    window.display();
}


void Solve(int buttonNumber, sf::RenderWindow& window) {

    window.clear();
    for (int i = 0; i < N; i++) {
        window.draw(rectangle[i]);
    }
    window.display();

    std::chrono::seconds duration(2);
    std::this_thread::sleep_for(duration);

    if (buttonNumber == 0) {
        Draw_BubbleSort(window);
    }
    if (buttonNumber == 1) {
        /// This is the Merge Sort
        /// !!!!! GET BACK ON THIS , IT'S NOT PROPERLY DONE
        Draw_MergeSort(window);
    }

    if (buttonNumber == 2) {
        Draw_QuickSort(window);
    }

    if (buttonNumber == 3) {
        Draw_SelectionSort(window);
    }

    if (buttonNumber == 4) {
        Draw_RadixSort(window);
    }

    if (buttonNumber == 5) {
        Draw_HeapSort(window);
    }

    if (buttonNumber == 6) {
        Draw_ShellSort(window);
    }

    if (buttonNumber == 7) {
        Draw_CocktailSort(window);
    }

    if (buttonNumber == 8) {
        Draw_InsertionSort(window);
    }

    Draw_SortedAnimation(window);

}

void Draw_SortedAnimation(sf::RenderWindow& window) {
    //window.clear();
    for (int i = 0; i < N; i++) {

        rectangle[i].setFillColor(sf::Color::Green);
        window.draw(rectangle[i]);
        window.display();
    }

}

// --------------------------------------------- FOR VISUALIZATION ---------------------------------------


// ------------------------------------- BUBBLE SORT ------------------------------------------

void Draw_BubbleSort(sf::RenderWindow& window) {

    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (a[i] > a[j]) {
                std::swap(a[i], a[j]);

                window.clear();

                rectangle[i].setPosition(10 + a[i] * lines_and_spaces, resolution_height - 10);
                rectangle[i].setFillColor(sf::Color::Red);
                rectangle[j].setPosition(10 + a[j] * lines_and_spaces, resolution_height - 10);
                rectangle[j].setFillColor(sf::Color::Red);
                window.draw(rectangle[i]);
                window.draw(rectangle[j]);


                for (int t = 0; t < N; t++) {
                    if (t == i or t == j) continue;
                    rectangle[t].setFillColor(sf::Color::White);
                    rectangle[t].setPosition(10 + a[t] * lines_and_spaces, resolution_height - 10);
                    window.draw(rectangle[t]);
                }
                window.display();

            }
        }
    }

}

// ------------------------------------- BUBBLE SORT ------------------------------------------


// --------------------------------------- MERGE SORT -----------------------------------------

void concat(std::vector<int>& a, int st, int dr, sf::RenderWindow& window) {
    int mij = (st + dr) / 2;
    int dim1 = mij - st + 1;
    int dim2 = dr - mij;

    int* b = new int[dim1 + 5];
    int* c = new int[dim2 + 5];

    int k = 0;
    for (int i = st; i <= mij; i++) b[++k] = a[i];
    b[++k] = INF;
    k = 0;
    for (int i = mij + 1; i <= dr; i++) c[++k] = a[i];
    c[++k] = INF;
    int ind1 = 1, ind2 = 1;
    k = st - 1;


    while (true) {
        if (b[ind1] == INF and c[ind2] == INF) break;
        if (b[ind1] < c[ind2] or c[ind2] == INF) {
            a[++k] = b[ind1];
            ind1++;
            continue;
        }
        if (b[ind1] >= c[ind2] or b[ind1] == INF) {
            a[++k] = c[ind2];
            ind2++;
            continue;
        }

        /*
        rectangle[b[ind1]].setFillColor(Color::Red);
        rectangle[c[ind2]].setFillColor(Color::Red);
        //printVisualization(window);
        */

    }
    delete[] b;
    delete[] c;
}

void merge_sort(std::vector<int>& a, int st, int dr, sf::RenderWindow& window) {
    if (st >= dr) return;
    int mij = (st + dr) / 2;

    merge_sort(a, st, mij, window);

    printSlowVisualization(window);

    merge_sort(a, mij + 1, dr, window);

    printSlowVisualization(window);

    concat(a, st, dr, window);


    printSlowVisualization(window);


}

void Draw_MergeSort(sf::RenderWindow& window) {
    merge_sort(a, 0, N - 1, window);
    printSlowVisualization(window);
}

// --------------------------------------- MERGE SORT -----------------------------------------


// --------------------------------------- QUICK SORT -----------------------------------------

int partitie(std::vector<int>& a,int low,int high,sf::RenderWindow& window) {
    int pivot = a[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (a[j] < pivot) {
            i++;
            std::swap(a[i], a[j]);

            window.clear();

            rectangle[i].setPosition(10 + a[i] * lines_and_spaces, resolution_height - 10);
            rectangle[i].setFillColor(sf::Color::Red);
            rectangle[j].setPosition(10 + a[j] * lines_and_spaces, resolution_height - 10);
            rectangle[j].setFillColor(sf::Color::Red);
            window.draw(rectangle[i]);
            window.draw(rectangle[j]);

            for (int t = 0; t < N; t++) {
                if (t == i or t == j) continue;
                slow_down();
                rectangle[t].setFillColor(sf::Color::White);
                rectangle[t].setPosition(10 + a[t] * lines_and_spaces, resolution_height - 10);
                window.draw(rectangle[t]);
            }
            window.display();

        }
    }
    std::swap(a[i + 1], a[high]);
    return i + 1;
}

void quicksort(std::vector<int>& a,int low,int high,sf::RenderWindow& window) {
    if (low < high) {
        long long mij = partitie(a, low, high, window);
        quicksort(a, low, mij - 1, window);
        quicksort(a, mij + 1, high, window);
    }
}

void Draw_QuickSort(sf::RenderWindow& window) {
    quicksort(a, 0, N-1, window);
    printVisualization(window);
}


// --------------------------------------- QUICK SORT -----------------------------------------


// --------------------------------------- RADIX SORT -----------------------------------------

void Draw_RadixSort(sf::RenderWindow& window) {
    radixsort(a, N, 10, window);
    printSlowVisualization(window);
}

void radixsort(std::vector<int>& a, int n, int base, sf::RenderWindow& window) {
    
    std::list<int> bucket[(1<<8)+5];

    long long p = 1;
    int maxim = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > maxim) maxim = a[i];
    }
    while (p <= maxim) {
        for (int i = 0; i < n; i++) {
            int cifra = (a[i] / p) % base;
            bucket[cifra].push_back(a[i]);
        }
        int ind = -1;
        for (int i = 0; i < base; i++) {
            while (!bucket[i].empty()) {
                a[++ind] = *(bucket[i].begin());
                bucket[i].erase(bucket[i].begin());

                printSlowVisualization(window);

            }
        }
        p *= base;
    }
    printSlowVisualization(window);
}

// --------------------------------------- RADIX SORT -----------------------------------------


// --------------------------------------- INSERTION SORT -----------------------------------------


void Draw_InsertionSort(sf::RenderWindow& window) {
    insertionsort(a, N, window);
    printVisualization(window);
}

void insertionsort(std::vector<int>& a, int n, sf::RenderWindow& window) {
    int key = 0;
    for (int i = 0; i < n; i++) {
        key = a[i];
        for (int j = i - 1; j >= 0; j--) {
            if (key < a[j]) {
                std::swap(a[j], a[j + 1]);
                key = a[j];

                window.clear();

                rectangle[j].setPosition(10 + a[i] * lines_and_spaces, resolution_height - 10);
                rectangle[j].setFillColor(sf::Color::Red);
                rectangle[j+1].setPosition(10 + a[j+1] * lines_and_spaces, resolution_height - 10);
                rectangle[j+1].setFillColor(sf::Color::Red);
                window.draw(rectangle[i]);
                window.draw(rectangle[j]);


                for (int t = 0; t < N; t++) {
                    if (t == j+1 or t == j) continue;
                    rectangle[t].setFillColor(sf::Color::White);
                    rectangle[t].setPosition(10 + a[t] * lines_and_spaces, resolution_height - 10);
                    window.draw(rectangle[t]);
                }
                window.display();


            }
            else break;
        }
    }
    
}


// --------------------------------------- INSERTION SORT -----------------------------------------



// --------------------------------------- SHELL SORT -----------------------------------------

void Draw_ShellSort(sf::RenderWindow& window) {
    shellsort(a, N, window);
    printSlowVisualization(window);
}

void shellsort(std::vector<int>& a,int n, sf::RenderWindow& window) {
    for (int gap = n / 2; gap >= 1; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int nr = a[i];
            int ind = i;
            while (ind >= gap and a[ind - gap] > nr) {
                a[ind] = a[ind - gap];

                printSlowVisualization(window);

                ind -= gap;
            }
            a[ind] = nr;

            window.clear();

            // printSlowVisualization(window);

        }
    }
}


// --------------------------------------- SHELL SORT -----------------------------------------



// --------------------------------------- HEAP SORT -----------------------------------------

void Draw_HeapSort(sf::RenderWindow& window) {
    heapsort(a, N, window);
    printSlowVisualization(window);
}

void heapify_arb(std::vector<int>& a, int n,int node, sf::RenderWindow& window) {
    if (n == 0) return; /// masura precautie
    int maxim = node;
    int st = 2 * node;
    int dr = 2 * node + 1;
    if (st < n and a[st] > a[maxim])
        maxim = st;
    if (dr < n and a[dr] > a[maxim])
        maxim = dr;
    if (node != maxim) { /// root not the biggest
        std::swap(a[node], a[maxim]);

        printSlowVisualization(window);

        heapify_arb(a, n, maxim, window);
    }
}

void heapsort(std::vector<int>& a,int n, sf::RenderWindow& window) {
    for (int i = n / 2; i >= 0; i--) /// construiesc max-heapul
        heapify_arb(a, n, i, window);
    for (int i = n-1; i >= 0; i--) {
        std::swap(a[1], a[i]); /// pun maximul in capat

        printSlowVisualization(window);

        /// maximul fiind mereu varful arborelui adica a[1];
        heapify_arb(a, i - 1, 1, window); /// get rid of last element
        /// e deja fixat
    }
}


// --------------------------------------- HEAP SORT -----------------------------------------

// ----------------------------------- SELECTION SORT ----------------------------------------

void selectionsort(std::vector<int>& a, int n,sf::RenderWindow& window)
{
    for (int i = 0; i < n - 1; i++) {

        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min_idx]) {
                min_idx = j;

                window.clear();

                rectangle[i].setPosition(10 + a[i] * lines_and_spaces, resolution_height - 10);
                rectangle[i].setFillColor(sf::Color::Red);
                rectangle[j].setPosition(10 + a[j] * lines_and_spaces, resolution_height - 10);
                rectangle[j].setFillColor(sf::Color::Red);
                window.draw(rectangle[i]);
                window.draw(rectangle[j]);

                for (int t = 0; t < N; t++) {
                    if (t == i or t == j) continue;
                    for (volatile int j = 0; j < 30000; ++j);
                    rectangle[t].setFillColor(sf::Color::White);
                    rectangle[t].setPosition(10 + a[t] * lines_and_spaces, resolution_height - 10);
                    window.draw(rectangle[t]);
                }

                window.display();
            
            }
            
        }

        if (min_idx != i) {

            std::swap(a[min_idx], a[i]);

            printSlowVisualization(window);

        }
    }
}

void Draw_SelectionSort(sf::RenderWindow& window) {
    selectionsort(a, N, window);
    printSlowVisualization(window);
}

// ----------------------------------- SELECTION SORT ----------------------------------------


// ----------------------------------- COCKTAIL SORT -----------------------------------------


void cocktailsort(std::vector<int>& a, int n, sf::RenderWindow& window) {
    bool swapped = true;
    int start = 0;
    int end = n - 1;
    while (swapped) {

        printVisualization(window);

        swapped = false;
        for (int i = start; i < end; ++i) {
            if (a[i] > a[i + 1]) {
                std::swap(a[i], a[i + 1]);
                swapped = true;

                window.clear();
                rectangle[i].setPosition(10 + a[i] * lines_and_spaces, resolution_height - 10);
                rectangle[i].setFillColor(sf::Color::Red);
                rectangle[i + 1].setPosition(10 + a[i + 1] * lines_and_spaces, resolution_height - 10);
                rectangle[i + 1].setFillColor(sf::Color::Red);
                window.draw(rectangle[i]);
                window.draw(rectangle[i + 1]);


                for (int t = 0; t < N; t++) {
                    if (t == i or t == i + 1) continue;
                    rectangle[t].setFillColor(sf::Color::White);
                    rectangle[t].setPosition(10 + a[t] * lines_and_spaces, resolution_height - 10);
                    window.draw(rectangle[t]);
                }
                window.display();

            }
        }
        if (!swapped)
            break;

        swapped = false;
        --end;
        for (int i = end - 1; i >= start; --i) {
            if (a[i] > a[i + 1]) {
                std::swap(a[i], a[i + 1]);
                swapped = true;

                window.clear();
                rectangle[i].setPosition(10 + a[i] * lines_and_spaces, resolution_height - 10);
                rectangle[i].setFillColor(sf::Color::Red);
                rectangle[i+1].setPosition(10 + a[i+1] * lines_and_spaces, resolution_height - 10);
                rectangle[i+1].setFillColor(sf::Color::Red);
                window.draw(rectangle[i]);
                window.draw(rectangle[i+1]);


                for (int t = 0; t < N; t++) {
                    if (t == i or t == i+1) continue;
                    rectangle[t].setFillColor(sf::Color::White);
                    rectangle[t].setPosition(10 + a[t] * lines_and_spaces, resolution_height - 10);
                    window.draw(rectangle[t]);
                }
                window.display();

            }
        }
        ++start;
    }
}

void Draw_CocktailSort(sf::RenderWindow& window) {
    cocktailsort(a, N, window);
    printVisualization(window);
}

// ----------------------------------- COCKTAIL SORT -----------------------------------------