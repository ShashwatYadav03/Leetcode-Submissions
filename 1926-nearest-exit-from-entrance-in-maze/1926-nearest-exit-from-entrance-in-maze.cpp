class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();

        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});

        // Mark entrance visited
        maze[entrance[0]][entrance[1]] = '+';

        int steps = 0;

        int dirs[5] = {-1, 0, 1, 0, -1};

        while (!q.empty()) {
            int size = q.size();
            steps++;

            while (size--) {
                auto [r, c] = q.front();
                q.pop();

                for (int d = 0; d < 4; d++) {
                    int nr = r + dirs[d];
                    int nc = c + dirs[d + 1];

                    // Valid and unvisited cell
                    if (nr >= 0 && nr < m &&
                        nc >= 0 && nc < n &&
                        maze[nr][nc] == '.') {

                        // If it's on the boundary, it's an exit
                        if (nr == 0 || nr == m - 1 ||
                            nc == 0 || nc == n - 1) {
                            return steps;
                        }

                        // Mark visited and add to queue
                        maze[nr][nc] = '+';
                        q.push({nr, nc});
                    }
                }
            }
        }

        return -1;
    }
};