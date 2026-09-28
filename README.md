# C Programming Assignment – Graph Representations

## Question 6
Consider a small social network with the following connections:

**A-B, A-C, B-D, B-E, C-F, E-F**

### Requirements
1. Implement the network using an adjacency matrix and adjacency list.
2. Perform BFS and DFS starting from vertex A.
3. Implement a search operation for a specified vertex using both representations and record the operations required.
4. Compare space requirements, traversal behaviour, search/edge-checking operations, and time complexity.
5. Determine the more suitable representation for a sparse social network and justify the conclusion using execution results.

## Project Contents
- `source_code/program.c` – C implementation.
- `input/input.txt` – input used for the execution (`F`).
- `output/output.txt` – recorded execution output.
- `trace_table/trace_table.md` – BFS/DFS and search trace tables.
- `analysis/complexity_analysis.md` – complexity analysis.
- `analysis/comparison_table.md` – comparison of adjacency matrix and list.
- `conclusion/final_conclusion.md` – final conclusion based on the graph and execution.

## Graph
The graph is treated as **undirected**, so every connection is stored in both directions.

## Expected traversal
With vertices and neighbours processed in alphabetical order:
- BFS from A: **A B C D E F**
- DFS from A: **A B D E F C**

## How to compile and run
```bash
gcc source_code/program.c -o program
./program < input/input.txt
```

On Windows with MinGW GCC:
```text
gcc source_code/program.c -o program.exe
program.exe < input/input.txt
```

## Conclusion
For this sparse graph, the adjacency list uses **O(V+E)** space compared with **O(V²)** for an adjacency matrix. Traversal using the list is **O(V+E)**, while matrix traversal is **O(V²)**. The adjacency matrix provides O(1) edge checking, whereas a list may inspect neighbours. For this sparse social-network example, the adjacency list is therefore the representation selected based on space and traversal efficiency.
