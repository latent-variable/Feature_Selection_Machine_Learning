
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "Feature_tree.h"

using namespace std; 


//////////Functions//////////////////////////////
int data_handler(vector<vector<float>> & data);

//**************MAIN******************************************************
int main() {
    
    int numfeat;
    char yn;
    int input;
    
    cout<< "Welcome to Lino Valdovinos Feature Selection Algorithm."<<endl;
    do{
        vector<vector<float>> data(100);
    
        do{
            numfeat = data_handler(data);
        }while(numfeat == -1);
        
        Feature_tree* one = new Feature_tree(data,numfeat);
        
        cout<<" \n 1)	Forward Selection\n 2)	Backward Elimination \n 3)	Lino’s Special Algorithm\n";
        
        cout<< "Type the number of the algorithm that your want to use: ";
        cin >> input; 
        switch(input){
            case(1):
                one->Forward_Selection();
                one->results();
                break;
            case(2):
                one->Backward_Elimination();
                one->results();
                break;
            case(3):
                one->GetRealFeatures();
                break;
        }        
        cout<< "Try more Data?(y/n): ";
        cin >> yn;
    }while(yn == 'y');
    
    return 0;
    
}




//////////////////////////////////////////////////////////////////////
// All the IO stuff 
// takes 100 objects with any number of features and stores in a 
// vector of vectors  features range from 0 - 64
// RETURNS the number of features 
int data_handler(vector<vector<float>> & data){
    ifstream testfile;
    string file;
    string line;
    int count;
    int x = 1;
    int j = 0;
    
    cout<< "Enter the name of the file to test: ";
    cin >> file;
    testfile.open (file);
    
    cout <<endl; 
    
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
    else{
        cout << "Unable to open file *~* \n";
        return(-1);
    }
    testfile.close();
    
    return(count-1);
}