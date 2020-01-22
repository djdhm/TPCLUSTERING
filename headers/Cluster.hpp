//
// Created by djame on 16‏/12‏/2019.
//

#ifndef PROJ_CLUSTER_HPP
#define PROJ_CLUSTER_HPP


#include <vector>
#include "Point.hpp"

class Cluster {

private:
    static int id ;
    int clusterId;
    Point center ;
    std::vector<double> xarray;
    std::vector<double> yarray;
public:
    Cluster(Point p);
    void addPoint(Point point);
    double getDistance(Point p );
    void setCenter(double x,double y);
    std::vector<double> getXArray();
    std::vector<double> getYArray();

    void calculateCenter();
    double getCenterX();
    double getCenterY();
    int getClusterId();
    void reset();
    Point getCenter();
};


#endif //PROJ_CLUSTER_HPP
