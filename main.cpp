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
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 2);
    g.addEdge(3, 1);
    cout<<g.isEmpty()<<endl;
    g.displayMatrix();
    cout<<"The degree of the entered vertex is: "<<g.degree(2)<<endl;
    cout<<"The in-degree of the entered vertex is: "<<g.indegree(2)<<endl;
    cout<<"The out-degree of the entered vertex is: "<<g.outdegree(3)<<endl;
    if(g.neighbour(1, 4))
    {
        cout<<"The second vertex is the neighbour of first vertex."<<endl;
    }
    else{
        cout<<"The entered vertices are not neighbours."<<endl;
    }
    if(g.neighbour(2, 3))
    {
        cout<<"The second vertex is the neighbour of first vertex."<<endl;
    }
    else{
        cout<<"The entered vertices are not neighbours."<<endl;
    }
    g.neighbours(4);
    cout<<"The number of edges are:"<<g.numEdges()<<endl;
    g.removeEdge(1,2);
    cout<<"The number of edges are:"<<g.numEdges()<<endl;
    cout<<"The number of vertices are:"<<g.numVertices()<<endl;
    g.removeVertex(3);
    cout<<"The number of edges are:"<<g.numEdges()<<endl;
    cout<<"The number of vertices are:"<<g.numVertices()<<endl;
    g.displayMatrix();
}