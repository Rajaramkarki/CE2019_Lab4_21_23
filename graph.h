#include<iostream>

using namespace std;



class Graph{
    public:
        Graph();
         int directed;

        bool ifVertexExists(int &index, int target_vertex);
        bool isEmpty();
        bool checkEmpty();
        bool isDirected();
        void addVertex(int newVertex);
        void addEdge(int vertex1, int vertex2);
        void removeEdge(int vertex1, int vertex2);
        void removeVertex(int vertex);
        int numVertices();
        int numEdges();
        int indegree(int vertex);
        int outdegree(int vertex);
        int degree(int vertex);
        void neighbours(int vertex);
        bool neighbour(int vertex1, int vertex2);
        void displayMatrix();
        void displayVertices();
        void createRandomGraph();

        void createRandomGraph(int n);

    private:
       
        int size = 16;
        int vertices[16];
        int last_vertex_index = 0;
        int adjMatrix[16][16];
        
};