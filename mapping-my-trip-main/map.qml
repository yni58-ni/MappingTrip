import QtQuick 2.0
import QtLocation 5.6
import QtPositioning 5.6
import mapdialog 1.0
Rectangle{
    id: window
    property double oldLat: 42.984908
    property double oldLng: -81.245303
    property Component comMarker: mapMarker
    property variant locationOslo: QtPositioning.coordinate( 59.93, 10.76)


    Plugin{
        id:mapPlugin
        name:"osm"
        PluginParameter { name: "osm.mapping.custom.host"; value: true }
        PluginParameter { name: "osm.mapping.providersrepository.disabled"; value: true}
    }

    MapDialog{
        id:myMap
    }

    Map {
        id: mapView
        anchors.fill: parent
        plugin:mapPlugin
        center: QtPositioning.coordinate(oldLat, oldLng);
        zoomLevel: 13

        //Current Location
        PositionSource {
            id: positionSource
            property variant lastSearchPosition: locationOslo
            active: true
            updateInterval: 120000 // 2 mins
            onPositionChanged:  {
                var currentPosition = positionSource.position.coordinate
                mapView.center = currentPosition
                var distance = currentPosition.distanceTo(lastSearchPosition)
                if (distance > 500) {
                    // 500m from last performed pizza search
                    lastSearchPosition = currentPosition
                    searchModel.searchArea = QtPositioning.circle(currentPosition)
                    searchModel.update()
                }
            }
        }

        //PlaceSearchModel
        PlaceSearchModel {
            id: searchModel

            plugin: mapPlugin

            searchTerm: MapDialog.p_name
            searchArea: QtPositioning.circle(locationOslo)

            Component.onCompleted: update()
        }

        MapItemView {
            model: searchModel
            delegate: MapQuickItem {
                coordinate: place.location.coordinate

                anchorPoint.x: image.width * 0.5
                anchorPoint.y: image.height

                sourceItem: Column {
                    Image { id: image; source: "qrc:/map_pin.png" }
                    Text { text: title; font.bold: true }
                }
            }
        }

        Connections {
            target: searchModel
            onStatusChanged: {
                if (searchModel.status == PlaceSearchModel.Error)
                    console.log(searchModel.errorString());
            }
        }

        MouseArea {
            anchors.fill: parent
            onPressAndHold: {
                var name = qsTr("untitled");
                var crd = mapView.toCoordinate(Qt.point(mouseX, mouseY))
                console.log(crd.latitude, crd.longitude, crd.altitude,name);

                onAddPoint(crd.latitude, crd.longitude, name);
            }

            onDoubleClicked: {
                var name = qsTr("untitled");
                var crd = mapView.toCoordinate(Qt.point(mouseX, mouseY))
                console.log(crd.latitude, crd.longitude, crd.altitude,name);

                onAddPoint(crd.latitude, crd.longitude, name);
            }
        }
    }

    signal onAddPoint(var latitude, var longitude, var name);

    signal onPointClicked(var pointId);

    function doAddPoint(pointId, latitude, longitude) {
        var item = comMarker.createObject(window, {  coordinate: QtPositioning.coordinate(latitude, longitude), pointId:pointId  })
        mapView.addMapItem(item)
    }

    Component {
            id: mapMarker
            MapQuickItem {
                id: markerImg
                anchorPoint.x: image.width/4
                anchorPoint.y: image.height
                coordinate: position
                property int pointId: -1

                sourceItem: Image {
                    id: image
                    source: "qrc:/map_pin.png"

                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            onPointClicked(pointId);
                        }
                    }
                }
            }
        }

}
