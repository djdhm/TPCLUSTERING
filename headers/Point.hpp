#ifndef POINT_DEFINITION
#define POINT_DEFINITION
struct Point {
    double x, y;     // les coordonnes X et Y
    int cluster;
    double minDist;  // par Default a MAX

    Point() : x(0.0), y(0.0), cluster(-1), minDist(__DBL_MAX__) {}
    Point(double x, double y) : x(x), y(y), cluster(-1), minDist(__DBL_MAX__) {}

    double distance(Point p) {
        return (p.x - x) * (p.x - x) + (p.y - y) * (p.y - y);
    }
};


#endif