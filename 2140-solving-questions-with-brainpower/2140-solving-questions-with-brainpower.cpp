class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n + 1);
        for (int i = 0; i < n; i++) {
            dp[i+1] = max(dp[i+1], dp[i]);
            int j = min(n, i + 1 + questions[i][1]);
            dp[j] = max(dp[j], dp[i] + questions[i][0]);
        }
        return dp[n];
    }
};
