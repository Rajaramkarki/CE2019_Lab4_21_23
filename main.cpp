#include<iostream>
#include "graph.h"
using namespace std;

// void createRandomGraph();

int main()
{
    Graph g;
    g.checkEmpty();

    g.addVertex(1);
    g.addVertex(2);
    g.addVertex(3);
    g.addVertex(4);
    g.addVertex(5);
    g.addVertex(6);

    g.addEdge(1, 2);
    g.addEdge(2, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    g.addEdge(4, 1);
    g.addEdge(5, 2);

    g.checkEmpty();
    
    if(g.isDirected())
    {
        cout<<"The graph is directed graph."<<endl;
    }
    else
    {
        cout<<"The graph is undirected graph."<<endl; 
    }

    g.displayMatrix();
    cout<<"\n"<<endl;

    g.degree(2);
    if(g.directed == 1)
    {
        cout<<"The indegree is "<<g.indegree(2)<<endl;
        cout<<"The outdegree is "<<g.outdegree(2)<<endl;;
    }
    cout<<"\n"<<endl;
    g.neighbour(5, 3);

    g.neighbour(4, 1);
    
    cout<<"\n"<<endl;
    g.neighbours(4);
    cout<<"The number of edges are:"<<g.numEdges()<<endl;
    g.removeEdge(1,2);
    cout<<"\n"<<endl;
    cout<<"The number of edges are:"<<g.numEdges()<<endl;
    cout<<"The number of vertices are:"<<g.numVertices()<<endl;
    g.removeVertex(3);
    cout<<"\n"<<endl;
    cout<<"The number of edges are:"<<g.numEdges()<<endl;
    cout<<"The number of vertices are:"<<g.numVertices()<<endl;
    g.displayMatrix();

    cout<<"\n"<<endl;
    cout<<"The vertices are:"<<endl;
    g.displayVertices();

    cout<<"\n"<<endl;
    cout<<"\nGenerating a random graph"<<endl;
    Graph h;
    int n;
    cout<<"Enter the number of vertices in the graph"<<endl;
    cin>>n;
    h.createRandomGraph(n);
    h.displayMatrix();
    cout<<"\n"<<endl;
    h.displayVertices();
}