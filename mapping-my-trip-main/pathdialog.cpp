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
#include <utility>
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

};

    pathDialog::~pathDialog()
    {
        delete ui;
    }

    void pathDialog::printDJKPath(int dest) {
        if (path[dest].size() == 0) {
            cout << "There is no path from the starting node to node " << dest << "." << endl;
            return;
        }

        cout << "The shortest path from the starting node to node " << dest << " is: ";
        for (int i = 0; i < path[dest].size(); i++) {
            cout << path[dest][i] << " ";
        }
        cout << endl;
    }

    void pathDialog::dijkstra(int start) {
        priority_queue<pair<int, int>> pq;

        for (int i = 1; i <= n; i++) {
            dist[i] = INF;
            path[i].clear();
        }
        dist[start] = 0;
        pq.push({0, start});

        while (!pq.empty()) {
            int cost = -pq.top().first;
            int here = pq.top().second;
            pq.pop();

            if (dist[here] < cost) {
                continue;
            }

            for (int i = 0; i < adj[here].size(); i++) {
                int there = adj[here][i].first;
                int nextDist = cost + adj[here][i].second;

                if (dist[there] > nextDist) {
                    dist[there] = nextDist;
                    path[there] = path[here];
                    path[there].push_back(there);
                    pq.push({-nextDist, there});
                }
            }
        }
    }


    //void pathDialog::on_position_clicked(){
    //     QMessageBox::information(this, "Error", "No position found");
    //}

    void pathDialog::on_shortPath_clicked(){           //Dijkstra algorithm
            n = 9;
            m = 20;
            adj[0].push_back({1,1});
            adj[0].push_back({5,1});
            adj[0].push_back({6,1});
            adj[1].push_back({4,3});
            adj[1].push_back({5,1});
            adj[1].push_back({8,5});
            adj[2].push_back({7,5});
            adj[2].push_back({3,11});
            adj[3].push_back({2,11});
            adj[3].push_back({5,4});
            adj[3].push_back({8,6});
            adj[4].push_back({1,3});
            adj[5].push_back({1,1});
            adj[5].push_back({6,2});
            adj[5].push_back({0,1});
            adj[6].push_back({0,1});
            adj[6].push_back({7,2});
            adj[7].push_back({2,5});
            adj[7].push_back({6,2});
            adj[8].push_back({1,5});



            int start = 2;
            dijkstra(start);

            printDJKPath(5);
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
        mapElements.insert(pair<int,string>(1,"Western University"));
        mapElements.insert(pair<int,string>(2,"Huron University College"));
        mapElements.insert(pair<int,string>(3,"Victoria Park"));
        mapElements.insert(pair<int,string>(4,"Sifton Bog"));
        mapElements.insert(pair<int,string>(5,"CF Masonville Place"));
        mapElements.insert(pair<int,string>(6,"Brescia University College"));
        mapElements.insert(pair<int,string>(7,"Talbot College"));
        mapElements.insert(pair<int,string>(8,"St. Joseph's Hospital"));
        mapElements.insert(pair<int,string>(9,"Museum Strathroy Caradoc"));
        
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
            for (int i = 0; i < adj2[curr].size(); i++)
            {
                int next = adj2[curr][i];
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
        mapElements.insert(pair<int,string>(1,"Western University"));
        mapElements.insert(pair<int,string>(2,"Huron University College"));
        mapElements.insert(pair<int,string>(3,"Victoria Park"));
        mapElements.insert(pair<int,string>(4,"Sifton Bog"));
        mapElements.insert(pair<int,string>(5,"CF Masonville Place"));
        mapElements.insert(pair<int,string>(6,"Brescia University College"));
        mapElements.insert(pair<int,string>(7,"Talbot College"));
        mapElements.insert(pair<int,string>(8,"St. Joseph's Hospital"));
        mapElements.insert(pair<int,string>(9,"Museum Strathroy Caradoc"));
        
        adj2[0].push_back(1);
        adj2[0].push_back(5);
        adj2[0].push_back(6);
        adj2[1].push_back(4);
        adj2[1].push_back(5);
        adj2[1].push_back(8);
        adj2[2].push_back(7);
        adj2[2].push_back(3);
        adj2[3].push_back(2);
        adj2[3].push_back(5);
        adj2[3].push_back(8);
        adj2[4].push_back(1);
        adj2[5].push_back(1);
        adj2[5].push_back(6);
        adj2[5].push_back(0);
        adj2[6].push_back(0);
        adj2[6].push_back(7);
        adj2[7].push_back(2);
        adj2[7].push_back(6);
        adj2[8].push_back(1);

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


