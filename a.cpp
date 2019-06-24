/* C/C++ program to solve Rat in a Maze problem using 
backtracking */
#include <stdio.h> 
#include<iostream>
#include<string>
#include<vector>
// Maze size 


// bool solveMazeUtil(int** maze, int x, int y, int** sol, int N, int M); 

// /* A utility function to print solution matrix sol[N][N] */
// void printSolution(int** sol, int N, int M) 
// { 
// 	for (int i = 0; i < N; i++) { 
// 		for (int j = 0; j < M; j++){
// 			if (sol[i][j] == 1){
// 				std::cout << i << " ss " << j << std::endl;
// 			}
// 		} 
// 		printf("\n"); 
// 	} 
// } 

// /* A utility function to check if x, y is valid index for N*N maze */
// bool isSafe(int** maze, int x, int y,int N, int M) 
// { 
// 	// if (x, y outside maze) return false
// 	if (x >= 0 && x < N && y >= 0 && y < M && maze[x][y] == 1) 
// 		return true; 

// 	return false; 
// } 

// /* This function solves the Maze problem using Backtracking. It mainly 
// uses solveMazeUtil() to solve the problem. It returns false if no 
// path is possible, otherwise return true and prints the path in the 
// form of 1s. Please note that there may be more than one solutions, 
// this function prints one of the feasible solutions.*/
// bool solveMaze(int** maze,int N, int M) 
// { 
// 	int** sol = new int*[N];
// 	 for (int i = 0; i < N; i++)
// 	 {
// 		sol[i] = new int[M];
// 	 }
	 

// 	if (solveMazeUtil(maze, 0, 0, sol, N, M) == false) { 
// 		printf("That's a dead end!"); 
// 		return false; 
// 	} 

// 	printSolution(sol, N, M); 
// 	return true; 
// } 

// /* A recursive utility function to solve Maze problem */
// bool solveMazeUtil(int** maze, int x, int y, int** sol,int N, int M) 
// { 
// 	// if (x, y is goal) return true 
// 	if (x == N - 1 && y == M - 1) { 
// 		sol[x][y] = 1; 
// 		return true; 
// 	} 

// 	// Check if maze[x][y] is valid 
// 	if (isSafe(maze, x, y, N, M) == true) { 
// 		// mark x, y as part of solution path 
// 		sol[x][y] = 1; 

// 		/* Move forward in x direction */
// 		// if (solveMazeUtil(maze, x + 1, y, sol, N, M) == true) 
// 		// 	return true; 

// 		// /* If moving in x direction doesn't give solution then 
// 		// Move down in y direction */
// 		// if (solveMazeUtil(maze, x, y + 1, sol, N, M) == true) 
// 		// 	return true;

// 		// if (solveMazeUtil(maze, x - 1, y, sol, N, M) == true) 
// 		// 	return true; 

// 		// // if (solveMazeUtil(maze, x, y - 1, sol, N, M) == true) 
// 		// // 	return true;

// 		if (solveMazeUtil(maze, x+1, y + 1, sol, N, M) == true)
// 			return true;

// 		// if (solveMazeUtil(maze, x-1, y - 1, sol, N, M) == true) 
// 		// 	return true;

// 		// if (solveMazeUtil(maze, x+1, y - 1, sol, N, M) == true) 
// 		// 	return true;

// 		// if (solveMazeUtil(maze, x - 1, y + 1, sol, N, M) == true) 
// 		// 	return true;

		
// 		if (solveMazeUtil(maze, x + 1, y, sol, N, M) == true) 
// 			return true; 

// 		/* If moving in x direction doesn't give solution then 
// 		Move down in y direction */
// 		if (solveMazeUtil(maze, x, y + 1, sol, N, M) == true) 
// 			return true;

// 		/* If none of the above movements work then BACKTRACK: 
// 			unmark x, y as part of solution path */
// 		sol[x][y] = 0; 
// 		return false; 
// 	} 

// 	return false; 
// } 

// // driver program to test above function 
// int main() 
// { 
// 	int N{};
// 	int M{};
// 	std::cin >> N >> M;
// 	int** maze = new int*[N];
// 	 for (int i = 0; i < N; i++)
// 	 {
// 		maze[i] = new int[M];
// 	 }


