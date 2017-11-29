#ifndef FEATURE_TREE_H
#define FEATURE_TREE_H
#include <vector>


using namespace std;

class Feature_tree{
public:
    Feature_tree();
    Feature_tree( vector<vector<float>> d, int f);
    
    void print();
    
    //Validationg the data 
    double leave_one_out_cross_validation(); 
    
    //tree traversals 
    void Forward_Selection();
    void Backward_Elimination();
    void Lino_Selection();
    
    void GetRealFeatures();
    
    //////////two flavors of this soon////
    int bf_nearest_neighbor(unsigned);
    ////////Distance for any dimentional points////////
    float N_dimensinal_distance(vector<float> point1 ,vector<float> point2);
    
    //return the subset of best features
    void results();
    
    
private:
     int NumFeature;
     double TopAccuracy;
     vector<vector<float>> Data;
     vector<int> ListFeatures;
     vector<int> BestFeatures;
    
    
};

#endif