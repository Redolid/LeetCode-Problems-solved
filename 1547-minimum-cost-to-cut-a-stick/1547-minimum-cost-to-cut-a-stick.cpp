class Solution {
public:
    int minCost(int n, std::vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        std::sort(cuts.begin(), cuts.end());

        int len = cuts.size();
        std::vector<std::vector<int>> dp(len, std::vector<int>(len, 0));

        for (int l = 2; l < len; ++l) {
            for (int i = 0; i < len - l; ++i) {
                int j = i + l;
                dp[i][j] = INT_MAX;
                for (int k = i + 1; k < j; ++k) {
                    dp[i][j] = std::min(dp[i][j], dp[i][k] + dp[k][j] + cuts[j] - cuts[i]);
                }
            }
        }

        return dp[0][len - 1];
    }
};
