#include<stdio.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX_NODES 100

unsigned char adjacencyMatrix[MAX_NODES][MAX_NODES / 8 + 1];

void insertEdge(int x, int y) {
    adjacencyMatrix[x][y / 8] |= (1 << (y % 8));
    adjacencyMatrix[y][x / 8] |= (1 << (x % 8));
}

void deleteEdge(int x, int y) {
    adjacencyMatrix[x][y / 8] &= ~(1 << (y % 8));
    adjacencyMatrix[y][x / 8] &= ~(1 << (x % 8));
}

bool isNeighbor(int x, int y) {
    return (adjacencyMatrix[x][y / 8] & (1 << (y % 8))) != 0;
}

void getNeighbors(int n, int numNodes) {
    printf("Neighbors of node %d: ", n);
    for (int i = 0; i < numNodes; i++) {
        if (isNeighbor(n, i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}


bool DFS(int x, int y, int visited[], int path[], int numNodes) {
    visited[x] = 1;
    path[path[0] + 1] = x;
    path[0]++;

    if (x == y) {
        for (int i = 1; i <= path[0]; i++) {
            printf("%d ", path[i]);
        }
        printf("\n");
        return true;
    }

    for (int i = 0; i < numNodes; i++) {
        if (isNeighbor(x, i) && !visited[i]) {
            if (DFS(i, y, visited, path, numNodes)) {
                return true;
            }
        }
    }

    visited[x] = 0;
    path[0]--;
    return false;
}


void Path(int x, int y, int numNodes) {
    int visited[MAX_NODES] = {0};
    int path[MAX_NODES + 1] = {0};
    if (!DFS(x, y, visited, path, numNodes)) {
        printf("No path from %d to %d\n", x, y);
    }
}


int maxDegree(int numNodes) {
    int maxDegree = 0;
    for (int i = 0; i < numNodes; i++) {
        int degree = 0;
        for (int j = 0; j < numNodes; j++) {
            if (isNeighbor(i, j)) {
                degree++;
            }
        }
        if (degree > maxDegree) {
            maxDegree = degree;
        }
    }
    return maxDegree;
}


int minDegree(int numNodes) {
    int minDegree = numNodes;
    for (int i = 0; i < numNodes; i++) {
        int degree = 0;
        for (int j = 0; j < numNodes; j++) {
            if (isNeighbor(i, j)) {
                degree++;
            }
        }
        if (degree < minDegree) {
            minDegree = degree;
        }
    }
    return minDegree;
}


float avgDegree(int numNodes) {
    int totalDegree = 0;
    for (int i = 0; i < numNodes; i++) {
        int degree = 0;
        for (int j = 0; j < numNodes; j++) {
            if (isNeighbor(i, j)) {
                degree++;
            }
        }
        totalDegree += degree;
    }
    return (float)totalDegree / numNodes;
}

int main() {
    int numNodes = 5;

    insertEdge(1, 3);
    insertEdge(1, 4);
    insertEdge(2, 3);
    insertEdge(2, 4);
    insertEdge(4, 0);
    insertEdge(4, 2);
    
    getNeighbors(3, numNodes);
    Path(1, 4, numNodes);
    
    printf("Max Degree: %d\n", maxDegree(numNodes));
    printf("Min Degree: %d\n", minDegree(numNodes));
    printf("Avg Degree: %.2f\n", avgDegree(numNodes));

    return 0;
}
