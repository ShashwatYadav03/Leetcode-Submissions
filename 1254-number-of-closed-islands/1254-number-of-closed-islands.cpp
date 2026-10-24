class Solution {
public:
    int m, n;

    bool dfs(int r, int c, vector<vector<int>>& grid) {
        grid[r][c] = 1;  // Mark land as visited

        bool closed = true;

        // If land touches the boundary, it is not closed
        if (r == 0 || c == 0 || r == m - 1 || c == n - 1) {
            closed = false;
        }

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k];
            int nc = c + dc[k];

            if (nr >= 0 && nr < m &&
                nc >= 0 && nc < n &&
                grid[nr][nc] == 0) {

                bool result = dfs(nr, nc, grid);

                if (!result) {
                    closed = false;
                }
            }
        }

        return closed;
    }
    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    if (dfs(i, j, grid)) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};