
#include <iostream>
#include <vector>

#include <Ensemble.hpp>
using namespace std;


int main() {

    int nbCluster;
    int nbPoints;
    char  animation;
    cout<<"How many cluster do you want as result ? :  ";
    cin >> nbCluster;
    cout<<"How many points do you want ? : ";
    cin>>nbPoints;
    cout<<"Finally , do you want to view the clustering phases with an animation  ? y/n";
    cin >> animation;

    RandomGenerator r1(0,100,0,100);
    RandomGenerator r3(500,700,0,100);
    RandomGenerator r4(500,700,400,800);
    RandomGenerator r2(150,300,120,400);
    vector<RandomGenerator> listeGenerator;
    listeGenerator.push_back(r1);
    listeGenerator.push_back(r2);
    listeGenerator.push_back(r3);
    listeGenerator.push_back(r4);
    Ensemble ensemble(listeGenerator,nbPoints); 
    ensemble.kMeansClustering(20,nbCluster,animation);





 
    
}
