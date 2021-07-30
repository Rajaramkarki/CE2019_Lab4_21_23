#include<iostream>

using namespace std;

class Graph{
    public:
        Graph();
        ~Graph()
        {
            for (int i = 0; i < size; i++)
            {   delete[] adjMatrix[i];
                delete[] adjMatrix;
            }
        }

        bool vertex_index_exists(int &index, int target_vertex);
        bool isEmpty();
        bool isDirected();
        void addVertex(int newVertex);
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
        int size;
        int vertices[20];
        int last_vertex_index = 0;
        int adjMatrix[10][10];
};