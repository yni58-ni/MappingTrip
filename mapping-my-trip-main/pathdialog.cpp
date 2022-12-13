#include <stdlib.h>
//#include <bits/stdc++.h>
#include <queue>
#include <QApplication>
#include <iostream>
#include <QFileDialog>
#include <QDebug>
#include "pathdialog.h"
#include "ui_pathdialog.h"
#include "graph.h"
#include <QMessageBox>
#include <limits.h>
#include <QDebug>
#include <QtGlobal>
#include <QString>
#include <QStringListModel>
#include <QInputDialog>
#include <map>
#include <vector>
#include <stack>

#include <vector>
using namespace std;

#define V 9   //num of vertices


pathDialog::pathDialog(){

}

pathDialog::pathDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pathDialog)
    {

    ui->setupUi(this);
    label = new QLabel(this);
    ui->scrollArea->setWidget(label);


    map<int, string> mapElements;
    mapElements.insert(pair<int,string>(1,"Western University"));
    mapElements.insert(pair<int,string>(2,"Huron University College"));
    mapElements.insert(pair<int,string>(3,"Victoria Park"));
    mapElements.insert(pair<int,string>(4,"Sifton Bog"));
    mapElements.insert(pair<int,string>(5,"CF Masonville Place"));
    mapElements.insert(pair<int,string>(6,"Brescia University College"));
    mapElements.insert(pair<int,string>(7,"Talbot College"));
    mapElements.insert(pair<int,string>(8,"St. Joseph's Hospital"));
    mapElements.insert(pair<int,string>(9,"Museum Strathroy Caradoc"));

};

    pathDialog::~pathDialog()
    {
        delete ui;
    }

    void pathDialog::printPath(int currentVertex, vector<int> parents)
    {
        int NO_PARENT = -1;

        if (currentVertex == NO_PARENT) {
            return;
        }
        printPath(parents[currentVertex], parents);
        cout << currentVertex << " ";
    }

    void pathDialog::printSolution(int startVertex, vector<int> distances,
                       vector<int> parents)
    {
        int nVertices = distances.size();
        cout << "Vertex\t Distance\tPath";

        for (int vertexIndex = 0; vertexIndex < nVertices;
             vertexIndex++) {
            if (vertexIndex != startVertex) {
                cout << "\n" << startVertex << " -> ";
                cout << vertexIndex << " \t\t ";
                cout << distances[vertexIndex] << "\t\t";
                printPath(vertexIndex, parents);
            }
        }
    }

    void pathDialog::dijkstra(vector<vector<int> > adjacencyMatrix,
                  int startVertex)
    {
        int NO_PARENT = -1;
        int nVertices = adjacencyMatrix[0].size();

        vector<int> shortestDistances(nVertices);

        vector<bool> added(nVertices);

        for (int vertexIndex = 0; vertexIndex < nVertices;
             vertexIndex++) {
            shortestDistances[vertexIndex] = INT_MAX;
            added[vertexIndex] = false;
        }

        shortestDistances[startVertex] = 0;

        // Parent array
        vector<int> parents(nVertices);

        // The starting vertex does not have a parent
        parents[startVertex] = NO_PARENT;

        // Find shortest path for all vertices
        for (int i = 1; i < nVertices; i++) {

            int nearestVertex = -1;
            int shortestDistance = INT_MAX;
            for (int vertexIndex = 0; vertexIndex < nVertices;
                 vertexIndex++) {
                if (!added[vertexIndex]
                    && shortestDistances[vertexIndex]
                           < shortestDistance) {
                    nearestVertex = vertexIndex;
                    shortestDistance
                        = shortestDistances[vertexIndex];
                }
            }

            // Mark the picked vertex as processed
            added[nearestVertex] = true;

            // Update list value
            for (int vertexIndex = 0; vertexIndex < nVertices; vertexIndex++) {
                int edgeDistance
                    = adjacencyMatrix[nearestVertex]
                                     [vertexIndex];

                if (edgeDistance > 0 && ((shortestDistance + edgeDistance) < shortestDistances[vertexIndex])) {
                    parents[vertexIndex] = nearestVertex;
                    shortestDistances[vertexIndex]
                        = shortestDistance + edgeDistance;
                }
            }
        }

        printSolution(startVertex, shortestDistances, parents);
    }

    //void pathDialog::on_position_clicked(){
    //     QMessageBox::information(this, "Error", "No position found");
    //}

    void pathDialog::on_shortPath_clicked(){           //Dijkstra algorithm
        vector<vector<int> > adjacencyMatrix
                = { { 0, 0, 0, 5, 0, 0, 0, 0, 0 },
                    { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                    { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                    { 0, 0, 0, 2, 0, 0, 0, 0, 0 },
                    { 9, 0, 0, 0, 1, 0, 0, 0, 0 },
                    { 0, 0, 0, 6, 0, 7, 0, 0, 0 },
                    { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                    { 0, 0, 0, 0, 0, 0, 8, 0, 0 },
                    { 0, 0, 4, 0, 0, 0, 0, 0, 3 } };
         int startIndex = ui->comboBox->currentIndex();
         dijkstra(adjacencyMatrix, startIndex);
    }



    // Helper function to print the path from the source node
    // to the destination node, using the parent array
    void pathDialog::printPath(vector<int>& parent, int dest)
    {
        // If the destination node is not reached
        if (parent[dest] == -1)
        {
            cout << "No path from source to destination exists" << endl;
            return;
        }

        // Print the path in reverse order (from destination to source)
        vector<int> path;
        int curr = dest;
        while (curr != -1)
        {
            path.push_back(curr);
            curr = parent[curr];
        }

        // Reverse the path and print it
        reverse(path.begin(), path.end());
        cout << "Path from source to destination: ";
        for (int node : path)
            cout << node << " ";
        cout << endl;
    }

    // Function that implements a breadth-first search
    // from the source node to the destination node
    void pathDialog::BFS(vector<int>* edges, int numNodes, int source, int dest)
    {
        // Create a queue to store the nodes in the order
        // in which they are visited
        queue<int> q;

        // Create a vector to store the parent of each node
        vector<int> parent(numNodes, -1);

        // Create a vector to store the visited status
        // of each node
        vector<bool> visited(numNodes, false);

        // Push the source node into the queue and mark it
        // as visited
        q.push(source);
        visited[source] = true;

        // Iterate until the queue is empty
        while (!q.empty())
        {
            // Get the front of the queue and pop it
            int curr = q.front();
            q.pop();
        // If the current node is the destination node,
        // print the path and return
        if (curr == dest)
        {
            printPath(parent, dest);
            return;
        }

        // Get the list of neighbors of the current node
        vector<int>& neighbors = edges[curr];

        // Iterate over the neighbors
        for (int neighbor : neighbors)
        {
            // If the neighbor has not been visited,
            // push it into the queue and mark it as visited
            if (!visited[neighbor])
            {
                q.push(neighbor);
                visited[neighbor] = true;
                parent[neighbor] = curr;
            }
        }
    }

    // If the destination node is not reached and the queue is empty,
    // print a message indicating that no path exists
    cout << "No path from source to destination exists" << endl;
    }

    void pathDialog::on_alt1_clicked(){         //BFS search
//        vector<vector<int> > g;
//        // number of vertices
//        int v = 9;
//        g.resize(9);
//        g[0].push_back(1);
//        g[0].push_back(5);
//        g[0].push_back(6);
//        g[1].push_back(4);
//        g[1].push_back(5);
//        g[1].push_back(8);
//        g[2].push_back(7);
//        g[2].push_back(3);
//        g[3].push_back(2);
//        g[3].push_back(5);
//        g[3].push_back(8);
//        g[4].push_back(1);
//        g[5].push_back(0);
//        g[5].push_back(1);
//        g[5].push_back(6);
//        g[6].push_back(0);
//        g[6].push_back(7);
//        g[7].push_back(2);
//        g[7].push_back(6);
//        g[8].push_back(1);

        vector<int> edges[9];
        edges[0].push_back(1);
        edges[0].push_back(5);
        edges[0].push_back(6);
        edges[1].push_back(4);
        edges[1].push_back(5);
        edges[1].push_back(8);
        edges[2].push_back(7);
        edges[2].push_back(3);
        edges[3].push_back(2);
        edges[3].push_back(5);
        edges[3].push_back(8);
        edges[4].push_back(1);
        edges[5].push_back(1);
        edges[5].push_back(6);
        edges[5].push_back(0);
        edges[6].push_back(0);
        edges[6].push_back(7);
        edges[7].push_back(2);
        edges[7].push_back(6);
        edges[8].push_back(1);

        int start, end;
        start = ui->comboBox->currentIndex();
        end = ui->comboBox2->currentIndex();
        string it1 = mapElements.at(start);
        string it2 = mapElements.at(end);
        QString xy1 = QString::fromStdString(it1);
        QString xy2 = QString::fromStdString(it2);
        QString status = QString("BFS Paths from the start %1 to end %2 are \n").arg(xy1,xy2);
        qDebug()<<status;
        BFS(edges, 9, start, end);
    }


    void pathDialog::dfs(int start, int end)
    {

        // Create a stack for the depth-first search
        stack<int> st;

        // Push the starting node onto the stack
        st.push(start);

        // Mark the starting node as visited
        visited[start] = true;

        // Loop until the stack is empty
        while (!st.empty())
        {
            // Get the top element from the stack
            int curr = st.top();
            st.pop();

            // Print the current node
            cout << curr << " ";

            // Check if we have reached the destination node
            if (curr == end)
            {
                return; // End the search
            }

            // Loop through the adjacent nodes of the current node
            for (int i = 0; i < adj[curr].size(); i++)
            {
                int next = adj[curr][i];
                if (!visited[next])
                {
                    // Push the next node onto the stack and mark it as visited
                    st.push(next);
                    visited[next] = true;
                }
            }
        }
    }

    void pathDialog::on_alt2_clicked(){         //DFS search
        adj[0].push_back(1);
        adj[0].push_back(5);
        adj[0].push_back(6);
        adj[1].push_back(4);
        adj[1].push_back(5);
        adj[1].push_back(8);
        adj[2].push_back(7);
        adj[2].push_back(3);
        adj[3].push_back(2);
        adj[3].push_back(5);
        adj[3].push_back(8);
        adj[4].push_back(1);
        adj[5].push_back(1);
        adj[5].push_back(6);
        adj[5].push_back(0);
        adj[6].push_back(0);
        adj[6].push_back(7);
        adj[7].push_back(2);
        adj[7].push_back(6);
        adj[8].push_back(1);

        int start = ui->comboBox->currentIndex();
        int end = ui->comboBox2->currentIndex();
        string it3 = mapElements.at(start);
        string it4 = mapElements.at(end);
        QString xy1 = QString::fromStdString(it3);
        QString xy2 = QString::fromStdString(it4);
        QString status = QString("Following is the DFS path from %1 to %2 \n").arg(xy1,xy2);
        qDebug()<<status;

        dfs(start,end);

    }


