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
                adjMatrix[i][j] = NULL;
                if (i == j) {
                    adjMatrix[i][j] = 0;
                }
            }
        }
    };

    ~Graph() {
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

        for (int i = 0; i < numVertices; i++) {
            if (i == 0) {
                minHeap.insert(0,0);
            } else {
                minHeap.insert(i, INT_MAX); // OR MAYBE max value to stop having to check for NULL?
            }
        }

        while (!minHeap.isEmpty()) {
            int lowestCostVertex = minHeap.extractMin();
            int cost = minHeap.getKeyValue(lowestCostVertex);
            totalCost += cost;

            if (lowestCostVertex != 0) {
                cout << minHeap.getEdgeStartVertex(lowestCostVertex) << " -- " << lowestCostVertex << " ("<< cost << ")" << endl; // Prints the next vertex to be reached
            }

            for (int i = 0; i < numVertices; i++) {
                if (adjMatrix[lowestCostVertex][i] != 0 && minHeap.isInMinHeap(i)) { // If there's an edge
                    minHeap.decreaseKey(i, adjMatrix[lowestCostVertex][i], lowestCostVertex);
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