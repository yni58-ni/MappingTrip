#include <iostream>
#include <list>
#include <stdlib.h>
#include <QString>
#include <QDebug>
#include "graph.h"

using namespace std;

graph::graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
}

// Prints all paths from 's' to 'd'
void graph::printAllPaths(int s, int d)
{
    // Mark all the vertices as not visited
    bool* visited = new bool[V];

    // Create an array to store paths
    int* path = new int[V];
    int path_index = 0; // Initialize path[] as empty

    // Initialize all vertices as not visited
    for (int i = 0; i < V; i++)
        visited[i] = false;

    // Call the recursive helper function to print all paths
    printAllPathsUtil(s, d, visited, path, path_index);
}


void graph::printAllPathsUtil(int u, int d, bool visited[],
                              int path[], int& path_index)
{
    visited[u] = true;
    path[path_index] = u;
    path_index++;

    // Check if current vertex is same as destination
    if (u == d) {
        for (int i = 0; i < path_index; i++)
            qDebug()<< path[i]<<" ";
//            cout << path[i] << " ";
//        cout << endl;
    }
    else // If current vertex is not destination
    {
        list<int>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
            if (!visited[*i])
                printAllPathsUtil(*i, d, visited, path,
                                  path_index);
    }

    // Remove current vertex from path[] and mark it as unvisited
    path_index--;
    visited[u] = false;
}

