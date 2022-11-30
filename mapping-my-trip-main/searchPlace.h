#ifndef SEARCHPLACE_H
#define SEARCHPLACE_H
#include <QPlaceManager>
#include<QGeoServiceProvider>
#include<QGeoCircle>
#include<QPlaceSearchReply>
#include<QObject>
#include <QString>

/**
 * @brief The searchPlace class to search places on the map
 * @author Nicole Ni
 */

class searchPlace : public QObject
{
public:
    searchPlace(QString name);
private slots:
    void handleSearchReply(); // a slot to handle the completion of the request
private:
    QGeoServiceProvider *provider;
    QPlaceManager *manager;
    QPlaceSearchRequest searchRequest;
    QPlaceSearchReply *searchReply;
};

#endif // SEARCHPLACE_H
