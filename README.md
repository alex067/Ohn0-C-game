# Ohn0-C-game
My C++ implemention of Martin Kool's Oh n0 game. 

My implemention of the Oh n0 game written in C++. 

The game can be played at: http://0hn0.com/
Only considering 4x4 matrices for the moment. 

Basic Rules:
- The value of each cell > 0 represents the visiblity of the cell, going from top to bottom, left and right. Diagonals are not considered.
- A board is valid if each cell can satisfiy its visibility range. For example:

0 | 2 | 1 <br />
0 | 1 | 0 <br /> 
0 | 0 | 0 <br />
<br />
*This board satisfies, as each cell can see the exact number of cells its value represents. So in [0][1], the "2" can see exactly 2 cells. The [0][2] cell can see exactly only 1 cell.
<br />
- An example of an invalid board:
0 | 2 | 2 <br />
0 | 1 | 0 <br />
0 | 0 | 0 <br />
*The board does not satisfy as [0][2] has a visibility range of 2 but only sees 1 cell.
<br />
Update (5/2/2018): 
- Implementing backtracking algorithm to effectively generate a random board. The primative way of using a nested for loop and generating a random number sequentially was so slow, it did not even generate a valid board in 10 minute time frame.
- Removed a lot of unneeded functions and simplified the validation function.
