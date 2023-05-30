/*
Massiel Sanchez 
CSCI 335 HW 5
Professor Stamos
Due: April 15 2023

This file contains two class, a Vertex class and a Graph class. A Graph is a mainly a vector of Vertex objects. 

*/


#ifndef STUDENT_GRAPH
#define STUDENT_GRAPH

#include <float.h>
#include <math.h>
#include <stdio.h>
#include <cfloat>
#include <climits>

#include "binary_heap.h"


/*
 Vertex class: 
 Every Vertex has an element and an adjacency list implemented with an vector of pairs <int, double>.
*/
class Vertex
    {
        public:
        /*
        Vertex Constructors: default, copy constructor, move constructor and 
        constructor for Vertices with empty adjacency lists that only takes an element
        */
       
       Vertex()
       {
        visited_ = false;
        distance_ = DBL_MAX;   //let DBL_MAX represent infinty 
       }

        //create Vertex Objects by passing the element in Vertex and Adjacency list
        Vertex(const int &num, vector<pair<int, double>> &vec)
        {
            element= num; 
            list = vec;
            visited_ = false;
            distance_ = DBL_MAX;
        }
            
        
        Vertex(const int &&num, vector<pair<int, double>> &&vec)
        {
            element= std::move(num); 
            list = std::move(vec);
            visited_ = false;
            distance_ = DBL_MAX;
        }

        //if List is empty
        Vertex(const int &num)
         {
            element= num; 
            visited_ = false;
            distance_ = DBL_MAX;
        }

    
        /*
        @return: element of Vertex
        */
        int getElement() const 
        {
            return element;
        }

        /*
        @param: an int representing the element of a Vertex
        @return: true if main Vertex who calls thisfunction is connected to other Vertex passed through parameter
        return false otherwise
        */
       bool check_Adjacent(const int &other)
       {
        if(!list.empty())
        {
            //iterate through adj list of main vertex to find other vertex 
            for(size_t i = 0; i < list.size(); i++)
            {
                if(other == list[i].first)
                {
                    return true;
                }
            }

        }
            return false;
       }


       /*
       @param: an int representing the element of a Vertex
       @return: returns weight associated with two vertices
       */
      double get_Weight(const int &other)
      {
        for(size_t i = 0; i < list.size(); i++)
            {
                if(other  == list[i].first)
                {
                    return list[i].second;
                }
            }
        return 0;
      }

        /*
        Print the adjacency list of the Vertex
        */
        void printList()
        {
            for(size_t i =0; i < list.size(); i++)
            {
    
                cout << "(" << list[i].first << "," << list[i].second << ")" << " ";          
            }
            cout << endl;
        }

        /*
        Compares distance of Verticies 
        */
        bool operator<(const Vertex &other) const
        {
            return distance_ < other.distance_;
        }

        /*
        Helper Function
        Set Distance of some Vertex to num passed through parameter 
        */
        void setDistance(double & num)
        {
            distance_ = num; 
        }

        /*
        Helper Function
        Set Visited to value passed through parameter
        */
        void setVisited(bool bool_, int prev_vertex)
        {
            visited_ = bool_;
            previous_vertex = prev_vertex;
        }

        /*
        Helper Function
        Returns the size of the list
        */
        size_t getListSize()
        {
            return list.size();
        }


        /*
        Helper Function
        Prints the Path of Vertex
        */
        void printPath()
        {
            for(size_t i =0; i < path.size(); i++)
            {
                cout << path[i] << " "; 
            }
        }
        


        //Vertex name in proj 5 they are integers 1-N
        int element;

        //Adjacency List: every vertex has a vector of ordered pairs that describe other vertices it is connected to (vertex, weight)
        vector<pair<int, double>> list; 

        
        //PART 2:

        bool visited_;
        double distance_;
        int previous_vertex;
        vector<int> path;

    };
  
/*
 Graph class: 
 is a collection of Vertex objects
 private members include:
    a vector of vertex objects
    total number of vertices in graph 
*/

