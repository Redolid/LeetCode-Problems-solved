class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        // Perform DFS to mark the first island
        bool found = false;
        queue<pair<int, int>> q;
        vector<vector<int>> visited(rows, vector<int>(cols, 0));
        
        // DFS to mark all cells of the first island
        for (int i = 0; i < rows; i++) {
            if (found) {
                break;
            }
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    dfs(grid, i, j, visited, q);
                    found = true;
                    break;
                }
            }
        }
        
        // BFS to find the shortest distance to the second island
        int distance = 0;
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                
                for (int k = 0; k < 4; k++) {
                    int nx = x + dirs[k][0];
                    int ny = y + dirs[k][1];
                    
                    if (isValid(nx, ny, rows, cols) && !visited[nx][ny]) {
                        if (grid[nx][ny] == 1) {
                            return distance;
                        }
                        
                        q.push({nx, ny});
                        visited[nx][ny] = 1;
                    }
                }
            }
            
            distance++;
        }
        
        return -1; // No path found
    }
    
private:
    void dfs(vector<vector<int>>& grid, int x, int y, vector<vector<int>>& visited, queue<pair<int, int>>& q) {
        if (!isValid(x, y, grid.size(), grid[0].size()) || visited[x][y] || grid[x][y] == 0) {
            return;
        }
        
        visited[x][y] = 1;
        q.push({x, y});
        
        dfs(grid, x - 1, y, visited, q);
        dfs(grid, x + 1, y, visited, q);
        dfs(grid, x, y - 1, visited, q);
        dfs(grid, x, y + 1, visited, q);
    }
    
    bool isValid(int x, int y, int rows, int cols) {
        return x >= 0 && x < rows && y >= 0 && y < cols;
    }
};
