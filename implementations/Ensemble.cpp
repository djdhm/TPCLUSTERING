
#include <chrono>
#include "Cluster.hpp"
#include "Point.hpp"
#include "Ensemble.hpp"
#include "../matplotlibcpp.h"

namespace plt = matplotlibcpp;

// Ajouter un point a l ensemble
void Ensemble::addPoint(Point point) {
    this->xarray.push_back(point.x);
    this->yarray.push_back(point.y);
}







// Constructeur de Ensemble avec une liste de RandomGenerator
Ensemble::Ensemble(std::vector<RandomGenerator> const & generators, int nombrePoints) {
    for (int k=0;k<generators.size();k++) {
        int cpt=nombrePoints;
        auto c=generators.at(k);
        while(cpt>0){
            auto point= c.getPoint();
            this->addPoint(point);
            cpt--;
            }
    }

}

// Generation aleatoire des centroids initiales
// On fait que prendre des elements existants de l ensemble
std::vector<Cluster> Ensemble::getRandomCentroids(int number) {
    std::vector<Cluster> centroids ;
    while(number>0){
        int x=rand() % getSize();
        centroids.push_back(Cluster(Point(xarray.at(x),yarray.at(x))));
        number--;
    }
    return centroids;
}



int Ensemble::getSize() {
    return xarray.size();
}


Point Ensemble::getPoint(int position) {
    return Point(xarray.at(position),yarray.at(position));
}


// Cette fonction permet d afficher les clusters
void plotClusters(std::vector<Cluster> clusters){

    auto iterator = clusters.begin();
    std::vector<double> clusterCentersX;
    std::vector<double> clusterCentersY;
    // Effacer le tableau de Plot
    plt::clf();
    for( ; iterator!=clusters.end(); iterator++){
        clusterCentersX.push_back(iterator->getCenterX());
        clusterCentersY.push_back(iterator->getCenterY());

        plt::plot(iterator->getXArray(),iterator->getYArray(),"d");

    }
    // afficher les centroids avec une couleur uni ( Etoile Rouhe)
    plt::plot(clusterCentersX,clusterCentersY,"r*");
    // Afficher en desactivant le blocage de thread principale
    plt::show(false);
    // Mettre le tableau en pause pour une seconde pour permettre de visualiser sinon ca passe vite
    plt::pause(1);
}
// On retourne le nombre de milliseconde de temps utilise pour l affichage pour les soustraire apres 
// du nombre total de la fonction pour avoir une idee plus precise sur le cout de calcul hors affichage
int Ensemble::kMeansClustering(int epochs, int k,char animation) {

    int n = getSize();
    int isAnimated = animation=='y';
    // On utilise la variable isChanged pour arreter la boucle si y a aucun changement
    bool isChanged = true;
    // On prend des points au hasard comme des centroids initialses
    std::vector<Cluster> centroids= getRandomCentroids(k);

    // Initialiser une variable de duration 
    std::chrono::milliseconds duration  ; 

    for (int i = 0; i < epochs && isChanged ; ++i) {


        // Pour chaque point on calcule les distance vers chaque centroids
        // et on met  a jour l attribution de point vers le nouveau cluster
        isChanged=false;
        for (int cpt=0;cpt< getSize();cpt++) {
            auto p =  getPoint(cpt);
            // Garder trace de l ancien cluster pour l attribuer a nouveau si y a pas de changement
            int choice = p.cluster;
        for (auto c = begin(centroids); c != end(centroids);++c) {
                double dist = c->getDistance(p);
                if (dist < p.minDist) {
                    choice=c->getClusterId();
                    p.minDist = dist;
                    isChanged=true;
                }
            }
        // On ajoute le point au cluster choisi
            centroids[choice-1].addPoint(p);
        }

        // Si l'utilisateur a demander de voir l animation on affiche a chaque etape les clusters intermediaires
        if(isAnimated || i==epochs) plotClusters(centroids);
    
        // Calculer les nouveaux centroids et effacer les points de chaque cluster pour preparer la prochaine iteration
        for (auto c = begin(centroids); c != end(centroids);
             ++c) {
            c->calculateCenter();
            if (i<epochs-1) c->reset();
        }





    }
    plotClusters(centroids);
    plt::pause(10);




}

