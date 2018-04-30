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
bool matrixboard::isOnEdge(int colPos, int rowPos)
{
	if (colPos == 0 || rowPos == 0)
	{
		return true;
	}
	return false;
}
void matrixboard::validTop(vector<vector<int>> board, int boundOne, int boundTwo, int pos, int posCheck, int &flag)
{
	for (int i = boundOne; i <= boundTwo; i++)
	{
		if (i == pos) //skip current row
		{
			continue;
		}
		else if (board[i][posCheck] != 0)
		{
			flag++;
		}
	}
}
void matrixboard::validBot(vector<vector<int>> board, int boundOne, int boundTwo, int pos, int posCheck, int &flag)
{
	for (int i = boundOne; i <= boundTwo; i++)
	{
		if (i == pos) //skip current row
		{
			continue;
		}
		else if (board[posCheck][i] != 0)
		{
			flag++;
		}
	}

}
bool matrixboard::isValid(int flag, int val)
{
	if (flag != val)
	{
		return false;
	}
	return true;
}
void matrixboard::boundCheck(int &boundOne, int &boundTwo, int val, int pos)
{
	//One refers to top or left
	//Two refers to bottom or right 
	boundOne = pos - val;
	boundTwo = pos + val;
	if (boundOne <= 0)
	{
		boundOne = 0;
	}
	if (boundTwo >= pos - 1)
	{
		boundTwo = pos - 1;
	}
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
}
bool matrixboard::validBoard(vector<vector<int>> board)
{
	bool isEdge = false; //check if validation is on matrix edge 
	int row = 0, col = 0, val = 0, upRowcheck = 0, downRowcheck = 0, leftColcheck = 0, rightColcheck = 0, posindex = 0;

	while (true) //continuous validation 
	{
		val = board[row][col];
		cout << "value: " << val << endl;
		if (val > 0) //test if cell is valid 
		{
			//check if row or col is on edge
			isEdge = isOnEdge(col, row);

			//create top and bottom bounds 
			boundCheck(upRowcheck, downRowcheck, val, row);
			//cout << "up bound : " << upRowcheck << endl;
			//cout << "down bound : " << downRowcheck << endl;
			//create left and right bounds
			boundCheck(leftColcheck, rightColcheck, val, col);
			//cout << "left bound : " << leftColcheck << endl;
			//cout << "right bound : " << rightColcheck << endl;
			//check if valid top down
			validTop(board,upRowcheck, downRowcheck, row, col, posindex);
			//check if valid left right
			validBot(board,leftColcheck, rightColcheck, col, row, posindex);
			if (isValid(posindex,val))
			{
				return false;
			}
			posindex = 0;
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
/*void matrixboard::copyBoard(vector<vector<int>> &original, const vector<vector<int>> copyTemp)
{
	for (int i = 0; i < rowsize; i++)
	{
		for (int j = 0; j < colsize; j++)
		{
			original[i][j] = copyTemp[i][j];
		}
	}
}*/
void matrixboard::generateBoard()
{
	int random = 0;
	srand(time(NULL));
	vector<vector<int>> board;
	//continuous board generation till one is a valid OhNo board
	while (true)
	{
		for (int i = 0; i < rowsize; i++)
		{
			vector<int> init(4);
			for (int j = 0; j < colsize; j++)
			{
				random = rand() % (rowsize + 2); // 0 to 5
				init[j] = random;
			}
			board.push_back(init);
		}
		if (validBoard(board))
		{
			cout << "yay" << endl;
			break;
		}
	}
	
}