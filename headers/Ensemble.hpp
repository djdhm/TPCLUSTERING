#ifndef PROJECT_WORLD_
#define PROJECT_WORLD_
#include <string>
#include <vector>
#include <typeinfo>
#include <iostream>
#include "Point.hpp"
#include "RandomGenerator.hpp"
#include "Cluster.hpp"

class Ensemble
    {
    private:
        /*  On sauvegarde les points de l ensemble dans deux vecteurs X et Y */
        std::vector<double> xarray;
        std::vector<double> yarray;


    public:
        Ensemble(std::vector<RandomGenerator> const  & generators,int nombrePoints);
        void addPoint(Point point);
        Point getPoint(int position);
        int getSize();
        std::vector<Cluster> getRandomCentroids(int number);
        int kMeansClustering (int epochs, int k,char animation);
};
    

   



#endif


