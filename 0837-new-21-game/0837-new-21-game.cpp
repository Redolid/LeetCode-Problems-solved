class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if (k == 0 || n >= k + maxPts)
            return 1.0;
        
        vector<double> dp(n + 1);
        dp[0] = 1.0;
        double probabilitySum = 1.0;
        
        for (int i = 1; i <= n; i++) {
            dp[i] = probabilitySum / maxPts;
            if (i < k)
                probabilitySum += dp[i];
            if (i - maxPts >= 0)
                probabilitySum -= dp[i - maxPts];
        }
        
        double result = 0.0;
        for (int i = 0; i <= n; i++) {
            if (i >= k)
                result += dp[i];
        }
        
        return result;
    }
};
