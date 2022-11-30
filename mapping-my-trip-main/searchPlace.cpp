#include "searchPlace.h"
#include <QPlaceResult>
#include <QDebug>

/**
 * @brief searchPlace class to search place on a map
 * @author Nicole Ni
 * @param name
 * @return none
 */

searchPlace::searchPlace(QString name)   // constructor
{ // initizlizing a manager

    provider = new QGeoServiceProvider("osm");
    manager = provider ->placeManager();

    //instantiate request and set parameters
    searchRequest.setSearchTerm(name);
    searchRequest.setSearchArea(QGeoCircle(QGeoCoordinate(10,10)));

    // send offf a search request
    searchReply = manager -> search(searchRequest);

    //connect a slot to handle the reply
    connect(searchReply,SIGNAL(finished()),this,SLOT(handleSearchReply()));
}

/**
 * @brief method (slot) to handle the completion of the request
 * @return details of the place
 */

void searchPlace::handleSearchReply(){
    if(searchReply ->error() == QPlaceReply::NoError){
        foreach(const QPlaceSearchResult &result,searchReply -> results()){
            if(result.type() == QPlaceSearchResult :: PlaceResult){
                QPlaceResult placeResult = result;
                qDebug() << "Name: " << placeResult.place().name();
                qDebug() << "Street: " << placeResult.place().location().address().street();
                qDebug() << "Distance: " << placeResult.distance();
            }
        }
    }
    searchReply -> deleteLater(); // discard reply
    searchReply = 0;
}
