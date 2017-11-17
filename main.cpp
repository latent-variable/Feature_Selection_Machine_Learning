
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "Feature_tree.h"

using namespace std; 


//////////Functions//////////////////////////////
int data_handler(vector<vector<float>> & data);


int main() {
    
    vector<vector<float>> data(100);

    int numfeat = data_handler(data);
    Feature_tree* one = new Feature_tree(data,numfeat); 
    one->Forward_Selection();
    return 0;
    
}




//////////////////////////////////////////////////////////////////////
// All the IO stuff 
// takes 100 objects with any number of features and stores in a 
// vector of vectors  features range from 0 - 64
// RETURNS the number of features 
int data_handler(vector<vector<float>> & data){
    ifstream testfile;
    string line;
    int count;
    int x = 1;
    int j = 0;
    
    testfile.open ("small_test_data.txt");
    
    for ( int i = 0 ; i < 100 ; i++ )
        data[i].resize(66);
        
    if(testfile.is_open()){
        while (getline(testfile, line))
        {   
            count = 0;
            istringstream iss(line);
             //cout << x <<":";
            for (unsigned i = 0 ; i <100; i++){
                if(!(iss >> data[j][i])) break;
                count++;
                //cout << data[j][i]<<" ";
            }
            j++;
            x++;
            //cout<<endl;
        }
        
    }
    else cout << "Unable to open file";
    testfile.close();
    
    return(count);
}