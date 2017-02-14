/* Michael Tee
Assignment 1*/


#include <ctime>
#include <iostream>

using namespace std;


void initialiseGrid(int& gridHeight, int& gridWidth)
{
	// requests user to input the dimensions of the grid
	cout << "please enter the height and width of the grid you wish to use";
	cin >> gridHeight >> gridWidth;

}


void treasurePosition(int& gridHeight, int& gridWidth, int& treasureX, int& treasureY, char grid[64][64])
{
	// sets a random x and y position for the treasure
	srand(time(0));
	//mod calculation to ensure that the random position is not outside the boundries of the set grid
	treasureX = (rand() % gridWidth) + 1;
	treasureY = (rand() % gridHeight) + 1;
}


void outputGrid(int& gridHeight, int& gridWidth, int& treasureX, int& treasureY, char grid[64][64])
{
	//row is for the number of positions across
	//col is for the number of positions down
	for (int row = 1; row <= gridWidth; row++)
	{
		// nested loop for iterating columns
		for (int col = 1; col <= gridHeight; col++)
		{
			// if statement to check that "o" or "!" aren't drawn
			if (grid[row][col] != 'o' && grid[row][col] != '!')
			{
				grid[row][col] = '*';
			}
			//outputs the grid
			cout << grid[row][col];
		}
		//starts new row when row has been output
		cout << "\n";

	}
}

void findTreasure(int& gridHeight, int& gridWidth, int& treasureX, int& treasureY, int& gridRow, int& gridCol, char grid[64][64], bool win)
{
	//while loop to exit if the player gets a correct guess
	while (win == false)
	{
		cout << "please enter the column and row you wish to attempt";
		cin >> gridCol >> gridRow;

		//if the guess is correct
		if (gridCol == (treasureX) && gridRow == (treasureY))
		{
			//informs player of correctly guessed position
			cout << "Congratulations you win! the treasure was in: " << (treasureX) << ", " << (treasureY) << ") \n";
			//draws a "!"  in the correctly guessed position
			grid[gridCol][gridRow] = '!';
			// sets boolean value to true to exit while loop
			win = true;
		}
		else
		{
			//requests that the user inputs another guess
			cout << "Incorrect guess, please try again. \n";
			//outputs an "o" where the incorrect guess was made
			grid[gridCol][gridRow] = 'o';
			// sets boolean value to false, to make sure while loop continues
			win = false;
		}
		// redraws grid
		outputGrid(gridHeight, gridWidth, treasureX, treasureY, grid);
	}

}


int main()
{
	// variable declarations
	char grid[64][64];
	int gridWidth = 0, gridHeight = 0, gridRow = 0, gridCol = 0, treasureX, treasureY;
	bool win = false;
	// call for grid size function
	initialiseGrid(gridHeight, gridWidth);
	// initialises treasure position
	treasurePosition(gridHeight, gridWidth, treasureX, treasureY, grid);
	//output grid to screen
	outputGrid(gridHeight, gridWidth, treasureX, treasureY, grid);
	//runs the function allowing the user to attempt to find the treasure
	findTreasure(gridHeight, gridWidth, treasureX, treasureY, gridRow, gridCol, grid, win);
	return(0);
}