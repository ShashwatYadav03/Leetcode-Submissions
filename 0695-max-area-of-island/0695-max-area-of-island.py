class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        row=len(grid)
        col=len(grid[0])

        def bfs(r, c):
            q = deque([(r, c)])
            grid[r][c] = 0
            area = 1
            while q:
                x, y = q.popleft()
                for dx, dy in [(1,0), (-1,0), (0,1), (0,-1)]:
                    nx, ny = x+dx, y+dy
                    if 0 <= nx < row and 0 <= ny < col and grid[nx][ny] == 1:
                        grid[nx][ny] = 0
                        area += 1
                        q.append((nx, ny))
            return area
        max_area=0
        for i in range(row):
            for j in range (col):
                if grid[i][j] ==1:
                    max_area=max(max_area,bfs(i,j))

        return max_area