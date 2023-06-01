class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
            return -1;  // No clear path
        }
        
        vector<vector<int>> directions = {
            {-1, 0}, {1, 0}, {0, -1}, {0, 1},
            {-1, -1}, {-1, 1}, {1, -1}, {1, 1}
        };
        
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        visited[0][0] = true;
        
        queue<pair<int, int>> q;
        q.push({0, 0});
        
        int distance = 1;
        
        while (!q.empty()) {
            int size = q.size();
            
            for (int i = 0; i < size; i++) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                
                if (row == n - 1 && col == n - 1) {
                    return distance;  // Reached the bottom-right cell
                }
                
                for (const auto& dir : directions) {
                    int newRow = row + dir[0];
                    int newCol = col + dir[1];
                    
                    if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < n &&
                        grid[newRow][newCol] == 0 && !visited[newRow][newCol]) {
                        visited[newRow][newCol] = true;
                        q.push({newRow, newCol});
                    }
                }
            }
            
            distance++;
        }
        
        return -1;  // No clear path
    }
};
