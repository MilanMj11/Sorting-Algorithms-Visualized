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

int resolution_width = 1920;
int resolution_height = 1080;

const int N = 200;
vector<int> a(N);

RectangleShape rectangle[N];

float actual_display_width = resolution_width - 20;     /// 20 - represents the spaces to the edge of the screen ( 10 + 10 )
float lines_and_spaces = actual_display_width / N;
float line_width = 8.0 * (lines_and_spaces / 10.0);   /// 80% line
float space_width = 2.0 * (lines_and_spaces / 10.0);  /// 20% space

float actual_display_height = resolution_height - 20;
float smallest_line = 5;
float lines_height_diff = (actual_display_height - smallest_line) / (N - 1);

enum class AppState {
    Menu,
    Visualization
};

/// --------------------------------- INITIAL VALUES ----------------------------------------

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

void Solve(int buttonNumber) {

    if (buttonNumber == 0) {
        /// This is the Bubble Sort

    }

}

int main()
{
    //init_vector(a);
    randomise_vector(a);
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

    while (window.isOpen()) {
        
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();

            if (event.type == Event::MouseButtonPressed and event.mouseButton.button == Mouse::Left) {

                Vector2i mousePosition = Mouse::getPosition(window);

                /// Check if mouse is over the button
                int button_number = -1;
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
                    Solve(button_number);
                }

            }
        }

        window.clear();
        
        
        if (currentState == AppState::Menu) {
            
            /// DRAW THE MENU BUTTONS
            for (int i = 0; i < 9; i++) {
                window.draw(button[i]);
                window.draw(text[i]);
            }

        }

        /*
        if(CheckSorted(a) == false)
            Draw_BubbleSort(window);
        else {
            if (sorted == false) {
                Draw_SortedAnimation(window);
                sorted = true;
            }
            for (int i = 0; i < N; i++) {
                window.draw(rectangle[i]);
            }
        }
        */

        window.display();

    }

    return 0;
}