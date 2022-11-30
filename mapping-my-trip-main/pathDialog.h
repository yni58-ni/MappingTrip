#ifndef PATHDIALOG_H
#define PATHDIALOG_H

#include <QDialog>
#include <QLabel>
#include "dbhelper.h"
#include "placeEntity.h"

namespace Ui {
class pathDialog;
}


private slots:
    /**
     * invoke when a position button is clicked, return its information
     * @brief on_position_clicked
     */
    void on_position_clicked();

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
    void on_shortPath_clicked(int startID, int endID);


    void printBFSpath(vector<int>& path);

    int isNotVisited(int x, vector<int>& path);

    /**
     * Breadth first algorithm for all alternative routes
     * @brief findBFSpaths
     * @param vector<vector<int> >& g, int src, int dst, int v
     */
    void findBFSpaths(vector<vector<int> >& g, int src, int dst, int v)

    /**
     * invoke when alt1 button clicked, return the BFS algorithm
     * @brief on_alt1_clicked
     * @param startID, endID
     */
    void on_alt1_clicked(int startID, int endID);

    /**
     * invoke when piture item clicked
     * @brief on_alt2_clicked
     * @param startID, endID
     */
    void on_alt2_clicked(int startID, int endID);

    private:
        Ui::pathDialog *ui;
        /**
         * current placeId
         * @brief placeId
         */
        int placeId;

        QLabel *label;

        DBHelper helper;
        QList<placeEntity> pList;
    };

    #endif // PATHDIALOG_H
