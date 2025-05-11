#ifndef HEAP_H
#define HEAP_H

class MinHeap {
public:
    MinHeap(int capacity) {
        this->capacity = capacity;
        heapArray = new int[capacity];
        keyArray = new int[capacity];
        position = new int[capacity];
    };

    ~MinHeap() { //TODO: Destructor
        delete heapArray;
        delete keyArray;
        delete position;
    };

    void insert(int vertex, int key) { // Step 1
        keyArray[vertex] = key;
        //minHeapify()
    };

    int extractMin() { // Step 3 (grab the smallest number)
        int min = keyArray[heapArray[0]];

        for (int i = 0; i < capacity; i++) {
            if (keyArray[i] != NULL && keyArray[i] < min) { //isInMinHeap(i)
                min = i;
            }
        }

        //TODO : Delete the lowest cost vertex to traverse to?

        size--;

        //TODO : Update positions

        return min; // Return the lowest cost vertex to move to
    };

    void decreaseKey(int vertex, int newKey) {
        keyArray[vertex] = newKey;
    };

    bool isInMinHeap(int vertex) {
        for (int i = 0; i < capacity; i++) { // Switch to size rather than capacity?
            if (heapArray[i] == vertex) {
                return true;
            }
        }
        return false;
    };

    bool isEmpty() {
        return size == 0;
    };

private:
    int* heapArray;        // Heap of vertex indices
    int* keyArray;         // Corresponding key values
    int* position;         // Maps vertex to its position in heap
    int capacity;
    int size;

    void minHeapify(int idx); //MinHeapify as insertions happen 2
};

#endif