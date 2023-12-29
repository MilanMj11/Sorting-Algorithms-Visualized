#include "../headers/globals.h"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include <chrono>
#include <thread>

using namespace std;
using namespace sf;

/// --------------------------------- INITIAL VALUES ----------------------------------------


/// --------------------------------- INITIAL VALUES ----------------------------------------

void printVisualization(RenderWindow &);

void init_vector(vector<int>& a) {
    for (int i = 0; i < N; i++)
        a[i] = i + 1;
}

void randomise_vector(vector<int> &a) {
    for (int i = 0; i < N; i++)
        a[i] = i + 1;

    random_device rd;
    mt19937 g(rd());

    shuffle(a.begin(), a.end(), g);
}

void print_vector(vector<int> &a) {
    for (int i = 0; i < N; i++)
        cout << a[i] << ' ';
}

void reset_vector(vector<int>& a) {
    for (int i = 0; i < N; i++) {
        a[i] = aux[i];
    }
}

void Draw_BubbleSort(RenderWindow &window) {
    
    for (int i = 0; i < N-1; i++) {
        for (int j = i+1; j < N; j++) {
            if (a[i] > a[j]) {
                swap(a[i], a[j]);

                window.clear();

                rectangle[i].setPosition(10 + a[i] * lines_and_spaces, resolution_height - 10);
                rectangle[i].setFillColor(Color::Red);
                rectangle[j].setPosition(10 + a[j] * lines_and_spaces, resolution_height - 10);
                rectangle[j].setFillColor(Color::Red);
                window.draw(rectangle[i]);
                window.draw(rectangle[j]);


                for (int t = 0; t < N; t++) {
                    if (t == i or t == j) continue;
                    rectangle[t].setFillColor(Color::White);
                    rectangle[t].setPosition(10 + a[t] * lines_and_spaces, resolution_height - 10); 
                    window.draw(rectangle[t]);
                }
                window.display();

            }
        }
    }

}

bool CheckSorted(vector<int>& a) {
    bool ok = true;
    for (int i = 1; i < N; i++) {
        if (a[i] <= a[i - 1]) {
            ok = false;
            break;
        }
    }
    return ok;
}

void Draw_SortedAnimation(RenderWindow &window) {
    //window.clear();
    for (int i = 0; i < N; i++) {

        rectangle[i].setFillColor(Color::Green);
        window.draw(rectangle[i]);
        window.display();
    }

}


///____________________________________________
void concat(vector<int> &a, int st, int dr, RenderWindow &window) {
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

void printVisualization(RenderWindow& window) {
    window.clear();
    for (int t = 0; t < N; t++) {
        rectangle[t].setFillColor(Color::White);
        rectangle[t].setPosition(10 + a[t] * lines_and_spaces, resolution_height - 10);
        window.draw(rectangle[t]);
    }
    window.display();
}

void merge_sort(vector<int> &a, int st, int dr, RenderWindow &window) {
    if (st >= dr) return;
    int mij = (st + dr) / 2;

    merge_sort(a, st, mij, window);

    printVisualization(window);

    merge_sort(a, mij + 1, dr, window);

    printVisualization(window);

    concat(a, st, dr, window);


    printVisualization(window);


}
///____________________________________________

void Draw_MergeSort(RenderWindow& window) {
    merge_sort(a, 0, N-1, window);
}

void Solve(int buttonNumber, RenderWindow &window) {

    window.clear();
    for (int i = 0; i < N; i++) {
        window.draw(rectangle[i]);
    }
    window.display();

    chrono::seconds duration(2);
    this_thread::sleep_for(duration);

    if (buttonNumber == 0) {
        /// This is the Bubble Sort
        
        Draw_BubbleSort(window);
        Draw_SortedAnimation(window);
    }

    if (buttonNumber == 1) {
        /// This is the Merge Sort
        /// !!!!! GET BACK ON THIS , IT'S NOT PROPERLY DONE
        Draw_MergeSort(window);
        Draw_SortedAnimation(window);
    }
        
    if (buttonNumber == 2) {
        /// This si the Quick Sort

    }

}

int main()
{
    //init_vector(a);
    randomise_vector(a);
    for (int i = 0; i < N; i++) {
        aux[i] = a[i];
    }
    //print_vector(a);



    // ------------------------------------- CREATING LINES -----------------------------

    for (int i = 0; i < N; i++) {
        rectangle[i].setSize(Vector2f(line_width,smallest_line + lines_height_diff * i)); /// dimensions of each line
        rectangle[i].setFillColor(Color::White);         /// color
        rectangle[i].setRotation(180);                   /// so I draw it from base up
        rectangle[i].setPosition(10 + a[i] * lines_and_spaces, resolution_height - 10);     /// Position on the X axis
    }


    // ------------------------------------- CREATING LINES -----------------------------


    // ------------------------------------- CREATING BUTTONS AND TEXT -------------------------------

    float lineSection = (resolution_height / 3.0);
    float buttonHeight = (lineSection * 7.0 / 10.0);

    float columnSection = (resolution_width / 3.0);
    float buttonWidth = (columnSection * 7.0 / 10.0);

    RectangleShape button[9];
    for (int i = 0; i < 9; i++) {
        button[i].setSize(Vector2f(buttonWidth, buttonHeight));
    }

    for (int i = 0; i < 9; i++) {
        button[i].setPosition(Vector2f(columnSection * (i % 3) + columnSection * 1.5 / 10.0, lineSection * (i / 3) + lineSection * 1.5 / 10.0));
    }

    Font font;
    if (!font.loadFromFile("res/fonts/coolvetica/coolvetica rg.otf")) {
        cout << "Font Error!";
        return 1;
    }

    float fontSize = 70;
    float centerX, centerY;
    
    Text text[9];

    text[0].setString("Bubble Sort");
    text[1].setString("Merge Sort");
    text[2].setString("Quick Sort");
    text[3].setString("Selection Sort");
    text[4].setString("Radix Sort");
    text[5].setString("Heap Sort");
    text[6].setString("Bucket Sort");
    text[7].setString("Counting Sort");
    text[8].setString("Insertion Sort");

    for (int i = 0; i < 9; i++) {
        text[i].setFont(font);
        text[i].setCharacterSize(fontSize);

        FloatRect textBounds = text[i].getLocalBounds();
        FloatRect rectBounds = button[i].getLocalBounds();
        text[i].setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);

        centerX = button[i].getPosition().x + rectBounds.width / 2;
        centerY = button[i].getPosition().y + rectBounds.height / 2;

        text[i].setPosition(centerX, centerY);
        text[i].setFillColor(Color::Black);
    }

    // ------------------------------------- CREATING BUTTONS AND TEXT -------------------------------


    RenderWindow window(VideoMode(resolution_width, resolution_height), "Sorting Visualized");
    AppState currentState = AppState::Menu;
    int button_number = -1;
    bool solved = false;

    while (window.isOpen()) {
        
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();

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

            /*
            */
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