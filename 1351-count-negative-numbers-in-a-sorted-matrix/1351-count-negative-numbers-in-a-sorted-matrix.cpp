class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size(); // Number of rows
        int n = grid[0].size(); // Number of columns
        
        int count = 0;
        int row = 0;
        int col = n - 1;
        
        while (row < m && col >= 0) {
            if (grid[row][col] < 0) {
                count += (m - row); // Add the remaining elements in the current column
                col--; // Move to the left column
            } else {
                row++; // Move to the next row
            }
        }
        
        return count;
    }
};
