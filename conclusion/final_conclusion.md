# Final Conclusion

The social network contains 6 vertices and 6 edges and is treated as an undirected sparse graph.

The adjacency matrix provides very fast direct edge checking, because an edge can be checked in O(1) time. However, it requires O(V²) space and matrix-based BFS/DFS scans all possible neighbour positions.

The adjacency list stores only the connections that actually exist, requiring O(V+E) space. Its BFS and DFS complexity is O(V+E), so it avoids scanning absent edges.

**Based on the space requirement, traversal complexity, and the sparse nature of the given social network, the adjacency list is selected as the suitable representation for this example.** The matrix remains useful when constant-time edge checking is a priority.
