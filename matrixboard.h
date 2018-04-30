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
public: 
	matrixboard();
	//getters
	int getRowSize();
	int getColSize();
	void boundCheck(int &boundOne, int &boundTwo, int val, int pos);
	void printBoard(const vector<vector<int>> board);
	//contiuously generates a random board using random numbers 
	void generateBoard();
	//validates whether or not given board is valid solution
	bool validBoard(vector<vector<int>> board);
	void validTop(vector<vector<int>> board, int boundOne, int boundTwo, int pos, int posCheck, int &flag);
	void validBot(vector<vector<int>> board, int boundOne, int boundTwo, int pos, int posCheck, int &flag);
	bool isOnEdge(int colPos, int rowPos);
	bool isValid(int flag, int val);
	//shallow copy
	void copyBoard( vector<vector<int>> &original, const vector<vector<int>> copyTemp);


};



#endif