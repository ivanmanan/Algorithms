class Solution:
    def dfs(self, r, c, max_rows, max_cols, grid, visited):
        if r < 0 or c < 0 or r >= max_rows or c >= max_cols or grid[r][c] == "0" or visited[r][c]:
            return

        visited[r][c] = True
        row_neighbors = [1, 0, 0, -1]
        col_neighbors = [0, 1, -1, 0]

        for i in range(4):
            new_r = r + row_neighbors[i]
            new_c = c + col_neighbors[i]
            self.dfs(new_r, new_c, max_rows, max_cols, grid, visited)

    def numIslands(self, grid: List[List[str]]) -> int:
        max_rows = len(grid)
        max_cols = len(grid[0])

        res = 0
        visited = [[False for _ in range(max_cols)] for _ in range(max_rows)]

        for r in range(max_rows):
            for c in range(max_cols):
                if grid[r][c] == "1" and not visited[r][c]:
                    res += 1
                    self.dfs(r, c, max_rows, max_cols, grid, visited)
        return res
