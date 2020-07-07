/*

You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water.

Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

 

Example:

Input:
[[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]

Output: 16

Explanation: The perimeter is the 16 yellow stripes in the image below:



*/

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) 
    {
        int row = grid.size();
        int col = (row > 0) ? grid[0].size() : 0;
        int result = 0;
        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                if(grid[i][j]) {
                    result += (i == 0 or !grid[i - 1][j]);
                    result += (i + 1 == row or !grid[i + 1][j]);
                    result += (j == 0 or !grid[i][j - 1]);
                    result += (j + 1 == col or !grid[i][j + 1]);
                }
            }
        }
        return result;
        
    }
};