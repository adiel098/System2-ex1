//ID:207988213
//E-mail: haleviadiel@gmail.com

#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
namespace ariel
{

    class Graph;

class Graph {
    // Class members and methods
    private:
        bool isDirected=false;
        bool isWeighted=false;  
        int countVertices =0;
        int countEdges =0;
        std::vector<std::vector<int>> adj_Mat;


    public:
        Graph();
        int get_countVertices();
        bool get_graphDirected()const;
        std::vector<std::vector<int>> get_matrix()const ;

        bool get_isWeighted()const;
        void loadGraph(const std::vector<std::vector<int>>& adj_Mat);
        void printGraph();

};

}

#endif
