//ID:207988213
//E-mail: haleviadiel@gmail.com

#include <iostream>
#include <vector>
#include "Graph.hpp"

 namespace ariel{

        
        // Default constructor
        Graph::Graph()
        { }

        bool Graph::get_isWeighted()const
        {
            return isWeighted;
        }

        
        bool Graph::get_graphDirected()const
        {
            return isDirected;
        }
        std::vector<std::vector<int>> Graph::get_matrix()const
        {
            return this->adj_Mat;
        }

        
        int Graph::get_countVertices()
        {
            return countVertices;
        }

        

        

        
        void Graph::printGraph()
        {

            std:: cout << "Graph with " << countVertices  << " vertices and " <<  countEdges  << " edges \n"; 
        }

        void Graph::loadGraph(const std::vector<std::vector<int>>& adj_Mat)
        {

            countVertices = adj_Mat.size();
            countEdges = 0;
            isDirected=true;
            this->adj_Mat=adj_Mat;

            if(adj_Mat.size() != adj_Mat[0].size())
            {
                throw std::invalid_argument("Invalid graph: The graph is not a square matrix.\n");
            }

            //check if directed
            for(int i=0;i<adj_Mat.size();i++)
            {
                for(int j=0;j<adj_Mat.size();j++)
                        {
                             if(adj_Mat[i][j]!=adj_Mat[j][i])   
                             {
                                isDirected=false;
                             }
                             if(adj_Mat[i][j]!=0)
                             {
                                countEdges++;
                             }
                        }
                
            }
            if(!isDirected)
            {
                countEdges=countEdges/2;
            }
            
        }
        


 }







