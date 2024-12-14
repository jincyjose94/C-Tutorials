/*
You are given a map (2D array) consisting of 0s and 1s. 
A storage unit has a dimension of 2x2 units. 
Storage units cannot overlap each other. 
You can place a storage unit only on 1s, not on 0s. 
How many storage units can you place on the map?
*/

#include <stdio.h>

int chargingStationCount (int** grid, int rowcount, int colCount){
    int count = 0;
    for(int i=0; i<9; i++){
        for(int j=0; j<19; j++){
            // printf("%d ", grid[i][j]);
            if(grid[i][j]==1 && grid[i][j+1]==1&&grid[i+1][j]==1 && grid[i+1][j+1]==1){
                count++;
                grid[i][j]=0;
                grid[i][j+1]=0;
                grid[i+1][j]=0;
                grid[i+1][j+1]=0;
            }
        }
    }
    return count;
}

int main(){
        int grid[10][10] = {
        {1, 0, 1, 1, 1, 0, 1, 1, 0, 1},
        {1, 1, 1, 0, 1, 1, 1, 0, 1, 0},
        {0, 1, 0, 1, 0, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 0, 0, 1, 1, 0, 0},
        {1, 0, 1, 1, 1, 1, 0, 1, 1, 1},
        {1, 1, 0, 0, 0, 1, 1, 0, 1, 0},
        {0, 1, 1, 1, 0, 1, 1, 1, 0, 0},
        {1, 1, 0, 0, 1, 1, 1, 1, 1, 1},
        {0, 0, 1, 1, 1, 0, 0, 0, 1, 0},
        {1, 1, 1, 0, 1, 0, 1, 1, 1, 1}
    };
    int* rowPointer[10];
    for(int i=0; i<10; i++){
         rowPointer[i] = grid[i];
    }
    int count = chargingStationCount(rowPointer, 10, 10);
    printf("count = %d\n",count);

    return 0;
}