#ifndef HEAP_H
#define HEAP_H

class MinHeap {
public:
    MinHeap(int capacity) {
        this->capacity = capacity;
        heapArray = new int[capacity];
        keyArray = new int[capacity];
        position = new int[capacity];

        startEdgeVertex = new int[capacity];

        size = 0;
    };

    ~MinHeap() {
        delete[] heapArray;
        delete[] keyArray;
        delete[] position;
        delete[] startEdgeVertex;
    };

    void insert(int vertex, int key) {
        heapArray[vertex] = vertex;
        position[vertex] = vertex;
        keyArray[vertex] = key;
        startEdgeVertex[vertex] = vertex;

        size++; // Increase the counter for the number of vertices in heapArray
    };

    int extractMin() {
        int min = heapArray[0];

        for (int i = 0; i < capacity; i++) {
            if (position[i] == 0 && isInMinHeap(i)) {
                min = i; // Grab the smallest number from heapArray using the position array
            }
        }

        int savedHeapPosition = 0;

        for (int i = 0; i < capacity; i++) { // Find where exactly the minimum lies in heapArray
            if (heapArray[i] == min) {
                savedHeapPosition = i;
            }
        }

        for (int i = savedHeapPosition; i < size - 1; i++) { // Move all subsequent vertices in heapArray down one
            heapArray[i] = heapArray[i + 1];
            position[heapArray[i]] = i;
        }

        size--; // Decrease the size by one

        return min; // Return the lowest cost vertex to move to
    };

    void decreaseKey(int vertex, int newKey, int lowestCostVertex) {
        if (newKey < keyArray[vertex]) { // Check if the new weight would be less than the old weight
            keyArray[vertex] = newKey;
            startEdgeVertex[vertex] = lowestCostVertex; // Save the vertex from which the edge starts
        }

        minHeapify(vertex);
    };

    bool isInMinHeap(int vertex) { // Check if vertex is in the heapArray
        for (int i = 0; i < size; i++) {
            if (heapArray[i] == vertex) {
                return true;
            }
        }
        return false;
    };

    bool isEmpty() {
        return size == 0;
    };

    int getKeyValue(int vertex) { // Custom function to get the edge weight from keyArray
        return keyArray[vertex];
    }

    int getEdgeStartVertex(int vertex) { // Custom function to get the vertex where the edge starts from
        return startEdgeVertex[vertex];
    }

private:
    int* heapArray;        // Heap of vertex indices
    int* keyArray;         // Corresponding key values
    int* position;         // Maps vertex to its position in heap
    int capacity;
    int size;

    int* startEdgeVertex; // Saved starting vertices for the lowest found edge

    void minHeapify(int idx) { // Modify the position array
        while (idx > 0) {
            if (keyArray[idx] != NULL && keyArray[idx] < keyArray[idx - 1] && isInMinHeap(idx - 1)) {
                position[idx] = position[idx] - 1; // Swap the two adjacent positions
                position[idx - 1] = position[idx] + 1;
            }
            idx--;
        }
    };
};

#endif