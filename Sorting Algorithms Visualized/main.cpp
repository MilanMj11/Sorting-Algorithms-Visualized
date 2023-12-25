#include <SFML/Graphics.hpp>
#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include <chrono>
#include <thread>


using namespace std;
using namespace sf;

int resolution_width = 1920;
int resolution_height = 1080;

const int N = 200;
vector<int> a(N);

RectangleShape rectangle[N];

float actual_display_width = resolution_width - 20;     /// 20 - represents the spaces to the edge of the screen
float lines_and_spaces = actual_display_width / N;
float line_width = 8.0 * (lines_and_spaces / 10.0);   /// 80% line
float space_width = 2.0 * (lines_and_spaces / 10.0);  /// 20% space

float actual_display_height = resolution_height - 20;
float smallest_line = 5;
float lines_height_diff = (actual_display_height - smallest_line) / (N - 1);

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

int main()
{
    //init_vector(a);
    randomise_vector(a);
    print_vector(a);


    // ------------------------------------- CREATING LINES -----------------------------

    for (int i = 0; i < N; i++) {
        rectangle[i].setSize(Vector2f(line_width,smallest_line + lines_height_diff * i)); /// dimensions of each line
        rectangle[i].setFillColor(Color::White);         /// color
        rectangle[i].setRotation(180);                   /// so I draw it from base up
        rectangle[i].setPosition(10 + a[i] * lines_and_spaces, resolution_height - 10);     /// Position on the X axis
    }


    // ------------------------------------- CREATING LINES -----------------------------
   
    RenderWindow window(VideoMode(resolution_width, resolution_height), "Sorting Visualized");
    
    if (window.isOpen()) {
        for (int i = 0; i < N; i++) {
            window.draw(rectangle[i]);
        }
    }
    window.display();

    chrono::seconds duration(2);
    this_thread::sleep_for(duration);

    bool sorted = false;

    while (window.isOpen()) {
        
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();
        
        /*
        for (int i = 0; i < N; i++) {
            window.draw(rectangle[i]);
        }
        */
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

        window.display();

    }

    return 0;
}