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
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    cout<<g.isEmpty()<<endl;
    cout<<"The number of edges are:"<<g.numEdges()<<endl;
    g.removeEdge(1,2);
    cout<<"The number of edges are:"<<g.numEdges()<<endl;
    cout<<"The number of vertices are:"<<g.numVertices()<<endl;
    g.removeVertex(3);
    cout<<"The number of edges are:"<<g.numEdges()<<endl;
    cout<<"The number of vertices are:"<<g.numVertices()<<endl;
    g.displayMatrix();
}