//ID:207988213
//E-mail: haleviadiel@gmail.com

#include <iostream>
#include <vector>
#include "Graph.hpp"

 namespace ariel{

        // Default constructor
        Vertex::Vertex() 
        {}


        Vertex::Vertex(int data)
        {this->data =data;}


     int Vertex::get_data() const
    {
        return data;
    }


        std::vector<Edge>& Vertex::get_Neighbours()
        {
            return this->neighbours;
        }

        // Default constructor
        Edge::Edge()
        {}
        
        Edge::Edge(Vertex& dest,int weight)
        {
            this->dest = &dest;
            this-> weight = weight;
        }


        int Edge::get_weight()
        {
            return weight;
        }
         Vertex& Edge::get_dest()
        {
            return *dest;
        }   
        // Default constructor
        Graph::Graph()
        { }

        bool Graph::get_isWeighted()
        {
            return isWeighted;
        }

        Vertex& Graph::get_vertex(int data)
        {
            if (data >= 0 && data < vertices.size()) 
            {
                return vertices[data];
            } 
            else 
            {  
                throw std::out_of_range("Index out of range");
                // or return nullptr;
            }
        }
        std::vector<Vertex>Graph::get_graphVertices()
        {
            return vertices;
        }
        bool Graph::get_graphDirected()
        {
            return isDirected;
        }

        void Graph::set_graphDirected(bool flag)
        {
            this->isDirected = flag;
        }
        int Graph::get_countVertices()
        {
            return countVertices;
        }

        void Graph::set_isWeighted(bool flag)
        {
            this->isWeighted = flag;
        }

        void Graph::add_Neighbour(Vertex& source,Vertex& destination,int weight)
        {
            if(source.get_data() < vertices.size())
            {
                Edge* e =  new Edge(destination,weight);
                vertices[source.get_data()].get_Neighbours().push_back(*e);
                countEdges++;

            }
            else
            {
                throw std::out_of_range("Source index out of range");
            }
            
        }

        void Graph::add_Vertex(Vertex v)
        {
            vertices.push_back(v);
            countVertices++;

        }
        void Graph::printGraph()
        {

            std:: cout << "Graph with " << countVertices  << " vertices and " <<  countEdges  << " edges \n"; 
        }

        void Graph::loadGraph(const std::vector<std::vector<int>>& adj_Mat)
        {
            countVertices = 0;
            countEdges = 0;
            isWeighted = false;
            vertices.clear(); 
            if(adj_Mat.size() != adj_Mat[0].size())
            {
                throw std::invalid_argument("Invalid graph: The graph is not a square matrix.\n");
            }

            // Use 'this' pointer to access the current object
            for (size_t i = 0; i < adj_Mat.size(); i++)
            {
                Vertex* v = new Vertex(i);
                this->add_Vertex(*v);
            }

            for (size_t j = 0; j < adj_Mat.size(); j++)
            {
                Vertex& source = this->get_vertex(j);
                for (size_t k = 0; k < adj_Mat.size(); k++)
                {
                    if (adj_Mat[j][k] > 1)
                    {
                        this->set_isWeighted(true);
                    }

                    if(adj_Mat[j][k] !=adj_Mat[k][j])
                    {
                        set_graphDirected(true);
                    } 
                    if(adj_Mat[j][k] >= 1)
                    {
                         Vertex& dest = this->get_vertex(k);
                         this->add_Neighbour(source, dest, adj_Mat[j][k]);
                    }
                   
                }
            }
        }
        


 }







