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
#include "dbhelper.h"
#include "graph.h"
#include "placeEntity.h"

using namespace std;

const int MAX_NODES = 100; // maximum number of nodes in the graph

vector<int> adj[MAX_NODES]; // adjacency list representation of the graph
bool visited[MAX_NODES]; // array to keep track of visited nodes

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
     * @param adjacencyMatrix, startVertex
     */

    void dijkstra(vector<vector<int>> adjacencyMatrix,int startVertex);

    /**
     * invoke when short path clicked, return the shortest path using Dijkstra algorithm
     * @brief on_shortPath_clicked
     * @param startID, endID
     */
    void on_shortPath_clicked();

    void printPath(int currentVertex, vector<int> parents);

    void printSolution(int startVertex, vector<int> distances,vector<int> parents);

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
