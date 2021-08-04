#include<iostream>
#include "graph.h"
using namespace std;

int main()
{
    Graph g;
    cout <<g.isEmpty() << endl;
    g.addVertex(1);
    g.addVertex(2);
    g.addVertex(3);
    g.addVertex(4);
    g.addVertex(5);
    g.addVertex(6);
    g.addVertex(7);
    g.addVertex(8);

    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 2);
    g.addEdge(3, 1);
    g.addEdge(4, 5);
    g.addEdge(7, 8);

    g.displayMatrix();

    cout<<"\nThe number of edges are:"<<g.numEdges()<<endl;
    cout<<"\nThe number of vertices are:"<<g.numVertices()<<endl;

    g.neighbours(7);
    g.removeVertex(7);
    g.removeVertex(5);
   
    cout<<"\nThe number of edges are:"<<g.numEdges()<<endl;
    cout<<"\nThe number of vertices are:"<<g.numVertices()<<endl;
    g.displayMatrix();
}