#include<iostream>
#include "graph.h"
using namespace std;

int main()
{
    Graph g;
    if(g.isEmpty())
    {
        cout<<"The graph is empty."<<endl;
    }
    else
    {
        cout<<"The graph is not empty."<<endl;
    }
    g.addVertex(1);
    g.addVertex(2);
    g.addVertex(3);
    g.addVertex(4);
    g.addVertex(5);
    g.addVertex(6);

    g.addEdge(1, 2);
    g.addEdge(2, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 2);
    g.addEdge(3, 1);
    g.addEdge(4, 1);
    g.addEdge(4, 3);
    g.addEdge(4, 4);
    g.addEdge(5, 2);

    if(g.isEmpty())
    {
        cout<<"The graph is empty."<<endl;
    }
    else
    {
        cout<<"The graph is not empty."<<endl;
    }
    
    if(g.isDirected())
    {
        cout<<"The graph is directed graph."<<endl;
    }
    else
    {
       cout<<"The graph is undirected graph."<<endl; 
    }
    g.displayMatrix();
    cout<<"The degree of the entered vertex is: "<<g.degree(4)<<endl;
    cout<<"The in-degree of the entered vertex is: "<<g.indegree(4)<<endl;
    cout<<"The out-degree of the entered vertex is: "<<g.outdegree(4)<<endl;
    if(g.neighbour(5, 3))
    {
        if(g.directed==1)
        {
            cout<<"The second vertex is the neighbour of first vertex."<<endl;
        }
        else
        {
            cout<<"The entered vertices are neighbours."<<endl;
        }   
    }
    else{
        cout<<"The entered vertices are not neighbours."<<endl;
    }
    if(g.neighbour(1, 4))
    {
        if(g.directed==1)
        {
            cout<<"The second vertex is the neighbour of first vertex."<<endl;
        }
        else
        {
            cout<<"The entered vertices are neighbours."<<endl;
        } 
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