#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "Feature_tree.h"
#include <stdlib.h>     
#include <time.h>

using namespace std;

Feature_tree::Feature_tree(vector<vector<float>> d , int f){
    NumFeature = f;
    Data = d;
}
void Feature_tree::print(){
    for(int i = 0; i <100; i++){
        cout<<i+1<<": ";
        for(int j = 0; j < NumFeature; j++){
            cout << Data[i][j]<< " ";
        }
        cout<<endl;
    }
}
//**************************************************************
//functions implementation
void Feature_tree::Forward_Selection(){
    int bestFeat= 1;
    bool skip = false;
    srand (time(NULL));
    
    for(int i = 0; i < NumFeature ; i++){
        
        cout<<"On level "<< i<<" of the search tree"<<endl;
       
        for(int j = 1; j < NumFeature; j++){
            
            for(unsigned z = 0; z < ListFeatures.size(); z++){
                if( j == ListFeatures[z]){
                    skip = true;
                    break;
                }
            }
            if(skip == true){
                skip = false;
                continue;
                
            }
            
            //bestFeat++;
            cout << "   Considering Feature: "<< j<<endl;
            //leave_one_out_cross_validation
        }
        
        cout << "Best Feature(s): "<< bestFeat <<endl;
        ListFeatures.push_back(bestFeat);
        bestFeat++;
    }
    
    
}

void Feature_tree::Backward_Elimination(){
    
    
    
}
void Feature_tree::Lino_Selection(){
    
    
    
}