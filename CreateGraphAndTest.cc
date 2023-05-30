/*
Massiel Sanchez 
CSCI 335 HW 5
Professor Stamos
Due: April 15 2023

This file reads in an input text file (a Graph File), and creates a Graph Objecet. 

It parses the text file, by sending each line to the Helper function create_Vertex(). 
create_Vertex() reads a line of the text file and creates a Vertex object, with an element and vector of pairs of <int, double>. 
These Vertices are added to the Graph.

After the graph is created, it tests it by reading another text file with pairs of Vertices, and confirms if 
the vertices are connected or not. 


*/


#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>

#include "graph.h"

using namespace std;

//Helper function: creates Vertex Objects from input line
Vertex create_Vertex(const string & input_line)
{
  stringstream stream(input_line);

  int element;
  vector<pair<int, double>> list;

  stream >> element;
  stream >> ws;

// If line only has an element, return Vertex with empty list
  if(stream.eof())
  {
    return Vertex(element, list);
  }

  while(stream.good())
  {
    int connected_vertex;
    double weight;
    stream >> connected_vertex >> weight;
    list.emplace_back(connected_vertex, weight);

    // pair<int, double> a_pair = make_pair(connected_vertex, weight);
    // list.push_back(a_pair);
  }

    // Create Vertex object using contructor, and return it
    return Vertex(element, list);
}


/*
Create and Test Graph
*/
int graphTestDriver(int argc, char **argv) 
{

  /*
  Create Graph:
  Reading from Graph1.txt (argv[1])
  for every input line except first : 
  parse line, create Vertex Objects get the element and the pairs, 
  then push_back obects to Graph's vector
  */
 Graph a_graph;
 ifstream file(argv[1]);
  if(!file.is_open())
 {
  cerr << "ERROR, file did not open \n";
  exit(EXIT_FAILURE);

 }


 string line;

 //skip the first line
 getline(file, line);

 
 while(getline(file, line))
 {
  Vertex a_vertex = create_Vertex(line);
  a_graph.add_Vertex(a_vertex);
 }

// test creation of tree with this line: a_graph.printGraph();


 /*
 Testing:
 reading from AdjacencyQueries1.txt (argv[2])
 print whether the vertices are adjacent or not 
iterate through graph vector of vertices, access vertex of first number
 iterate through vector of the vertex, does 2nd number match any 
 list[some_index].first in the list? if yes they are ajacent if no they arent

//read from file and get main Vertx obj and other Vertex obj

 */

  ifstream input_file(argv[2]);
  int main, other;

  while(input_file >> main >> other)
  {
    cout << main << " " << other << ": ";

   
   //find Vertex obejct associated with int main in a_graph
   Vertex main_Vertex = a_graph.get_Vertex(main);
   if( main_Vertex.check_Adjacent( other) == true)
    {
      cout << "connected " << main_Vertex.get_Weight(other) << endl;
    }
    else
    {
      cout << "not_connected " << endl;
    }
  }

    return 0;
}

int main(int argc, char **argv) 
{
    if (argc != 3) 
    {
		  cout << "Usage: " << argv[0] << " <GRAPH_File>" << "<ADJACENCY_QUERYFILE>" << endl;
		  return 0;
    }

    graphTestDriver(argc, argv);

    return 0;
}
