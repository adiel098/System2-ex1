# **Advanced Systems Programming - C++ Graph Project**

This repository hosts the project assignment for the **Advanced Systems Programming** course at Ariel University. The focus of the project is on implementing graph-related classes and algorithms in C++.

## **Overview**

In this project, we develop a `Graph` class to represent graphs using an adjacency matrix. The class supports both directed and undirected graphs, as well as weighted and unweighted graphs. Additionally, we implement various algorithms to perform graph operations such as checking connectivity, finding shortest paths, detecting cycles, and verifying bipartiteness.

### **Contents**

- **Graph.hpp**: Header file declaring the `Graph` class and associated classes (`Vertex` and `Edge`).
- **Graph.cpp**: Implementation of the `Graph` class.
- **Algorithms.hpp**: Header file declaring the `Algorithms` namespace, which includes various graph algorithms.
- **Algorithms.cpp**: Implementation of the algorithms in the `Algorithms` namespace.
- **Demo.cpp**: Example demonstrations showing how to use the `Graph` class and algorithms.

## **Classes and Algorithms**

### **Graph Class**

- **Vertex**: Represents a node within the graph.
- **Edge**: Represents a connection between two nodes.
- **Graph**: Manages a graph using an adjacency matrix. Includes methods to add vertices and edges, load graphs from adjacency matrices, print graphs, and access graph properties.

### **Algorithms**

- **isConnected**: Checks if the graph is connected.
- **shortestPath**: Computes the shortest path between two nodes.
- **isContainsCycle**: Detects if there are any cycles in the graph.
- **isBipartite**: Verifies if the graph is bipartite.
- **negativeCycle**: Identifies a negative cycle in the graph, if any.
- **DFS**: Depth-first search implementation.
- **BFS**: Breadth-first search implementation.
- **dijkstra**: Dijkstra's algorithm for finding shortest paths.