class Graph
{
    public:

    Graph()
    {
        currentSize_ = 0;
    }

    Graph(vector<Vertex> &some_vertices)
    {
        currentSize_ = some_vertices.size();
        vertices_ = some_vertices;
    }

    Graph(vector<Vertex> &&some_vertices)
    {
        currentSize_ = some_vertices.size();
        vertices_ = std::move(some_vertices);
    }

    //Helper Function: adds a Vertex to the Graph and increments size of Graph
    void add_Vertex(Vertex & vertex)
    {
        vertices_.push_back(vertex);
        currentSize_++ ;
    }

    /*
    Helper Function: 
    @param: an integer
    @post: sets the currentSize_ of the graph to int passed through param
    */
    void setSize(const int & num)
    {
        currentSize_ = num;
    }


    /*
    @return: returns size of graph
    */
    int getSize() const
    {
        return currentSize_;
    }

     /*
    Created For Testing
    @return: returns size of graph, should be the same as getSize()
    */
    int getVerticesSize()
    {
        return vertices_.size();
    }

    //For testing 
    void printGraph()
    {
        for(int i =0; i < currentSize_; i++)
        {
            cout << "element: " << vertices_[i].getElement() << " ";
            cout << "list: " ;
            vertices_[i].printList(); 
            cout << endl;

        }
    }

    /*
    Helper Function: given an integer, returns Vertex Object if found in graph
    if not found in Graph throws exception
    */
   Vertex & get_Vertex( const int & num)  
   {
    for(size_t i =0; i < vertices_.size(); i++)
    {
        if(num == vertices_[i].element)
        {
          return vertices_[i];
        }
    }
    throw std::runtime_error("Vertex not found. Vertex is not in Graph");
   }






    /*
    Implements Dijkstra algorithm using a binary Min-Heap.
    @param: an integer that represents the element of the starting Vertex
    @post: prints vertices in Graph, with shortest path from starting Vertex to element
    and the cost associated with the path. 
    example:
    1: 1 cost: 0
    element: <path> cost: <cost>

    */
   void Dijkstra( const int & starting_vertex)
   {


    Vertex &starting_Vertex = get_Vertex(starting_vertex);

    //For starting vertex set distance to 0 and set visited to true
    starting_Vertex.distance_ = 0.0 ;
    starting_Vertex.setVisited(true, starting_vertex); 
    starting_Vertex.path.push_back(starting_vertex);
    

    //create Heap and insert starting vertex
    BinaryHeap<Vertex> the_heap ;
    the_heap.insert(starting_Vertex);

    while(!the_heap.isEmpty())
    {
        int curr_element = the_heap.findMin().element;
        Vertex &u = get_Vertex(curr_element);
        the_heap.deleteMin();
        u.setVisited(true, u.previous_vertex);

        for(size_t i=0; i < u.list.size(); i++)
        {
            int other = u.list[i].first;
            Vertex &other_Vertex = get_Vertex(other);
            double weight = u.list[i].second;



            if(!other_Vertex.visited_)
            {
                if(u.distance_ + weight < other_Vertex.distance_)
                {
                    other_Vertex.distance_ = u.distance_ + weight;
                    other_Vertex.previous_vertex = u.element;
                    //update path
                    other_Vertex.path = u.path;
                    other_Vertex.path.push_back(other);
                }

                the_heap.insert(other_Vertex);
            }


        }

}

for(size_t i =0; i < vertices_.size(); i++)
     {
        if (vertices_[i].visited_) 
        {
        cout << vertices_[i].element << ": ";
        vertices_[i].printPath();
        cout << "cost: " << vertices_[i].distance_ << endl;
        }
        else
        {
            cout << vertices_[i].element << ": ";
            cout << "not_possible" << endl;

        }
     }


   }

    
    private:

    int currentSize_;
    vector<Vertex> vertices_; 
};

#endif
