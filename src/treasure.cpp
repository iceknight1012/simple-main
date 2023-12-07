#include "treasure.h"
#include <iomanip>
#include <iostream>
#include <cmath>

using namespace std;


void calculateDistanceMatrix(double distance[][3], double clue[][2], double region[][2],
                             int CLUE_ROWS, int CLUE_COLS, int REG_ROWS, int REG_COLS){

  for(int i = 0; i<CLUE_ROWS;i++){
    for(int j=0;j<REG_ROWS;j++){
      double rx = region[j][0];
      double ry = region[j][1];
      double cx = clue[i][0];
      double cy = clue[i][1];
      distance[i][j]=sqrt(pow((rx-cx),2)+pow((ry-cy),2));
    }
  }
}
void findClueRegion(double distance[][3], int clue_regions[], int DISTANCE_ROWS, int DISTANCE_COLS){
  for(int i = 0;i<DISTANCE_ROWS;i++){
    int min_col = 0;
    double min_val = distance[i][0];
    for(int j = 0; j<DISTANCE_COLS; j++){
      double d = distance[i][j];
      if(distance[i][j]<min_val){
        min_val = d;
        min_col = j;
      }

    }
    clue_regions[i]=min_col+1;

  }

}

struct ft_result _findTreasure(int clue_regions[], double region[][2],
                               int CLUE_REGIONS_SIZE, int REG_ROWS, int REG_COLS){


  int region_count[REG_ROWS];

  // Initialize region count to 0
  for(int i = 0; i<REG_ROWS;i++){
    region_count[i] = 0;
  }

  // Count the number of clues in each region
  for(int i = 0; i<CLUE_REGIONS_SIZE;i++){
    region_count[clue_regions[i]-1]+=1;
  }

  int min_reg_count=region_count[0];
  int min_reg = 0;

  // Find the region with the least number of clues
  for(int i=0;i<REG_ROWS;i++){
    if(region_count[i]<min_reg_count){
      min_reg_count = region_count[i];
      min_reg = i;
    }
  }

  return {min_reg+1, min_reg_count, region[min_reg][0], region[min_reg][1]};

}

void findTreasure(int clue_regions[], double region[][2], int CLUE_REGIONS_SIZE, int REG_ROWS, int REG_COLS)
{

  struct ft_result r = _findTreasure(clue_regions, region, CLUE_REGIONS_SIZE,
                                     REG_ROWS, REG_COLS);

  cout << "Region " << r.region
       << " had the least number of clues : " << r.n_clues << endl;
  cout << "Treasure must be buried in the coordinates ( " << fixed
       << setprecision(2) << r.x << ", " << r.y << " )" << endl;
}

