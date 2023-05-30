# CSCI-335_Project5
Graph Algorithms
# Assignment-5-Code

ReadMe Assignment Reflection:

For this project we had to represent a graph using an adjacency list.
I created a Vertex class and a Graph class. Vertex objects have an element, and 
a vector of pairs<int, double>. The vector of paris is the Vertex's adjacency's list, where
the int represents other Vertices the Vertex is connected to and the double represents the 
weight of the edge connecting the two vertices. Graph objects have a vector of Vertex objects. 

To create a graph given an input file, I made a Helper function that took lines from the input file, and converted 
them into Vertex objects, with elements (the first int in the line) and the vector of pairs (the next two numbers in the line).
Once the vertex objects were created I added them to a Graph object with an addVertex() helper function. Part one was fun and 
straightforward, since we had the freedom to implement however we wanted. 

For Part two, we had implement the Dijkstra algorithm using a binary heap. 
Given a graph and a starting Vertex, the function returns the shortest path 
found using the algorithm including the cost of the path.

For part two, I had to add some data members to Vertex objects. I added a distance variable to keep track of the shortest distance. 
A visited boolean to keep track if Vertex was visited and a vector of integers to keep the path stored. In order to keep track of the path
I also added a previous_vertex member to keep track of the individual vertices along the shortest path. 

One of the bugs I encountered was an infinite loop in the Dijkstra function. The while(!heap is empty ) loop went on forever. 
It was because, I was using intergers to represent the Vertices across files and functions. Then I would use a helper fucntion, getVertex(num)
to get the actual Vertex Object in the Graph associated with that number. However, I wasn't using the actual vertex in the graph I was created a 
new one and setting equal to the vertex in the graph. So this led to errors. I changed the function so it returns, a l-value reference:
Vertex & getVertex(num). This way when it returns the Vertices in the graph it returns the Vertex itself. 

I am working on the edge cases and hidden tests. I checked to make sure the graph doesn't accept negative edges because then the Dijkstra algorithm wouldn't work.
Further, I added tests to check if the starting vertex provided for the Dijkstra function is invalid (it doesn't exist in the graph). If the file is empty or the graph 
is empty, I also think my program will catch that. I need to add more edge cases, including chekcing if any Verterices loop back to their selves. This would also 
effect the validity of the algorithm. 


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

