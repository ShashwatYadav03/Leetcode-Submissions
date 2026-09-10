class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int cc = 0;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {

                // Water
                if (grid[r][c] == '0') {
                    continue;
                }

                // Found a new island
                cc++;

                queue<pair<int, int>> qu;

                // Mark starting cell as visited
                grid[r][c] = '0';

                qu.push({r, c});

                while (!qu.empty()) {

                    auto curr = qu.front();
                    qu.pop();

                    int currRow = curr.first;
                    int currCol = curr.second;

                    // Up
                    if (currRow - 1 >= 0 &&
                        grid[currRow - 1][currCol] == '1') {

                        qu.push({currRow - 1, currCol});
                        grid[currRow - 1][currCol] = '0';
                    }

                    // Down
                    if (currRow + 1 < rows &&
                        grid[currRow + 1][currCol] == '1') {

                        qu.push({currRow + 1, currCol});
                        grid[currRow + 1][currCol] = '0';
                    }

                    // Left
                    if (currCol - 1 >= 0 &&
                        grid[currRow][currCol - 1] == '1') {

                        qu.push({currRow, currCol - 1});
                        grid[currRow][currCol - 1] = '0';
                    }

                    // Right
                    if (currCol + 1 < cols &&
                        grid[currRow][currCol + 1] == '1') {

                        qu.push({currRow, currCol + 1});
                        grid[currRow][currCol + 1] = '0';
                    }
                }
            }
        }

        return cc;
    }
};