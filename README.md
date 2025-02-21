# Graph Algorithms Project 5 Code

This project was part of the *Software Analysis and Design III* (CSCI 335) course at Hunter College. <br>


____________________________________________________________________________________________________________________________________________________________________________________________________________________

### Summary:
class project...

Summary:
CreateGraphAndTest.cc: creates graph and tests graph built. 
graph.h: Graph class. Dijkstra implementation here. 
FindPaths.cc : using Dijkstra retruns shortest path.

Testing Files: 
Graph1.txt and Graph2.txt to create graph. 
AdjacencyQueries1.txt and AdjacencyQueries2.txt to test adjacent nodes.


To compile type:

 `make all`

To clean object files and executables type:

 `make clean`
 
To run the create and test graph routine, type:
`./CreateGraphAndTest <GRAPH_FILE> <ADJECENCY_QUERYFILE>`

where `<GRAPH_FILE>` is the file used to create the graph and
`<ADJECENCY_QUERYFILE>` is the file used to check if vertices
are adjacent

Example:
`./CreateGraphAndTest Graph1.txt AdjacencyQueries1.txt`

To run the find paths in graph routine, type:
`./FindPaths <GRAPH_FILE> <STARTING_VERTEX>`

where `<GRAPH_FILE>` is the file used to create the graph and 
`<STARTING_VERTEX>` is the vertex in the graph as the starting
point for the paths

Example:
`./FindPaths Graph2.txt 1`

