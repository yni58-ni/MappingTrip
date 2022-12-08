#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <list>
#include <string>
#include <regex>

using namespace std;

class graph {
    int V;
    list<int> *adj;

    void printAllPathsUtil(int, int, bool[], int[], int&);

public:
    graph(int V); // Constructor
    void addEdge(int u, int v);
    void printAllPaths(int s, int d);
};










#endif
