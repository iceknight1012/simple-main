
#include "treasure.h"
#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

int main(){
    const int CLUE_ROWS = 5;
    const int CLUE_COLS = 2;
    const int REG_ROWS = 3;
    const int REG_COLS = 2;
    double clue[CLUE_ROWS][CLUE_COLS] = {{2, 10}, {2, 5}, {8, 4}, {5, 8}, {1, 2}};
    double region[REG_ROWS][REG_COLS] = {{0, 0}, {5, -1}, {-1, -2}};

    double distance[CLUE_ROWS][3];

    cout << " FIND THE TREASURE " << endl;

    calculateDistanceMatrix(distance, clue, region, CLUE_ROWS, CLUE_COLS, REG_ROWS, REG_COLS);
    for(int i = 0; i<CLUE_ROWS;i++){
        for(int j=0;j<REG_ROWS;j++){
            cout <<fixed<<setprecision(3)<< distance[i][j]<<" ";
        }
        cout <<endl;
    }

    int clue_regions[CLUE_ROWS];
    findClueRegion(distance, clue_regions, CLUE_ROWS,REG_ROWS);
    for(int i = 0; i<CLUE_ROWS;i++){
        cout << clue_regions[i]<<" ";
   }
   cout << endl;

   findTreasure(clue_regions,region,CLUE_ROWS,REG_ROWS,REG_COLS);
}

