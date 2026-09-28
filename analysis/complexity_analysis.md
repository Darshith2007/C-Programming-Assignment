# Complexity Analysis

Let **V** be the number of vertices and **E** be the number of edges. For this graph, V = 6 and E = 6.

| Operation | Adjacency Matrix | Adjacency List |
|---|---|---|
| Space | O(V²) | O(V+E) |
| BFS | O(V²) | O(V+E) |
| DFS | O(V²) | O(V+E) |
| Edge check (u,v) | O(1) | O(degree(u)), worst O(V) |
| Vertex-label search | O(V) | O(V) |

### Why
- **Matrix:** one cell is stored for every possible pair of vertices, so space is O(V²). During BFS/DFS, each visited vertex scans all V columns, giving O(V²).
- **List:** only existing edges are stored, so space is O(V+E). BFS/DFS inspect each vertex and edge a constant number of times, giving O(V+E).
- **Edge check:** the matrix can directly access matrix[u][v] in O(1). A list may scan the neighbours of u, taking O(degree(u)).
- **Vertex-label search:** if labels are stored in an unsorted array, both representations may require O(V) label checks.

### Space for this example
The matrix reserves 6 × 6 = **36 cells** for adjacency information. The undirected list stores 12 neighbour entries because each of the 6 edges occurs in both endpoint lists, plus the vertex/list structure.
