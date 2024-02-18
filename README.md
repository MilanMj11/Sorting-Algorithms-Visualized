# Sorting Algorithms Visualized with C++ and SFML

## Overview
This project showcases the visualization of 9 different sorting algorithms, which are not necessarily perfectly optimised because the purpose of this project is to show how each of them modelates the array to be sorted, not to obtain the fastest time of execution.

## Highlights

- **Visual Delight:** Experience sorting algorithms in a visually captivating display.

- **Learn by Watching:** Quickly grasp how different sorting methods operate.

- **Interactive Fun:** Play with the visuals and see the magic happen in real-time.

- **Algorithm Variety:** From slow and simple algorithms like Bubble Sort to lightning-fast practical algorithms like Quick Sort.

- **SFML Smoothness:** The visuals are powered by SFML for a sleek and eye-catching experience.

## Sorting Lineup

1. Bubble Sort
2. Merge Sort
3. Quick Sort
4. Selection Sort
5. Radix Sort
6. Heap Sort
7. Shell Sort
8. Cocktail Sort
9. Insertion Sort

## Notes
The visualization was done so that it can be compatible with any resolution that you choose ( the standard being 1920*1080 ) . Each algorithm sorts the same array of 1000 randomised elements, but each execution randomises the array in a different way ( meaning I don't have a set seed beforehand ) . 
The project was made in such a way that each algorithm takes approximately the same time to execute, which is why some faster sorting algorithms were intentionally slowed down so that they could be viewed in more detail.

And don't forget to run it in "Release" mode.

## SFML Elements
The SFML library was not used to it's fullest potential, in fact, I've used the simplest elements such as : Creating and drawing rectangles, Creating a window and Writing Text.
Each element from the array is represented by a Rectangle which is taller or shorter depending on the value of the element.

## Important ! 
Depending on how fast a computer is, the speed of the visualizations might differ. If the app is too slow or too fast, you might need to change the variable SLOW in globals.cpp. The default is 21337

The bigger SLOW is, the slower the app will run and vice versa.

```bash
const int SLOW = 21337;
```

## Preview

![image](https://github.com/MilanMj11/Sorting-Algorithms-Visualized/assets/87907265/8fec8f25-9057-44f3-a37e-ff3b0b6cbfae)
![image](https://github.com/MilanMj11/Sorting-Algorithms-Visualized/assets/87907265/807d41fb-d3b7-4058-8a94-0df1ed38aed6)


