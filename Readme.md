[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/K_t6ffJX)
# Prim's Algorithm with Min Heap and Adjacency Matrix

## Author
Sean Lumahan

## Description
My program creates a graph with a set number of vertices and creates weighted edges between those vertices, both based in main.cpp. An adjacency matrix is created in graph.h to hold the weight of the edges between two vertices (in this case, rows and columns). When primMST() is called, it finds the smallest weight possible to traverse all vertices in n-1 edges. It does this by inserting all edges into several different arrays in heap.h, accounting for the smallest edge weights, position, and the heap itself. At each iteration, it finds the cheapest vertex to traverse to and adjusts the arrays accordingly, repeating until the heap is empty. It prints out what the cheapest path is and the total weight of it all.

## Files
- graph.h / graph.cpp
- heap.h / heap.cpp
- main.cpp (unchanged)
- README.md

## How to Compile and Run
This project was developed and tested in CLion.  
Run directly from the IDE.

## Time Complexity Analysis


| Operation            | Time Complexity |
|----------------------|-----------------|
| Insert in MinHeap    | O(1)            |
| Extract Min          | O(n)            |
| Decrease Key         | O(n)            |
| Prim’s MST Overall   | O(n^3)          |

_Explain why your MST implementation has the above runtime._

Inserting into the MinHeap has a time complexity of O(1). Each insert adds to several arrays and increments the size, all of which have a linear time complexity. However, adding all objects has a time complexity of O(n) since the program loops through all the vertices.

Extract Min has a time complexity of O(n) since it has to loop through the position array to figure out which one has priority (meaning which one is the lowest value of the remaining vertices). I created two other loops for extractMin(), but since they are not nested loops, the time complexity remains at O(n).

Decrease Key, in my program, has a time complexity of O(n). While the majority of the function is O(1), including the line where the key is actually decreased, I call minHeapify() in the same function to maintain the order of the heap, which loops through the entire position array, making it an O(n) function.

Overall, my implementation of Prim's MST has a time complexity of O(n^3). The main loop is a while loop that checks if the heap is not empty. Inside is a nested loop that checks all specific matrix combinations with the extractMin() value to see if it should decrease the key for that given vertex. This main part of Prim's MST is O(n^2), but each time decreaseKey() runs successfully, minHeapify() is called which is another function that loops through the entire position array. These three loops give my program a time complexity of O(n^3), but a smaller time complexity is possible had I implemented several of the functions and arrays differently.

## Assumptions

I assumed it was given that no edges would be created that did not fit with the given number of vertices for a graph (like trying to add an edge to vertex 10 when only 5 vertices were created). I mention it later, but I created new arrays and functions to help get the keyValues and starting vertex for the edges. 

## Test Plan

I tested both the code provided in main.cpp and the sample code provided in the example on Canvas. I tested when a graph with 0 vertices was made (which ended up working normally assuming no edges were created as well). I also made sure that negative values couldn't be passed when creating the graph.

## Challenges Faced (Optional)

I kept confusing the three given arrays: heapArray, keyArray, and position. When I was writing the code, I kept calling the wrong arrays or didn't call the correct index, so I kept getting the wrong output. Another issue was implementing extractMin(), where I would always get the minimum with ease if the priority of the vertices matched their literal name (like where vertex 3 has greater priority than vertex 4). However, with the code in main.cpp, there comes a point where vertex 4 is reached before vertex 3, and my code did not properly handle these cases originally. After a half hour of fiddling, I eventually got it to work. One more issue (smaller though) was that I was struggling to keep track of which vertex started the smallest key to reach each vertex. In the end, I opted to create a new array and several functions to call the correct values.

## Test Case Description

Input:  

Graph g(5);

g.addEdge(0, 1, 2);

g.addEdge(0, 3, 6);

g.addEdge(1, 2, 3);

g.addEdge(1, 3, 8);

g.addEdge(1, 4, 5);

g.addEdge(2, 4, 7);

g.addEdge(3, 4, 9);

g.primMST();

---
Output:

0 -- 1 (2)

1 -- 2 (3)

1 -- 4 (5)

0 -- 3 (6)

Total Cost: 16