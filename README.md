# Ohn0-C-game
My C++ implemention of Martin Kool's Oh n0 game. 

My implemention of the Oh n0 game written in C++. 

Currently not finished, not even close. Only considering 4x4 matrices in the mean time. 

Update 1:
1. Create the primative board generation, where each randomly generated 4x4 matrix is passed along validBoard() function to determine which board is a valid solution.
Not optimized, as each random 4x4 board generated is expensive, until one of those boards is a solution. 
2. Optimize random board generation function, make it less expensive.
3. Allow user to select row and col size of the matrix. 

Update 2: 
1. Implement time method gameplay.
2. Technique to hide appropriate cells to user and have user select cells to determine if it's a probable cell.
3. If user selects wrong cell, implement penalty mechanism.
4. Game is won if user finds the correct solution.

Update 3: 
1. Review validBoard() function, optimize. 
2. Continue time gameplay mechanic, if user finds correct solution, present another xy matrix.
3. Game is won through highscore, how many matrix can the user solve before time runs out. 
