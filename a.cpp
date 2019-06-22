/* C/C++ program to solve Rat in a Maze problem using 
backtracking */
#include <stdio.h> 
#include<iostream>
#include<string>
// Maze size 
// #define N 4 

bool solveMazeUtil(int** maze, int x, int y, int** sol, int N, int M); 

/* A utility function to print solution matrix sol[N][N] */
void printSolution(int** sol, int N, int M) 
{ 
	for (int i = 0; i < N; i++) { 
		for (int j = 0; j < M; j++) 
			printf(" %d ", sol[i][j]); 
		printf("\n"); 
	} 
} 

/* A utility function to check if x, y is valid index for N*N maze */
bool isSafe(int** maze, int x, int y,int N, int M) 
{ 
	// if (x, y outside maze) return false 
	if (x >= 0 && x < N && y >= 0 && y < M && maze[x][y] == 1) 
		return true; 

	return false; 
} 

/* This function solves the Maze problem using Backtracking. It mainly 
uses solveMazeUtil() to solve the problem. It returns false if no 
path is possible, otherwise return true and prints the path in the 
form of 1s. Please note that there may be more than one solutions, 
this function prints one of the feasible solutions.*/
bool solveMaze(int** maze,int N, int M) 
{ 
	int** sol = new int*[N];
	 for (int i = 0; i < N; i++)
	 {
		sol[i] = new int[M];
	 }
	 

	if (solveMazeUtil(maze, 0, 0, sol, N, M) == false) { 
		printf("Solution doesn't exist"); 
		return false; 
	} 

	printSolution(sol, N, M); 
	return true; 
} 

/* A recursive utility function to solve Maze problem */
bool solveMazeUtil(int** maze, int x, int y, int** sol,int N, int M) 
{ 
	// if (x, y is goal) return true 
	if (x == N - 1 && y == M - 1) { 
		sol[x][y] = 1; 
		return true; 
	} 

	// Check if maze[x][y] is valid 
	if (isSafe(maze, x, y, N, M) == true) { 
		// mark x, y as part of solution path 
		sol[x][y] = 1; 

		/* Move forward in x direction */
		if (solveMazeUtil(maze, x + 1, y, sol, N, M) == true) 
			return true; 

		/* If moving in x direction doesn't give solution then 
		Move down in y direction */
		if (solveMazeUtil(maze, x, y + 1, sol, N, M) == true) 
			return true; 

		/* If none of the above movements work then BACKTRACK: 
			unmark x, y as part of solution path */
		sol[x][y] = 0; 
		return false; 
	} 

	return false; 
} 

// driver program to test above function 
int main() 
{ 
	int N{};
	int M{};
	std::cin >> N >> M;
	int** maze = new int*[N];
	 for (int i = 0; i < N; i++)
	 {
		maze[i] = new int[M];
	 }

	// std::cin >> maze[0][0] >> maze[0][1] >> maze[0][2] >> maze[0][3];
	// std::cin >> maze[1][0] >> maze[1][1] >> maze[1][2] >> maze[1][3];
	// std::cin >> maze[2][0] >> maze[2][1] >> maze[2][2] >> maze[2][3];
	// std::cin >> maze[3][0] >> maze[3][1] >> maze[3][2] >> maze[3][3];

	for (int x = 0; x < N; x++)
	{	
		std::string a{};
		std::getline(std::cin,a);
		std::cout << a;
		for(size_t y = 0; y < a.size(); ++y) {
			std::cout << a[y];
			maze[x][y] = a[y];
			
		}
		
	}
	



	
	
	

	solveMaze(maze, N, M); 
	return 0; 
} 
