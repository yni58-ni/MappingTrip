#include <stdlib.h>
#include <bits/stdc++.h>
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
#include <QString>
#include <QStringListModel>
#include <QInputDialog>
#include <map>

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

                if (edgeDistance > 0
                    && ((shortestDistance + edgeDistance)
                        < shortestDistances[vertexIndex])) {
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




    //all utility functions for alt1 route
    void pathDialog::printBFSpath(vector<int>& path)
    {
        int size = path.size();
        for (int i = 0; i < size; i++){
            auto it = mapElements.find(i+1);
            cout << it->second << " ";
            cout << endl;
        }
    }

    int pathDialog::isNotVisited(int x, vector<int>& path)
    {
        int size = path.size();
        for (int i = 0; i < size; i++)
            if (path[i] == x)
                return 0;
        return 1;
    }


    void pathDialog::findBFSpaths(vector<vector<int> >& g, int src, int dst,
                   int v)
    {
        queue<vector<int> > q;

        // path vector to store the current path
        vector<int> path;
        path.push_back(src);
        q.push(path);
        while (!q.empty()) {
            path = q.front();
            q.pop();
            int last = path[path.size() - 1];

            // check if last vertex is the destination

            if (last == dst)
                printBFSpath(path);

            // traverse to all the nodes connected to current vertex
            for (int i = 0; i < g[last].size(); i++) {
                if (isNotVisited(g[last][i], path)) {
                    vector<int> newpath(path);
                    newpath.push_back(g[last][i]);
                    q.push(newpath);
                }
            }
        }
    }

    void pathDialog::on_alt1_clicked(){         //BFS search
        vector<vector<int> > g;
        // number of vertices
        int v = 9;
        g.resize(9);
        g[0].push_back(1);
        g[0].push_back(5);
        g[0].push_back(6);
        g[1].push_back(4);
        g[1].push_back(5);
        g[1].push_back(8);
        g[2].push_back(7);
        g[2].push_back(3);
        g[3].push_back(2);
        g[3].push_back(5);
        g[3].push_back(8);
        g[4].push_back(1);
        g[5].push_back(0);
        g[5].push_back(1);
        g[5].push_back(6);
        g[6].push_back(0);
        g[6].push_back(7);
        g[7].push_back(2);
        g[7].push_back(6);
        g[8].push_back(1);



        int start, end;
        start = ui->comboBox->currentIndex();
        end = ui->comboBox2->currentIndex();
        auto it1 = mapElements.find(start);
        auto it2 = mapElements.find(end);
        cout << "paths from start " << it1->second << " to end " << it2->second
                 << " are \n";
        findBFSpaths(g, start, end, v);
    }



    void pathDialog::on_alt2_clicked(){         //DFS search
        graph g(9);
        g.addEdge(0,1);
        g.addEdge(0,5);
        g.addEdge(0,6);
        g.addEdge(1,4);
        g.addEdge(1,5);
        g.addEdge(1,8);
        g.addEdge(2,7);
        g.addEdge(2,3);
        g.addEdge(3,2);
        g.addEdge(3,5);
        g.addEdge(3,8);
        g.addEdge(4,1);
        g.addEdge(5,0);
        g.addEdge(5,1);
        g.addEdge(5,6);
        g.addEdge(6,0);
        g.addEdge(6,7);
        g.addEdge(7,2);
        g.addEdge(7,6);
        g.addEdge(8,1);

        int start, end;
        start = ui->comboBox->currentIndex();
        end = ui->comboBox2->currentIndex();
        auto it3 = mapElements.find(start);
        auto it4 = mapElements.find(end);
        cout << "Following are all different paths from " << it3->second
                 << " to " << it4->second << endl;
        g.printAllPaths(start, end);

    }


