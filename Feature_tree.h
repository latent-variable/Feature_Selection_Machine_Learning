#ifndef FEATURE_TREE_H
#define FEATURE_TREE_H
#include <queue>
#include <vector>

using namespace std;

class Feature_tree{
public:
    Feature_tree();
    Feature_tree( vector<vector<float>> d, int f);
    
    void print();
    
    void Forward_Selection();
    void Backward_Elimination();
    void Lino_Selection();
    
    
private:
     double accuracy;
     int NumFeature;
     vector<vector<float>> Data;
     vector<int> ListFeatures;
    
    
};

#endif