#include<bits/stdc++.h>
using namespace std;


// bool RatinMaze(char  maze[][1001], int soln[][1001], int  x, int  y, int rows, int cols)
// {
// 	static int counter = 0;

// 	if (x == rows - 1 && y == cols - 1)
// 	{
// 		soln[x][y] = 1;
// 		//Print the path
		
// 		if(!counter)
// 		{
// 			for (int i = 0; i < rows; i++)
// 			{
// 				for (int j = 0; j < cols; j++)
// 				{
// 					cout << soln[i][j] << " ";
// 				}
// 				cout << endl;
// 			}

// 			cout << endl;
			
// 		}

// 		counter ++;
// 		return true;
// 	}

// 	if (x > rows || y > cols || maze[x][y] == 'X' )
// 	{
// 		soln[x][y] = 0;
// 		return false;
// 	}

// 	//Assume that we are on the correct position

// 	soln[x][y] = 1;

// 	bool rightsuccess = RatinMaze(maze, soln, x, y + 1, rows, cols);
// 	bool leftsuccess = RatinMaze(maze, soln, x + 1, y, rows, cols);

// 	//Backtracking


// 	if (rightsuccess || leftsuccess)
// 	{
// 		return true;
// 	}

// 	else soln[x][y] = 0;
	
// 	return false;

// }


bool rat_in_maze(char  maze[][1001], int soln[][1001], int  x, int  y, int rows, int cols)
{
	if (x == rows - 1 && y == cols - 1)
	{
		soln[x][y] = 1;
		return true;
	}

	if (x >= rows || y >= cols ||  maze[x][y] == 'X')
		return false;

	soln[x][y] = 1;

	if (rat_in_maze(maze, soln, x, y + 1, rows, cols) || rat_in_maze(maze, soln, x + 1, y, rows, cols))
		return true;

	soln[x][y] = 0;

	return false;
}

int main()
{

	int rows, cols;

	cin >> rows >> cols;

	char maze[1001][1001];
	int soln[1001][1001] ;


	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			cin >> maze[i][j];



	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			soln[i][j] = 0;


	// bool ans = RatinMaze( maze, soln, 0, 0, rows, cols);

	// if(!ans) cout << "-1" << endl;



	bool ans = rat_in_maze( maze, soln, 0, 0, rows, cols);

	if (ans)
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
				cout << soln[i][j] << " ";
			cout << endl;
		}
	}
	else cout << -1 << endl;

	return 0;
}
