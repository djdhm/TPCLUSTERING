#include <iostream>
#include "Cluster.hpp"

int Cluster::id=1;

Cluster::Cluster(Point center):clusterId{Cluster::id++},center{center} {
}

void Cluster::addPoint(Point point) {
    this->xarray.push_back(point.x);
    this->yarray.push_back(point.y);
    point.cluster=this->clusterId;
}

void Cluster::setCenter(double x, double y) {
    this->center=Point(x,y);
}

void Cluster::calculateCenter(){
    double sumx=0,sumy=0, size= xarray.size();
    auto xiterator= xarray.begin();
    auto yiterator= yarray.begin();

    for( ; xiterator!=xarray.end(); xiterator++,yiterator++){
            sumx += *xiterator;
            sumy += *yiterator;
    }

    this->setCenter(sumx/size,sumy/size);

}
double Cluster::getCenterX(){
    return center.x;
}
double Cluster::getCenterY(){
    return center.y;
}
int Cluster::getClusterId(){
    return clusterId;
};
Point Cluster::getCenter(){
    return center;
}
double  Cluster::getDistance(Point p) {
    return center.distance(p);
}

std::vector<double> Cluster::getXArray() {
    return xarray;
}

std::vector<double> Cluster::getYArray() {
    return yarray;
}

void Cluster::reset() {
    xarray=std::vector<double >();
    yarray=std::vector<double >();

}