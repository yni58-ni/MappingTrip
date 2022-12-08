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
#include "dbhelper.h"
#include "graph.h"
#include "placeEntity.h"

using namespace std;

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

    void printBFSpath(vector<int>& path);

    int isNotVisited(int x, vector<int>& path);

    /**
     * Breadth first algorithm for all alternative routes
     * @brief findBFSpaths
     * @param vector<vector<int> >& g, int src, int dst, int v
     */
    void findBFSpaths(vector<vector<int> >& g, int src, int dst, int v);

    /**
     * invoke when alt1 button clicked, return the BFS algorithm
     * @brief on_alt1_clicked
     * @param startID, endID
     */
    void on_alt1_clicked();

    /**
     * invoke when piture item clicked
     * @brief on_alt2_clicked
     * @param startID, endID
     */
    void on_alt2_clicked();

    private:
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
