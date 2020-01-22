//
// Created by djame on 16‏/12‏/2019.
//

#include "iostream"
#include <Point.hpp>
#include "RandomGenerator.hpp"

// La classe RandomGenerator permet de  generer des nombres  aleatoires  avec une distribution normale
// Avec des bornes


RandomGenerator::RandomGenerator(double Xmin, double Xmax, double Ymin, double Ymax) {
        this->e1=std::default_random_engine(this->r());
        randomX=std::uniform_real_distribution(Xmin,Xmax);
        randomY=std::uniform_real_distribution(Ymin,Ymax);

}


double RandomGenerator::getRandomX() {
    return randomX(this->e1);

}
RandomGenerator::RandomGenerator(const RandomGenerator & test) {
    this->randomX=test.randomX;
    this->randomY=test.randomY;

}

double RandomGenerator::getRandomY() {
    return randomY(this->e1);

}

Point RandomGenerator::getPoint(){
        return Point(this->getRandomX(),this->getRandomY());

}