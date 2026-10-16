/* 
cd ~/Downloads
g++ projectCSCI.cpp -o projectCSCI
./projectCSCI
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct myData{ //struct to temporarily hold input values for each x,y,and block
    int row; 
    int ccol;
    string boX;
};

int main (){
    string theBlock;
    int x; // colomn
    int y; //row
    ifstream inFile; //file
    vector<myData> inputRead; //vector of struct type to read values
    int largestX = 0 ; 
    int largestY = 0;
    unsigned int i; //loop control
    unsigned int j; //loop control


    inFile.open("data_proj.txt");

    if(!inFile.is_open()){ //error 
        cout << "Error opening file" << endl;
        return -1;
    }

    while (inFile >> x >> theBlock >> y) { //create struct type and append values to the vector
        myData item;            
        item.row = y;           
        item.ccol = x;
        item.boX = theBlock;
        inputRead.push_back(item);   

        if(x > largestX){ //find the number of colomns
            largestX = x;
        }

        if(y > largestY){ //find the number of rows
            largestY = y;
        }
    }

    unsigned int rows = largestY + 1;
    unsigned int cols = largestX + 1;

    string** twoDemarray = new string*[rows]; // dynamic 2dem array
    for(i = 0; i < rows; ++i){
        twoDemarray[i] = new string[cols];
    }

    for(i = 0; i < rows; ++i){ //create spaces for each rows and colomn
        for(j = 0; j < cols; ++j){
            twoDemarray[i][j] = " ";
        }
    }

    for(i = 0; i < inputRead.size(); ++i){ // assign block values to specified coordinates
        twoDemarray[inputRead.at(i).row][inputRead.at(i).ccol] = inputRead.at(i).boX;
    }

    for(i =0; i < rows; ++i){ //print the array
        for(j=0; j< cols; ++j){
            cout << twoDemarray[i][j];
        }
        cout << endl;
    }
    for(i = 0; i < rows; ++i){ //unallocate dynamic array
        delete[] twoDemarray[i];
    }
    delete[] twoDemarray;

    return 0;
}
