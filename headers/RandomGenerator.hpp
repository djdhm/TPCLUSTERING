//
// Created by djame on 16‏/12‏/2019.
//

#ifndef PROJ_RANDOMGENERATOR_HPP
#define PROJ_RANDOMGENERATOR_HPP


#include <random>

class RandomGenerator {
    std::random_device r;
    std::default_random_engine e1;
    std::uniform_real_distribution<double> randomX;
    std::uniform_real_distribution<double> randomY;

    public:
    RandomGenerator(const RandomGenerator&);
    RandomGenerator(double Xmin, double Xmax,double Ymin, double Ymax);
    double getRandomX();
    double getRandomY();
    Point getPoint();
};


#endif //PROJ_RANDOMGENERATOR_HPP
