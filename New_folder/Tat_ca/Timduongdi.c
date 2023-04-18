#include <stdio.h>
#define SIZE_1 20
#define SIZE_2 17
//the maze problem
//"0" is able to move
//"1" is wall, can't go through
int maze[SIZE_1][SIZE_2] = {
  	{0,1,0,1,1,1,1,0,0,0,1,1,1,0,0,0,0},//1
  	{0,0,0,0,0,0,0,1,1,0,1,0,0,1,1,1,0},//2
  	{1,0,1,0,1,1,1,1,0,0,1,0,1,1,0,0,1},//3
  	{0,0,1,0,0,1,1,1,1,0,0,1,0,0,0,1,1},//4
  	{1,0,0,0,0,1,1,1,1,0,0,0,0,1,0,1,0},//5
  	{1,1,1,0,0,0,1,1,0,0,0,1,0,1,1,0,0},//6
  	{1,1,1,0,0,1,1,0,0,1,0,0,0,1,1,0,0},//7
  	{0,0,1,0,0,1,1,1,1,0,0,1,0,0,0,1,1},//8
 	{0,1,0,1,0,1,0,0,0,0,1,1,1,0,0,0,0},//9
    {0,0,1,0,0,1,0,1,1,0,0,1,0,0,0,1,1},//10
    {0,0,1,0,0,1,0,1,1,0,0,1,0,0,0,1,1},//11
    {1,1,1,0,0,1,0,1,0,0,0,1,0,1,1,0,0},//12
    {0,0,0,0,1,0,0,0,1,0,1,0,0,1,1,1,0},//13
    {1,1,1,0,0,1,1,0,1,1,0,0,0,1,1,0,0},//14
    {0,0,1,0,0,1,1,0,1,0,0,1,0,0,0,1,1},//15
    {1,1,1,0,0,1,1,0,1,1,0,0,0,1,1,0,0},//16
    {1,1,0,0,1,1,0,0,0,1,0,1,0,1,1,1,0},//17
    {0,0,0,0,0,0,0,1,0,1,0,0,0,1,1,1,0},//18
    {1,1,0,0,1,1,0,0,0,1,0,0,0,1,1,1,0},//19
    {1,1,1,0,1,1,1,1,0,0,1,0,0,0,0,0,0},//20
};
//matrix to store the solution
int solution[SIZE_1][SIZE_2];
//function to print the solution matrix
void printsolution() {
   int i,j;
   for(i=0;i<SIZE_1;i++) {
      for(j=0;j<SIZE_2;j++) {
         printf("%d ",solution[i][j]);
      }
      printf("\n");
   }
}
//function to solve the maze
//using backtracking`
int solvemaze(int r, int c) {
   //if destination is reached, maze is solved
   //destination is the last cell(maze[SIZE-1][SIZE-1])
   if((r==SIZE_1-1) && (c==SIZE_2-1)) {
      solution[r][c] = 1;
      return 1;
   }
   //checking if we can visit in this cell or not
   //the indices of the cell must be in (0,SIZE-1)
   //and solution[r][c] == 0 is making sure that the cell is not already visited
   //maze[r][c] == 0 is making sure that the cell is not blocked
   if(r>=0 && c>=0 && r<SIZE_1 && c<SIZE_2 && solution[r][c] == 0 && maze[r][c] == 0){
      //if safe to visit then visit the cell
      solution[r][c] = 1;
      //going down
      if(solvemaze(r+1, c))
         return 1;
      //going right
      if(solvemaze(r, c+1))
         return 1;
      //going up
      if(solvemaze(r-1, c))
         return 1;
      //going left
      if(solvemaze(r, c-1))
         return 1;
      //backtracking
      solution[r][c] = 0;
      return 0;
   }
   return 0;
}
int main() {
   //making all elements of the solution matrix 0
   int i,j;
   for(i=0; i<SIZE_1; i++) {
      for(j=0; j<SIZE_2; j++) {
         solution[i][j] = 0;
      }
   }
   if (solvemaze(0,0))
      printsolution();
   else
      printf("No solution");
   return 0;
}
