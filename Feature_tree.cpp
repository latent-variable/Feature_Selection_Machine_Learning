#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include "Feature_tree.h"


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
    double current_accuracy; 
    double best_accuracy; 
    int bestFeat= 1;
    bool skip = false;
    int count = 0;
    char s = 's';
    
    for(int i = 0; i < NumFeature ; i++){
        
        ListFeatures.push_back(0);
        current_accuracy = 0; 
        best_accuracy = 0; 
        cout<<"\nOn level "<< i<<" of the search tree"<<endl;
        
        for(int j = 1; j < NumFeature+1; j++){
           
            
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
            ListFeatures[count] = j;
            cout << "   Using feature(s) {";
             for(unsigned y = 0; y < ListFeatures.size(); y++){
                if(y != ListFeatures.size()-1)
                    cout<< ListFeatures[y]<<",";
                else
                    cout<<ListFeatures[y];
            }
            cout<<"}";
            
            current_accuracy = leave_one_out_cross_validation();
            
            cout<<" has accuracy of " << current_accuracy <<"%" << endl;
            if( current_accuracy > best_accuracy){
                best_accuracy = current_accuracy;
                bestFeat = j;
            }
            
        }
        ListFeatures[count] = bestFeat;
        cout << "Best Feature(s): {";
        for(unsigned n = 0; n < ListFeatures.size();n++){
            if(n != ListFeatures.size()-1)
                cout<< ListFeatures[n] <<",";
            else
                cout<<ListFeatures[n];
        }
        cout <<"} with "<< best_accuracy<<"% accuracy"<<endl;
        
        if( best_accuracy > TopAccuracy){
                TopAccuracy = best_accuracy;
                BestFeatures = ListFeatures;
        } 
        
        count++;
        
        if (s == 's'){
            cout <<"Step: ";
            cin >> s; 
        }
        
    }
}

void Feature_tree::Backward_Elimination(){
    
    
    
}
void Feature_tree::Lino_Selection(){
    
    
    
}
double Feature_tree::leave_one_out_cross_validation(){
    double total_accuracy = 0 ;
    int temp_class; 
    for(unsigned i = 0; i < Data.size(); i ++ ){
        temp_class =  bf_nearest_neighbor(i);
        if(temp_class == Data[i][0]) 
            total_accuracy++;
    }
    return total_accuracy ;
}

int Feature_tree::bf_nearest_neighbor(unsigned leave_out){
    string s;
    float inf = 99999999999999;
    float temp;
    vector<float> a;
    vector<float> b;
    int classified = 0;
   
    for(unsigned x = 0; x < ListFeatures.size();x++){
            a.push_back(Data[leave_out][ListFeatures[x]]);
    }
    for(unsigned j = 0; j < Data.size();j++){
        
        if(j == leave_out) continue; 
    
        for(unsigned y = 0; y < ListFeatures.size();y++){
            b.push_back(Data[j][ListFeatures[y]]);
            
        }
        temp = N_dimensinal_distance(a,b);
        b.clear();
        if(temp < inf){
            inf = temp;
            classified = Data[j][0];
        }
            
    }
    return classified;
}
float Feature_tree::N_dimensinal_distance(vector<float> point1 ,vector<float> point2){
    float distance = 0;
    for(unsigned i = 0; i < point1.size(); i++){
        distance = distance + pow(point1[i] -point2[i],2);
    }
    
    return(sqrt(distance));
    
}
 void Feature_tree::GetRealFeatures(){
    
     vector<int> all_best_accuracy; 
     vector<vector<int>> all_best_feat;
     vector<vector<float>> temp_data = Data; 
     
     for(unsigned i = 0; i < 5; i++){
         srand(time(NULL));
         Data = temp_data;
         for(unsigned j = 0; j < 5; j++){
             int c = rand()% 100;
             Data.erase(Data.begin()+ (c));
         }
         Forward_Selection(); 
         all_best_feat.push_back(BestFeatures); 
         all_best_accuracy.push_back(TopAccuracy);
         ListFeatures.clear();
         TopAccuracy = 0;
     }
     
    cout<<"\nFinished!\n";
    for(unsigned n = 0; n <5; n++){
        cout<<"The best feature(s) are {";
        for(unsigned m = 0; m < all_best_feat[n].size();m++){
                if(m != all_best_feat[n].size()-1)
                    cout<< all_best_feat[n][m] <<",";
                else
                    cout<<all_best_feat[n][m];
        }
        cout<<"} with an accuracy of "<< all_best_accuracy[n]<<"%."<<endl;
    }
}


void Feature_tree::results()
{
    cout<<"\nFinished!\n";
    
    cout<<"The best feature(s) are {";
    for(unsigned n = 0; n < BestFeatures.size();n++){
            if(n != BestFeatures.size()-1)
                cout<< BestFeatures[n] <<",";
            else
                cout<<BestFeatures[n];
    }
    cout<<"} with an accuracy of "<< TopAccuracy<<"%."<<endl;
    
}