#include <stdio.h>

void printMaze(char **maze, const int HT, const int WD); // prints the maze

int solveMaze(char **maze, const int HT, const int WD, int y, int x); // draws a path to the exit on the maze string

int main(){
    char mazeStr[] ="  ##############"
		    "#     #     ####"
		    "# ####* ### ####"
		    "#    ###### ####"
		    "#### # #### ####"
		    "#    # #### ####"
		    "#### # #### ####"
		    "####        ####"
		    "################";
    const int HT = 9;
    const int WD = 16;
    char *maze[HT];

    for (int i=0; i<HT ; i++)		// filling the 2D char array
	maze[i]=&mazeStr[i*WD];
    
    solveMaze(maze, HT, WD, 0, 0);
    
    printMaze(maze, HT, WD);
   
    return 0;
}


int solveMaze(char **maze, const int HT, const int WD, int x, int y){
    if (x < 0 || x >= WD || y < 0 || y >= HT) return 0; //ensure the point is within boundaries
    if (maze[y][x] == '*') return 1; //check if the goal is reached
    if (maze[y][x] == '#') return 0; //blocked path  
    if (maze[y][x] == '.') return 0; //check if the path has been visited before
    
    maze[y][x] = '.'; //the path will be dotted
    
    
    if(solveMaze(maze, HT, WD, x, y-1) == 1) return 1; // the north
    if(solveMaze(maze, HT, WD, x-1, y) == 1) return 1; // the west
    if(solveMaze(maze, HT, WD, x, y+1) == 1) return 1; // the south
    if(solveMaze(maze, HT, WD, x+1, y) == 1) return 1; // the east 
    
    maze[y][x] = ' '; //dot will be deleted
    return 0;
    
}


void printMaze(char **maze, const int HT, const int WD){
    for (int i=0; i<HT ; i++){
	for(int j=0; j<WD-1; j++)
	  printf("%c",maze[i][j]);
	printf("%c\n",maze[i][WD-1]);
    }
}

