/*
#200. Number of Islands

Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example:
Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
*/

// Sol 1: DFS
// Time:  O(mn)
// Space: O(mn)
class Solution {
private:
    int m;
    int n;
public:
    void fill(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0') return;
        grid[i][j] == '1';
        fill(grid, i-1, j);
        fill(grid, i+1, j);
        fill(grid, i, j-1);
        fill(grid, i, j+1);
    }

    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int numberOfIslabds = 0;

        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j] == '1') {
                    numberOfIslabds++;
                    fill(grid, i, j);
                }
            }
        }
        return numberOfIslabds;
    }
};

// Another Sol: BFS
// Time:  O(mn)
// Space: O(min(m, n))
class Solution {
private:
    int m;
    int n;
public:
    void fill(vector<vector<char>>& grid, int i, int j) {
        queue<pair<int, int>> q;
        q.push({i,j});
        grid[i][j] = '0';

        while (!q.empty()) {
            auto rc = q.front();
            q.pop();
            int row = rc.first, col = rc.second;
            if (row - 1 >= 0 && grid[row-1][col] == '1') {
                grid[row-1][col] = '0';
                q.push({row-1, col});
            }
            if (row + 1 < m && grid[row+1][col] == '1') {
                grid[row+1][col] = '0';
                q.push({row+1, col});
            }
            if (col - 1 >= 0 && grid[row][col-1] == '1') {
                grid[row][col-1] = '0';
                q.push({row, col-1});
            }
            if (col + 1 < n && grid[row][col+1] == '1') {
                grid[row][col+1] = '0';
                q.push({row, col+1});
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int numberOfIslabds = 0;

        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j] == '1') {
                    numberOfIslabds++;
                    fill(grid, i, j);
                }
            }
        }
        return numberOfIslabds;
    }
};