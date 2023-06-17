class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        sort(arr2.begin(), arr2.end());
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX));
        dp[0][0] = INT_MIN;
        
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= i; j++) {
                if (arr1[i - 1] > dp[j][i - 1]) {
                    dp[j][i] = arr1[i - 1];
                }
                if (j > 0) {
                    int idx = upper_bound(arr2.begin(), arr2.end(), dp[j - 1][i - 1]) - arr2.begin();
                    if (idx < arr2.size()) {
                        dp[j][i] = min(dp[j][i], arr2[idx]);
                    }
                }
                if (i == n && dp[j][i] != INT_MAX) {
                    return j;
                }
            }
        }
        
        return -1;
    }
};
