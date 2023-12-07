#pragma once

#include <string>


void calculateDistanceMatrix(double distance[][3], double clue[][2], double region[][2],
                             int CLUE_ROWS, int CLUE_COLS, int REG_ROWS, int REG_COLS);
void findClueRegion(double distance[][3], int clue_regions[], int DISTANCE_ROWS, int DISTANCE_COLS);

struct ft_result  {
  int region;
  int n_clues;
  double x;
  double y;
};

struct ft_result _findTreasure(int clue_regions[], double region[][2],
                               int CLUE_REGIONS_SIZE, int REG_ROWS, int REG_COLS);
void findTreasure(int clue_regions[], double region[][2], int CLUE_REGIONS_SIZE, int REG_ROWS, int REG_COLS);


