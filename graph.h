#ifndef GRAPH_H
#define GRAPH_H
#include "heap.h"

using namespace std;

class Graph {
public:
    Graph(int vertices) {
        numVertices = vertices;
        adjMatrix = new int*[vertices];

        if (vertices > 0) { // Ensure negative values can't be plugged in
            for (int i = 0; i < vertices; i++) { // Create rows
                adjMatrix[i] = new int[vertices];
                for (int j = 0; j < vertices; j++) { // Create columns
                    adjMatrix[i][j] = NULL;
                    if (i == j) {
                        adjMatrix[i][j] = 0; // Set the weight to 0 for the major diagonal
                    }
                }
            }
        }
    };

    ~Graph() {
        for (int i =0; i < numVertices; i++) {
            delete[] adjMatrix[i]; // Delete the rows
        }

        delete[] adjMatrix;
    };

    void addEdge(int u, int v, int weight) {
        adjMatrix[u][v] = weight; // Set both combinations of the vertices to the edge weight
        adjMatrix[v][u] = weight;
    };

    void primMST() {
        //cout << "Testing Prim's MST" << endl;

        MinHeap minHeap(numVertices);
        int totalCost = 0;

        for (int i = 0; i < numVertices; i++) {
            if (i == 0) {
                minHeap.insert(0,0); // Start at vertex 0
            } else {
                minHeap.insert(i, INT_MAX); // Add other vertices with INFINITY (originally used NULL)
            }
        }

        while (!minHeap.isEmpty()) {
            int lowestCostVertex = minHeap.extractMin(); // Get the smallest vertex to traverse to
            int cost = minHeap.getKeyValue(lowestCostVertex); // Get the cost (custom function)
            totalCost += cost;

            if (lowestCostVertex != 0) {
                cout << minHeap.getEdgeStartVertex(lowestCostVertex) << " -- " << lowestCostVertex << " ("<< cost << ")" << endl; // Prints the next vertex to be reached
            }

            for (int i = 0; i < numVertices; i++) {
                if (adjMatrix[lowestCostVertex][i] != 0 && minHeap.isInMinHeap(i)) { // Check for any new neighbors
                    minHeap.decreaseKey(i, adjMatrix[lowestCostVertex][i], lowestCostVertex); // Try decreasing the key
                }
            }
        }

        cout << "Total Cost: " << totalCost << endl;
    };  // Must print MST edges and total weight

private:
    int** adjMatrix;
    int numVertices;
};

#endif