/*
Massiel Sanchez
CSCI 335 HW 5
Professor Stamos
Due: April 15 2023

FindPaths.cc, this file calls the Dijkstra function in the Graph class 
in order to print the list of elements in the graph and their shortest 
path and cost. 

*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

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

    //no negative Weights
    if(weight < 0.0)
    {
      throw invalid_argument("Negative Weight not allowed");
    }
    list.emplace_back(connected_vertex, weight);

    // pair<int, double> a_pair = make_pair(connected_vertex, weight);
    // list.push_back(a_pair);
  }

    // Create Vertex object using contructor, and return it
    return Vertex(element, list);
}


int pathfindDriver(int argc, char **argv) 
{
 Graph a_graph_;
 ifstream file(argv[1]);

 if(!file.is_open())
 {
  cerr << "ERROR, file did not open \n";
  exit(EXIT_FAILURE);

 }

 string first_line;
 string line;


 //skip the first line
 getline(file, first_line);
//  int total_vertices = stoi(first_line);
//  a_graph_.setSize(total_vertices);


 while(getline(file, line))
 {
  Vertex a_vertex = create_Vertex(line);
  a_graph_.add_Vertex(a_vertex);
 }

 int starting_vertex = atoi(argv[2]);

a_graph_.Dijkstra(starting_vertex);





    return 0;
}

int main(int argc, char **argv) {
    if (argc != 3) {
		cout << "Usage: " << argv[0] << " <GRAPH_FILE>" << "<STARTING_VERTEX>" << endl;
		return 0;
    }

    pathfindDriver(argc, argv);

    return 0;
}
