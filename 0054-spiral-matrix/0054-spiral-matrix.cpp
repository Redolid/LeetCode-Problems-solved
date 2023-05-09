class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> res;
    if (matrix.empty()) return res;
    int m = matrix.size(), n = matrix[0].size();
    int i = 0, j = 0;
    while (m > 0 && n > 0) {
        // print top row
        for (int k = 0; k < n; k++)
            res.push_back(matrix[i][j++]);
        i++; j--; m--;
        if (m == 0 || n == 0) break;
        // print right column
        for (int k = 0; k < m; k++)
            res.push_back(matrix[i++][j]);
        i--; j--; n--;
        if (m == 0 || n == 0) break;
        // print bottom row
        for (int k = 0; k < n; k++)
            res.push_back(matrix[i][j--]);
        i--; j++; m--;
        if (m == 0 || n == 0) break;
        // print left column
        for (int k = 0; k < m; k++)
            res.push_back(matrix[i--][j]);
        i++; j++; n--;
    }
    return res;
}
};