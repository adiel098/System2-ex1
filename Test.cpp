//ID:207988213
//E-mail: haleviadiel@gmail.com

#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"
#include <vector>
#include <stdexcept>


using namespace std;
using namespace ariel;



TEST_CASE("Test isConnected")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == "1");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isConnected(g) == "0");
}

TEST_CASE("Test shortestPath")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "0->1->2");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "-1");
}

TEST_CASE("Test isContainsCycle")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "0");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "The cycle is: 0->1->2->0");
}

TEST_CASE("Test isBipartite")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2}, B={1}");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isBipartite(g) == "0");

    vector<vector<int>> graph3 = {
        {0, 1, 2, 0, 0},
        {1, 0, 3, 0, 0},
        {2, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isBipartite(g) == "0");
}
TEST_CASE("Test invalid graph")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 5}};
    CHECK_THROWS(g.loadGraph(graph));
}
TEST_CASE("Test isConnected with additional scenarios") {
    // Test a connected graph with more vertices
    ariel::Graph g;
    vector<vector<int>> connectedGraph = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g.loadGraph(connectedGraph);
    CHECK(ariel::Algorithms::isConnected(g) == "1");

    // Test an empty graph
    ariel::Graph emptyGraph;
    CHECK(ariel::Algorithms::isConnected(emptyGraph) == "1");

    
}

TEST_CASE("Test shortestPath with additional scenarios") {
    // Test a graph with multiple shortest paths between vertices
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 1, 0},
        {1, 0, 1, 1},
        {1, 1, 0, 1},
        {0, 1, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 3) == "0->1->3");

    // Test a graph with no path between vertices
    ariel::Graph noPathGraph;
    vector<vector<int>> noPathMatrix = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}};
    noPathGraph.loadGraph(noPathMatrix);
    CHECK(ariel::Algorithms::shortestPath(noPathGraph, 0, 2) == "-1");

    // Test a graph with negative weights
    ariel::Graph negativeWeightGraph;
    vector<vector<int>> negativeWeights = {
        {0, 1, -1},
        {1, 0, 2},
        {-1, 2, 0}};
    negativeWeightGraph.loadGraph(negativeWeights);
    CHECK(ariel::Algorithms::shortestPath(negativeWeightGraph, 0, 2) == "-1");
}

TEST_CASE("Test isContainsCycle with additional scenarios") {
    // Test a graph without a cycle
    ariel::Graph acyclicGraph;
    vector<vector<int>> acyclicMatrix = {
        {0, 1, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {0, 0, 1, 0}};
    acyclicGraph.loadGraph(acyclicMatrix);
    CHECK(ariel::Algorithms::isContainsCycle(acyclicGraph) == "0");

    // Test a cyclic graph with multiple cycles
    ariel::Graph cyclicGraph;
    vector<vector<int>> cyclicMatrix = {
        {0, 1, 1, 0},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {0, 0, 1, 0}};
    cyclicGraph.loadGraph(cyclicMatrix);
    CHECK(ariel::Algorithms::isContainsCycle(cyclicGraph) == "The cycle is: 0->1->2->0");

    // Test a graph with a self-loop
    ariel::Graph selfLoopGraph;
    vector<vector<int>> selfLoopMatrix = {
        {0, 1, 0, 0},
        {1, 0, 0, 0},
        {0, 0, 0, 1},
        {0, 0, 1, 0}};
    selfLoopGraph.loadGraph(selfLoopMatrix);
    CHECK(ariel::Algorithms::isContainsCycle(selfLoopGraph) == "0");
}


TEST_CASE("Test invalid graph with additional scenarios") {
    // Test a non-square graph
    ariel::Graph nonSquareGraph;
    vector<vector<int>> nonSquareMatrix = {
        {0, 1, 0},
        {1, 0, 1}};
    CHECK_THROWS(nonSquareGraph.loadGraph(nonSquareMatrix));

    
}
