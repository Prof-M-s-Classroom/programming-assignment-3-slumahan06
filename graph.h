#ifndef GRAPH_H
#define GRAPH_H
#include "heap.h"

using namespace std;

class Graph {
public:
    Graph(int vertices) {
        numVertices = vertices;
        adjMatrix = new int*[vertices];
        for (int i = 0; i < vertices; i++) {
            adjMatrix[i] = new int[vertices];
            for (int j = 0; j < vertices; j++) {
                if (i == j) {
                    adjMatrix[i][j] = 0;
                }
            }
        }
    };

    ~Graph() { //TODO: Destructor
        delete adjMatrix;
    };

    void addEdge(int u, int v, int weight) {
        adjMatrix[u][v] = weight;
        adjMatrix[v][u] = weight;
    };

    void primMST() {
        cout << "Testing Prim's MST" << endl; // Start at vertex 0

        MinHeap minHeap(numVertices);
        int totalCost = 0;

        while (!minHeap.isEmpty()) {
            int lowestCost = minHeap.extractMin();

            cout << lowestCost << " -- ";

            for (int i = 0; i < numVertices; i++) {
                if (adjMatrix[lowestCost][i] != NULL && adjMatrix[lowestCost][i] != 0) {
                    minHeap.decreaseKey(i, adjMatrix[lowestCost][i]);
                }
            }

            cout << endl;
        }

        cout << "Total Cost: " << totalCost << endl;
    };  // Must print MST edges and total weight

private:
    int** adjMatrix;
    int numVertices;
};

#endif