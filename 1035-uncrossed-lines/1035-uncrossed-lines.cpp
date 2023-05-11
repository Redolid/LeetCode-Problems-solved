class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        
        // Create a 2D array to store the maximum number of uncrossed lines
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (nums1[i-1] == nums2[j-1]) {
                    // If the elements are equal, update dp value
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    // If the elements are not equal, take the maximum of previous dp values
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        // Return the maximum number of uncrossed lines
        return dp[m][n];
    }
};
