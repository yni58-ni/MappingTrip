#ifndef PATHDIALOG_H
#define PATHDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QApplication>
#include <QMessageBox>
#include <limits.h>
#include <QDebug>
#include <QStringListModel>
#include <QInputDialog>
#include <map>
#include <vector>
#include <stack>
#include <utility>
#include "dbhelper.h"
#include "graph.h"
#include "placeEntity.h"

using namespace std;

const int MAX_NODES = 100; // maximum number of nodes in the graph

namespace Ui {
class pathDialog;
}

class pathDialog : public QDialog
{
    Q_OBJECT

public:
    pathDialog();
    pathDialog(QWidget *parent);

    ~pathDialog();

private slots:

    //void on_position_clicked();

    /**
     * Dijkstra algorithm to return the optimal route
     * @brief dijkstra
     * @param start
     */

    void dijkstra(int start);

    /**
     * invoke when short path clicked, return the shortest path using Dijkstra algorithm
     * @brief on_shortPath_clicked
     * @param startID, endID
     */
    void on_shortPath_clicked();  

    /**
     * print the path from starting node to destination node
     * @brief printDJKPath
     * @param dest
     */
    void printDJKPath(int dest);

    void printPath(vector<int>& parent, int dest);


    /**
     * Breadth first algorithm for all alternative routes
     * @brief BFS
     * @param vector<int>* edges, int numNodes, int source, int dest
     */
    void BFS(vector<int>* edges, int numNodes, int source, int dest);

    /**
     * invoke when alt1 button clicked, return the BFS algorithm
     * @brief on_alt1_clicked
     * @param startID, endID
     */
    void on_alt1_clicked();

    void dfs(int start, int end);

    /**
     * invoke when piture item clicked
     * @brief on_alt2_clicked
     * @param startID, endID
     */
    void on_alt2_clicked();

    private:
//        // define a simple graph structure with adjacency list representation
//        struct Graph {
//            int num_nodes;
//            vector<vector<int>> adjacency_list;
//        };
        const int INF = 1000000000;

        vector<pair<int, int>> adj[100001];
        int dist[100001];
        int n, m;
        vector<int> path[100001];



        vector<int> adj2[MAX_NODES]; // adjacency list representation of the graph
        bool visited[MAX_NODES]; // array to keep track of visited nodes


        Ui::pathDialog *ui;
        /**
         * current placeId
         * @brief placeId
         */
        int placeId;

        QLabel *label;

        DBHelper helper;
        map<int, string> mapElements;
        QList<placeEntity> pList;

};

#endif // PATHDIALOG_H
