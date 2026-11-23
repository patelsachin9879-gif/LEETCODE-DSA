class Solution {
public:
    // Helper function to perform DFS and mark connected land cells
    void dfs(int i, int j, vector<vector<bool>>& vis, vector<vector<char>>& grid, int n, int m) {
        // Boundary conditions and check if cell is already visited or is water ('0')
        if (i < 0 || j < 0 || i >= n || j >= m || vis[i][j] || grid[i][j] != '1') {
            return;
        }
        
        // Mark the current cell as visited
        vis[i][j] = true;
        
        // Recursively visit all 4 neighboring directions
        dfs(i - 1, j, vis, grid, n, m); // Top
        dfs(i, j + 1, vis, grid, n, m); // Right
        dfs(i + 1, j, vis, grid, n, m); // Bottom
        dfs(i, j - 1, vis, grid, n, m); // Left
    }

    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        
        int islands = 0;
        int n = grid.size();
        int m = grid[0].size();
        
        // Initialize the 2D visited array with false
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        
        // Traverse every cell in the grid
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // If a cell is land ('1') and hasn't been visited yet, it's a new island
                if (grid[i][j] == '1' && !vis[i][j]) {
                    islands++;
                    dfs(i, j, vis, grid, n, m); // Flood-fill the entire island
                }
            }
        }
        
        return islands;
    }
};