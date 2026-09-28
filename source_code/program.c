#include <stdio.h>
#include <string.h>

#define V 6
#define MAX_DEGREE 5

char vertices[V] = {'A', 'B', 'C', 'D', 'E', 'F'};
int matrix[V][V];
int adjList[V][MAX_DEGREE];
int degree[V];

int indexOf(char x) {
    for (int i = 0; i < V; i++) {
        if (vertices[i] == x) return i;
    }
    return -1;
}

void addEdge(int u, int v) {
    matrix[u][v] = matrix[v][u] = 1;

    adjList[u][degree[u]++] = v;
    adjList[v][degree[v]++] = u;
}

void buildGraph(void) {
    memset(matrix, 0, sizeof(matrix));
    memset(adjList, 0, sizeof(adjList));
    memset(degree, 0, sizeof(degree));

    addEdge(0, 1); // A-B
    addEdge(0, 2); // A-C
    addEdge(1, 3); // B-D
    addEdge(1, 4); // B-E
    addEdge(2, 5); // C-F
    addEdge(4, 5); // E-F
}

void printMatrix(void) {
    printf("\nADJACENCY MATRIX\n");
    printf("    A B C D E F\n");
    for (int i = 0; i < V; i++) {
        printf("%c   ", vertices[i]);
        for (int j = 0; j < V; j++) printf("%d ", matrix[i][j]);
        printf("\n");
    }
}

void printList(void) {
    printf("\nADJACENCY LIST\n");
    for (int i = 0; i < V; i++) {
        printf("%c -> ", vertices[i]);
        for (int j = 0; j < degree[i]; j++)
            printf("%c ", vertices[adjList[i][j]]);
        printf("\n");
    }
}

void bfsMatrix(int start) {
    int visited[V] = {0};
    int queue[V], front = 0, rear = 0;
    int checks = 0;

    visited[start] = 1;
    queue[rear++] = start;
    printf("\nBFS using adjacency matrix from A: ");

    while (front < rear) {
        int u = queue[front++];
        printf("%c ", vertices[u]);
        for (int v = 0; v < V; v++) {
            checks++;
            if (matrix[u][v] && !visited[v]) {
                visited[v] = 1;
                queue[rear++] = v;
            }
        }
    }
    printf("\nMatrix BFS cell checks: %d\n", checks);
}

void bfsList(int start) {
    int visited[V] = {0};
    int queue[V], front = 0, rear = 0;
    int checks = 0;

    visited[start] = 1;
    queue[rear++] = start;
    printf("\nBFS using adjacency list from A: ");

    while (front < rear) {
        int u = queue[front++];
        printf("%c ", vertices[u]);
        for (int i = 0; i < degree[u]; i++) {
            int v = adjList[u][i];
            checks++;
            if (!visited[v]) {
                visited[v] = 1;
                queue[rear++] = v;
            }
        }
    }
    printf("\nList BFS neighbour checks: %d\n", checks);
}

void dfsMatrixUtil(int u, int visited[], int *checks) {
    visited[u] = 1;
    printf("%c ", vertices[u]);
    for (int v = 0; v < V; v++) {
        (*checks)++;
        if (matrix[u][v] && !visited[v])
            dfsMatrixUtil(v, visited, checks);
    }
}

void dfsMatrix(int start) {
    int visited[V] = {0};
    int checks = 0;
    printf("\nDFS using adjacency matrix from A: ");
    dfsMatrixUtil(start, visited, &checks);
    printf("\nMatrix DFS cell checks: %d\n", checks);
}

void dfsListUtil(int u, int visited[], int *checks) {
    visited[u] = 1;
    printf("%c ", vertices[u]);
    for (int i = 0; i < degree[u]; i++) {
        int v = adjList[u][i];
        (*checks)++;
        if (!visited[v])
            dfsListUtil(v, visited, checks);
    }
}

void dfsList(int start) {
    int visited[V] = {0};
    int checks = 0;
    printf("\nDFS using adjacency list from A: ");
    dfsListUtil(start, visited, &checks);
    printf("\nList DFS neighbour checks: %d\n", checks);
}

void searchMatrix(char target) {
    int checks = 0;
    printf("\nMATRIX VERTEX SEARCH for %c\n", target);
    for (int i = 0; i < V; i++) {
        checks++;
        if (vertices[i] == target) {
            printf("Found %c after %d vertex-label checks.\n", target, checks);
            return;
        }
    }
    printf("Vertex not found after %d checks.\n", checks);
}

void searchList(char target) {
    int checks = 0;
    printf("\nLIST VERTEX SEARCH for %c\n", target);
    for (int i = 0; i < V; i++) {
        checks++;
        if (vertices[i] == target) {
            printf("Found %c after %d vertex-label checks.\n", target, checks);
            return;
        }
    }
    printf("Vertex not found after %d checks.\n", checks);
}

void edgeCheckComparison(void) {
    int u = indexOf('E');
    int v = indexOf('F');
    int matrixChecks = 1;
    int listChecks = 0;
    int found = 0;

    for (int i = 0; i < degree[u]; i++) {
        listChecks++;
        if (adjList[u][i] == v) {
            found = 1;
            break;
        }
    }

    printf("\nEDGE CHECK: E-F\n");
    printf("Adjacency Matrix: %d direct cell check -> %s\n", matrixChecks,
           matrix[u][v] ? "edge exists" : "no edge");
    printf("Adjacency List: %d neighbour checks -> %s\n", listChecks,
           found ? "edge exists" : "no edge");
}

int main(void) {
    char target;

    buildGraph();

    printf("SOCIAL NETWORK GRAPH\n");
    printf("Connections: A-B, A-C, B-D, B-E, C-F, E-F\n");

    printMatrix();
    printList();

    bfsMatrix(0);
    bfsList(0);
    dfsMatrix(0);
    dfsList(0);

    printf("\nEnter vertex to search (A-F): ");
    if (scanf(" %c", &target) != 1) return 1;

    searchMatrix(target);
    searchList(target);
    edgeCheckComparison();

    printf("\nCOMPLEXITY\n");
    printf("Adjacency Matrix space: O(V^2)\n");
    printf("Adjacency List space: O(V+E)\n");
    printf("BFS/DFS with matrix: O(V^2)\n");
    printf("BFS/DFS with list: O(V+E)\n");
    printf("Matrix edge check: O(1)\n");
    printf("List edge check: O(degree(u)), worst-case O(V)\n");

    return 0;
}
