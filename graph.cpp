#include<iostream>
#include "graph.h"

using namespace std;

Graph::Graph()
{
    this->last_vertex_index = 0;
    for (int i = 0; i <= size; i++)
    {
        for (int j = 0; j <= size; j++)
        {
            this->adjMatrix[i][j] = 0;
        }
    }
}

bool Graph::isEmpty()
{
    if (last_vertex_index == 0)
    {
        return true;
    }
    else
        return false;
}

void Graph::addVertex(int newVertex)
{
    vertices[last_vertex_index] = newVertex;
    last_vertex_index++;
}

void Graph ::addEdge(int vertex1, int vertex2)
{
    int index_of_vertex1, index_of_vertex2;
    if (vertex_index_exists(index_of_vertex1, vertex1) && vertex_index_exists(index_of_vertex2, vertex2))
    {
        this->adjMatrix[index_of_vertex1][index_of_vertex2] = 1;
    }
}

void Graph::removeEdge(int vertex1, int vertex2)
{
    int index_of_vertex1, index_of_vertex2;
    if (vertex_index_exists(index_of_vertex1, vertex1) && vertex_index_exists(index_of_vertex2, vertex2))
    {
        this->adjMatrix[index_of_vertex1][index_of_vertex2] = 0;
    }
}

bool Graph :: vertex_index_exists(int &index, int target_vertex)
{
    for (int i = 0; i <= last_vertex_index; i++)
    {
        if (this->vertices[i] == target_vertex)
        {
            index = i;
            return true;
        }
    }
    return false;
}

void Graph::removeVertex(int vertex)
{
    int index;
    if (vertex_index_exists(index, vertex))
    {
        for (int i = 0; i <= size; i++)
        {
            this->adjMatrix[index][i] = 0;
        }
        this->vertices[index] = 0;

        for (int i = index; i <= size - 1; i++)
        {
            this->vertices[i] = this->vertices[i + 1];
        }
        last_vertex_index--;
    }
}
int Graph::numEdges()
{
    if (!isEmpty())
    {
        int edges = 0;
        for (int i = 0; i <= last_vertex_index; i++)
        {
            for (int j = 0; j <= last_vertex_index; j++)
            {
                if (this->adjMatrix[i][j] == 1)
                {
                    edges++;
                }
            }
        }
        return edges;
    }
}
