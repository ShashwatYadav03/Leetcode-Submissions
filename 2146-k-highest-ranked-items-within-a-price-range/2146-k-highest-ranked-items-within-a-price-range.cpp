class Solution {
public:
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        int m = grid.size();
        int n = grid[0].size();

        int low = pricing[0];
        int high = pricing[1];

        vector<vector<int>> ans;
        vector<vector<int>> dist(m, vector<int>(n, -1));

        queue<pair<int, int>> q;
        q.push({start[0], start[1]});
        dist[start[0]][start[1]] = 0;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        vector<tuple<int, int, int, int>> items;
        // {distance, price, row, column}

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            int price = grid[r][c];

            if (price >= low && price <= high) {
                items.push_back({dist[r][c], price, r, c});
            }

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < m &&
                    nc >= 0 && nc < n &&
                    grid[nr][nc] != 0 &&
                    dist[nr][nc] == -1) {

                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }

        sort(items.begin(), items.end());

        for (int i = 0; i < min(k, (int)items.size()); i++) {
            auto [d, price, r, c] = items[i];
            ans.push_back({r, c});
        }

        return ans;
    }
};