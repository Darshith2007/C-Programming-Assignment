# Comparison Table

| Criterion | Adjacency Matrix | Adjacency List |
|---|---|---|
| Storage | V × V array | Vertex neighbour lists |
| Space | O(V²) | O(V+E) |
| BFS | O(V²) | O(V+E) |
| DFS | O(V²) | O(V+E) |
| Edge check | O(1) | O(degree(u)) |
| Traversal | Scans all possible neighbours | Scans only existing neighbours |
| Sparse graph | Stores many 0s/unconnected pairs | Stores only actual edges |
| Dense graph | Convenient | Larger neighbour lists |

## Execution comparison for this graph

Here V = 6 and E = 6. The matrix BFS and DFS each performed 36 cell checks because every visited vertex scans all 6 possible neighbour positions. The list BFS and DFS each performed 12 neighbour checks, matching the total degree sum 2E = 12 for this undirected graph.

For the E-F edge check, the matrix used 1 direct cell check. The list examined 2 neighbours in E's adjacency list before finding F.
