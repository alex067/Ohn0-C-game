#ifndef MATRIXBOARD_H
#define MATRIXBOARD_H
#include <vector>
#include <iostream>
#include <time.h> 
using std::vector;
using std::cout;
using std::endl;

class matrixboard
{
private:
	vector <vector<int>> mainBoard;
	//board which holds temporary values until a valid board is found 
	//vector <vector<int>> board;
	static const int rowsize = 4;
	static const int colsize = 4;
	bool validFlag;
public: 
	matrixboard();
	//getters
	int getRowSize();
	int getColSize();
	void printBoard(const vector<vector<int>> board);
	//contiuously generates a random board using random numbers 
	void generateBoard();
	//validates whether or not given board is valid solution
	bool validBoard(vector<vector<int>> board);
	//validates if visibility is valid for height 
	bool isValid(int flag, int val);
	//returns true or false depending if the current board is a valid solution
	bool validPos(const vector<vector<int>> board, int currRow, int currCol, int val);

};



#endif