#include<iostream>

using namespace std;

class Graph{
    public:
        Graph();
        ~Graph()
        {
            for (int i = 0; i < n; i++)
            {   delete[] adjMatrix[i];
                delete[] adjMatrix;
            }
        }

        bool isEmpty();
        bool isDirected();
        bool addVertex(int newVertex);
        void addEdge(int vertex1, int vertex2);
        void removeEdge(int vertex1, int vertex2);
        void removeVertex(int vertex1, int vertex2);
        int numVertices();
        int numEdges();
        int indegree(int vertex);
        int outdegree(int vertex);
        int degree(int vertex);
        int neighbours(int vertex);
        bool neighbour(int vertex1, int vertex2);
        void displayMatrix();

    private:
        int n;
        int adjMatrix[10][10];
};