// 	for (int x = 0; x < N; x++)
// 	{	
// 		std::string a{};
// 		std::cin >> a;
// 		for(size_t y = 0; y < a.size(); ++y) {
// 			std::string aa{a[y]};
// 			maze[x][y] = 1 - std::stoi(aa);
			
// 		}
		
// 	}
// 	solveMaze(maze, N, M); 
// 	return 0; 
// } 










// CPP program to solve Rat in a maze 
// problem with backtracking using stack 

#include <cstring> 
#include <iostream> 
#include <stack> 

using namespace std; 

// #define N 4 
// #define M 5 

class node { 
public: 
	int x, y; 
	int dir; 

	node(int i, int j) 
	{ 
		x = i; 
		y = j; 
		
		// Initially direction 
		// set to 0 
		dir = 0; 
	} 
}; 

// maze of n*m matrix 
// int n = N, m = M;

// Coordinates of food 
int fx, fy;
// bool visited[3][5];

bool isReachable(int** maze, int N,int M,bool** visited) 
{ 
	int n = N, m = M;
	// Initially starting at (0, 0). 
	int i = 0, j = 0; 
	
	stack<node> s; 
	
	node temp(i, j); 
	
	s.push(temp); 

	while (!s.empty()) { 

		// Pop the top node and move to the 
		// left, right, top, down or retract 
		// back according the value of node's 
		// dir variable. 
		temp = s.top(); 
		int d = temp.dir; 
		i = temp.x, j = temp.y; 

		// Increment the direction and 
		// push the node in the stack again. 
		temp.dir++; 
		s.pop(); 
		s.push(temp); 

		// If we reach the Food coordinates 
		// return true 
		if (i == fx and j == fy) { 
			return true; 
		} 

		// Checking the Up direction. 
		if (d == 0) { 
			if (i - 1 >= 0 and maze[i - 1][j] and 
									visited[i - 1][j]) { 
				node temp1(i - 1, j); 
				visited[i - 1][j] = false; 
				s.push(temp1); 
			} 
		} 

		// Checking the left direction 
		else if (d == 1) { 
			if (j - 1 >= 0 and maze[i][j - 1] and 
									visited[i][j - 1]) { 
				node temp1(i, j - 1); 
				visited[i][j - 1] = false; 
				s.push(temp1); 
			} 
		} 

		// Checking the down direction 
		else if (d == 2) { 
			if (i + 1 < n and maze[i + 1][j] and 
									visited[i + 1][j]) { 
				node temp1(i + 1, j); 
				visited[i + 1][j] = false; 
				s.push(temp1); 
			} 
		} 
		// Checking the right direction 
		else if (d == 3) { 
			if (j + 1 < m and maze[i][j + 1] and 
									visited[i][j + 1]) { 
				node temp1(i, j + 1); 
				visited[i][j + 1] = false; 
				s.push(temp1); 
			} 
		} 

		// If none of the direction can take 
		// the rat to the Food, retract back 
		// to the path where the rat came from. 
		else { 
			visited[temp.x][temp.y] = true; 
			s.pop(); 
		} 
	} 

	// If the stack is empty and 
	// no path is found return false. 
	return false; 
} 

// Driver code 
int main() 
{ 
	// Initially setting the visited 
	// array to true (unvisited) 
	
	int N=3;

	int M=5;
	// bool visited[N][M];
	bool** visited = new bool*[N];
	for (int i = 0; i < N; i++)
	{
		visited[i] = new bool[M];
	}
	// memset(visited, true, sizeof(visited));
	// Maze matrix 
	int** maze = new int*[N];
	for (int i = 0; i < N; i++)
	{
		maze[i] = new int[M];
	}


	for (int x = 0; x < N; x++)
	{	
		std::string a{};
		std::cin >> a;
		for(size_t y = 0; y < a.size(); ++y) 
		{
			std::string aa{a[y]};
			maze[x][y] = 1 - std::stoi(aa);
			
		}
		
	}

	// Food coordinates 
	fx = N-1; 
	fy = M-1; 

	if (isReachable(maze,N,M,visited)) { 
		cout << "Path Found!" << '\n'; 
	} 
	else
		cout << "No Path Found!" << '\n'; 
		
	return 0; 
} 
