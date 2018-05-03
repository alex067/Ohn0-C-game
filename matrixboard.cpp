#include "matrixboard.h"
matrixboard::matrixboard()
{
	generateBoard();
	cout << "Board generated";
	//printBoard();
}
int matrixboard::getRowSize()
{
	return rowsize;
}
int matrixboard::getColSize()
{
	return colsize;
}
void matrixboard::printBoard(const vector<vector<int>> board)
{
	for (int i = 0; i < rowsize; i++)
	{
		cout << "|";
		for (int j = 0; j < colsize; j++)
		{
			cout << board[i][j] << "|";
		}
		cout << endl;
	}
	cout << endl;
}
bool matrixboard::validPos(const vector<vector<int>> board, int currRow, int currCol, int val)
{
	int validFlag = 0;
	//check cell row visiblity 
	for (int row = 0; row < rowsize; row++)
	{
		if (row == currRow)
		{
			continue;
		}
		else if (board[row][currCol] != 0)
		{
			validFlag++;
		}
	}
	//check cell col visiblity 
	for (int col = 0; col < colsize; col++)
	{
		if (col == currCol)
		{
			continue;
		}
		else if (board[currRow][col] != 0)
		{
			validFlag++;
		}
	}
	if (isValid(validFlag, val))
	{
		return true;
	}
	return false;
}
bool matrixboard::isValid(int flag, int val)
{
	if (flag == val)
	{
		return true;
	}
	return false;
}
bool matrixboard::validBoard(vector<vector<int>> board)
{
	bool isEdge = false; //check if validation is on matrix edge 
	int row = 0, col = 0, val = 0, upRowcheck = 0, downRowcheck = 0, leftColcheck = 0, rightColcheck = 0, posindex = 0;

	while (true) //continuous validation 
	{
		val = board[row][col];
		if (val > 0) //test if cell is valid 
		{
			if (!validPos(board, row, col, val))
			{
				return false;
			}
		}
		col++;
		if (col == colsize && row == rowsize - 1)
		{
			return true; //reached end of validation
		}
		else if (col == colsize) //reached the edge 
		{
			row++;
			col = 0;
		}
	}
}
//
void matrixboard::generateBoard()
{
	int random = 0;
	//used to generate random index of row and col
	int randRow = 0;
	int randCol = 0;
	//counters for random generation
	int randomFlag = 0;
	//array to keep track of which index was already used 
	bool capRow[4] = { false }; 
	bool capCol[4] = { false }; 
	//flag for valid board
	bool valid = true;
	

	vector<vector<int>> board(4, vector<int>(4, 0));
	static vector<int> init(4);
	printBoard(board);

	//continuous board generation till one is a valid OhNo board
	while (valid)
	{
		srand(time(NULL));
		//generate a random board 
		while (randomFlag != 15)
		{

			randRow = rand() % 4;
			randCol = rand() % 4;
			srand(time(NULL));
			//set index to true, as used index 
			if (capRow[randRow] != true && capCol[randCol] != true)
			{
				capRow[randRow] = true;
				capCol[randCol] = true;
				//generate random number between 0 - 4 
				random = rand() % (rowsize + 1);
				board[randRow][randCol] = random;
				randomFlag++;
			}
		}
		printBoard(board);
		randomFlag = 0;
		valid = false;
		if (validBoard(board))
		{
			valid = false;
			cout << "yay";
		}
	}

	

	
}