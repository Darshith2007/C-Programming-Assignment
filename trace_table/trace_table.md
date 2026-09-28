# Trace Tables

The graph is treated as **undirected** and neighbours are processed in the order in which the connections are inserted (alphabetical for each vertex here).

## BFS from A

| Step | Queue before | Removed | Newly visited / enqueued | Queue after | Output |
|---:|---|---|---|---|---|
| 1 | A | A | B, C | B, C | A |
| 2 | B, C | B | D, E | C, D, E | A B |
| 3 | C, D, E | C | F | D, E, F | A B C |
| 4 | D, E, F | D | — | E, F | A B C D |
| 5 | E, F | E | — (F already visited) | F | A B C D E |
| 6 | F | F | — | empty | A B C D E F |

**BFS result:** A → B → C → D → E → F

## DFS from A

| Step | Current | Action | Next |
|---:|---|---|---|
| 1 | A | Visit A; B is unvisited | B |
| 2 | B | Visit B; A visited, D unvisited | D |
| 3 | D | Visit D; B visited | Back to B |
| 4 | B | Continue; E unvisited | E |
| 5 | E | Visit E; B visited, F unvisited | F |
| 6 | F | Visit F; C unvisited | C |
| 7 | C | Visit C; A and F visited | Backtrack |

**DFS result:** A → B → D → E → F → C

## Vertex search for target F

| Representation | Label checks | Result |
|---|---:|---|
| Adjacency Matrix | 6 | F found |
| Adjacency List | 6 | F found |

## Edge check for E-F

| Representation | Operation | Checks | Result |
|---|---|---:|---|
| Matrix | Inspect matrix[E][F] directly | 1 | Edge exists |
| List | Scan E's neighbours | 2 | Edge exists |

## Traversal operation counts from execution

| Traversal | Matrix | List |
|---|---:|---:|
| BFS from A | 36 cell checks | 12 neighbour checks |
| DFS from A | 36 cell checks | 12 neighbour checks |
