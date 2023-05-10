class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int num = 1;
        int top = 0, bottom = n - 1, left = 0, right = n - 1;
        
        while (num <= n * n) {
            // Traverse right
            for (int i = left; i <= right; i++)
                matrix[top][i] = num++;
            top++;
            
            // Traverse down
            for (int i = top; i <= bottom; i++)
                matrix[i][right] = num++;
            right--;
            
            // Traverse left
            for (int i = right; i >= left; i--)
                matrix[bottom][i] = num++;
            bottom--;
            
            // Traverse up
            for (int i = bottom; i >= top; i--)
                matrix[i][left] = num++;
            left++;
        }
        
        return matrix;
    }
};
