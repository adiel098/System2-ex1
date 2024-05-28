//ID:207988213
//E-mail: haleviadiel@gmail.com

#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
namespace ariel
{

    class Edge;
    class Vertex;
    class Graph;


class Vertex {
    
    private:
        std::vector<Edge> neighbours;   
        int data;

    public:
        Vertex();
        Vertex(int data);
        int get_data() const;
        std::vector<Edge>& get_Neighbours();
      

};

class Edge{

    private:
        Vertex* dest;
        int weight;

    public:
        Edge();
        Edge(Vertex& dest,int weight);
        Vertex& get_dest();
        int get_weight();

};

class Graph {
    // Class members and methods
    private:
        bool isDirected=false;
        bool isWeighted=false;  

        int countVertices =0;
        int countEdges =0;
        std::vector<Vertex> vertices;

    public:
        Graph();
        std::vector<Vertex>  get_graphVertices();
        Vertex& get_vertex(int data);

        int get_countVertices();
        bool get_graphDirected();
        void set_graphDirected(bool flag);

        void set_isWeighted(bool flag);
        bool get_isWeighted();
        void add_Vertex(Vertex v);
        void add_Neighbour(Vertex& source,Vertex& dest,int weight);
        void loadGraph(const std::vector<std::vector<int>>& adj_Mat);
        void printGraph();

};

}

#endif
