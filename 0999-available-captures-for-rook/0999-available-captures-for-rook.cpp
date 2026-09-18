class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int r, c;

        // Find the rook
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (board[i][j] == 'R') {
                    r = i;
                    c = j;
                }
            }
        }

        int count = 0;

        // 4 directions: up, down, left, right
        vector<pair<int, int>> dir = {
            {-1, 0},
            {1, 0},
            {0, -1},
            {0, 1}
        };

        for (auto [dr, dc] : dir) {
            int nr = r + dr;
            int nc = c + dc;

            while (nr >= 0 && nr < 8 && nc >= 0 && nc < 8) {

                // Bishop blocks the rook
                if (board[nr][nc] == 'B') {
                    break;
                }

                // Pawn can be captured
                if (board[nr][nc] == 'p') {
                    count++;
                    break;
                }

                // Empty cell
                nr += dr;
                nc += dc;
            }
        }

        return count;
    }
};