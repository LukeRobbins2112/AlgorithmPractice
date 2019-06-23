#include <vector>
#include <iostream>

using namespace std;


void printGrid(vector<vector<int>> & grid){
    
    int n = grid.size();
    
    for (int i = 0; i < n; i++){
       for (int j = 0; j < n; j++){
           std::cout << grid[i][j] << " ";
       }
       std::cout << std::endl;
    }
    
}

vector<vector<int> > prettyPrint(int A) {
    
    int n = 1 + (A-1) * 2;
    pair<int, int> origin = {n/2, n/2};
    vector<vector<int>> res(n, vector<int>(n));
    res[n/2][n/2] = 1;    
    
    int sideLength = 2;
    int curVal = 2;
    
    int curX = origin.first; curX++;
    int curY = origin.second; curY--;
        
    while(sideLength <= n){
        
        for (int i = 0; i < sideLength; i++){
            res[curX][curY] = curVal;
            curY++;
        }
        
        for (int i = 0; i < sideLength; i++){
            res[curX][curY] = curVal;
            curX--;
        }
        
        for (int i = 0; i < sideLength; i++){
            res[curX][curY] = curVal;
            curY--;
        }
        for (int i = 0; i < sideLength; i++){
            res[curX][curY] = curVal;
            curX++;
        }
        
        curX++;
        curY--;
        
        sideLength+=2;
        curVal++;
    }
    
    return res;
    
}

int main(){

    vector<vector<int>> result = prettyPrint(3);

    printGrid(result);

    return 0;

}