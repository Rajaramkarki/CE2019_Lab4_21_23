#include<iostream>
#include "graph.h"

using namespace std;

Graph::Graph()
{
    cout<<"Do you want your graph to be directed or not? (Enter 1 for yes and 0 for no):";
    cin>>directed;
    this->last_vertex_index = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            this->adjMatrix[i][j] = 0;
        }
    }
}

bool Graph::isDirected()
{
    if(directed==1)
    {
        return true;
    }
    else
    {
        return false;
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

void Graph ::addEdge(int vertex1, int vertex2)
{
    if(directed==1)
    {
    int index_of_vertex1, index_of_vertex2;
    if (vertex_index_exists(index_of_vertex1, vertex1) && vertex_index_exists(index_of_vertex2, vertex2))
    {
        this->adjMatrix[index_of_vertex1][index_of_vertex2] = 1;
    }
    }

    else
    {
    int index_of_vertex1, index_of_vertex2;
    if (vertex_index_exists(index_of_vertex1, vertex1) && vertex_index_exists(index_of_vertex2, vertex2))
    {
        this->adjMatrix[index_of_vertex1][index_of_vertex2] = 1;
        this->adjMatrix[index_of_vertex2][index_of_vertex1] = 1;
    } 
    }
}

void Graph::removeEdge(int vertex1, int vertex2)
{
    if(directed==1)
    {
        int index_of_vertex1, index_of_vertex2;
        if (vertex_index_exists(index_of_vertex1, vertex1) && vertex_index_exists(index_of_vertex2, vertex2))
        {
            this->adjMatrix[index_of_vertex1][index_of_vertex2] = 0;
        }
        else       
        {
            cout<<"The given edge doesn't exist"<<endl;
        }
    }
    else
    {
        int index_of_vertex1, index_of_vertex2;
        if (vertex_index_exists(index_of_vertex1, vertex1) && vertex_index_exists(index_of_vertex2, vertex2))
        {
            this->adjMatrix[index_of_vertex1][index_of_vertex2] = 0;
            this->adjMatrix[index_of_vertex2][index_of_vertex1] = 0;
        }
        else       
        {
            cout<<"The given edge doesn't exist"<<endl;
        }
    }
}

void Graph::removeVertex(int vertex)
{
    int index;
    if (vertex_index_exists(index, vertex))
    {
        for (int i = 0; i < 16; i++)
        {
             if (this->adjMatrix[index][i] == 1 || this->adjMatrix[i][index] == 1)
            {
                this->adjMatrix[index][i] = 0;
                this->adjMatrix[i][index] = 0;
            }
        }
        this->vertices[index] = 0;

        for (int i = index; i <= last_vertex_index; i++)
        {
            this->vertices[i] = this->vertices[i + 1];
        }
        last_vertex_index--;
    }   
}


int Graph::numEdges()
{
    if(directed==1)
    {
        if (!isEmpty())
        {
            int edges = 0;
            for (int i = 0; i < 16; i++)
            {
                for (int j = 0; j < 16; j++)
                {
                    if (this->adjMatrix[i][j] == 1)
                    {
                        edges++;
                    }
                }
            }
            return edges;
        }
        else
        {
            cout<<"The given graph is empty"<<endl;
            return 0;
        }
    }

    else
    {
        if (!isEmpty())
        {
            int edges = 0;
            for (int i = 0; i < 16; i++)
            {
                for (int j = i; j < 16; j++)
                {
                    if (this->adjMatrix[i][j] == 1)
                    {
                        edges++;
                    }
                }
            }
            return edges;
        }
        else
        {
            cout<<"The given graph is empty"<<endl;
            return 0;
        }
    }
}

int Graph::numVertices()
{
        return last_vertex_index;
}

void Graph::displayMatrix()
{   
    cout<<"\nThe adjacency matrix is:"<<endl;
       for(int i=0; i<16; i++)
        {
                for(int j=0; j<16; j++)
                {
                        cout<<" "<<adjMatrix[i][j]<<" ";
                }
                cout<<"\n";
        }
}

int Graph::degree(int vertex)
{
    if(directed==1)
    {
        return indegree(vertex)+outdegree(vertex);
    }  
    else
    {
        int index_of_vertex;
        int degree=0;
        if (vertex_index_exists(index_of_vertex, vertex))
        {
            for(int i=0; i<16; i++)
            {
                if(this->adjMatrix[i][index_of_vertex] == 1 && this->adjMatrix[index_of_vertex][i] == 1)
                {
                    degree++;
                }
            }
        }
        return degree;
    }
}

int Graph::indegree(int vertex)
{
    if(directed==1)
    {
        int index_of_vertex;
        int indegree=0;
        if (vertex_index_exists(index_of_vertex, vertex))
        {
            for(int i=0; i<16; i++)
            {
                if(this->adjMatrix[i][index_of_vertex] == 1)
                {
                    indegree++;
                }
            }
        }
        return indegree;
    }
    else
    {
        cout<<"The indegree cannot be determined as the graph is undirected but the degree of entered vertex is:"<<degree(vertex)<<endl;
        return 0;
    }
}

int Graph::outdegree(int vertex)
{
    if(directed==1)
    {
        int index_of_vertex;
        int outdegree=0;
        if (vertex_index_exists(index_of_vertex, vertex))
        {
            for(int i=0; i<16; i++)
            {
                if(this->adjMatrix[index_of_vertex][i] == 1)
                {
                    outdegree++;
                }
            }
        }
        return outdegree;
    }
    else
    {
        cout<<"The outdegree cannot be determined as the graph is undirected but the degree of entered vertex is:"<<degree(vertex)<<endl;
        return 0;
    }
}

bool Graph::neighbour(int vertex1, int vertex2)
{
    int index_of_vertex1, index_of_vertex2;
    if (vertex_index_exists(index_of_vertex1, vertex1) && vertex_index_exists(index_of_vertex2, vertex2))
    {
        if(this->adjMatrix[index_of_vertex1][index_of_vertex2] == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else       
    {
        cout<<"The given vertices doesn't exist."<<endl;
        return false;
    }
}

void Graph::neighbours(int vertex)
{
    int index_of_vertex, c=0;
    if (vertex_index_exists(index_of_vertex, vertex))
    {
        cout<<"The neighbours of given vertex are: "<<endl;
        for(int i=0; i<16; i++)
        {
            if(this->adjMatrix[index_of_vertex][i] == 1)
            {
                cout<<vertices[i]<<endl;
                c++;
            }
        }
        if(c==0)
        {
            cout<<"Error! There are no neighbours of the given vertex."<<endl;
        }
    }
    else
    {
        cout<<"Error!! The vertex doesn't exist."<<endl;
    }
}

