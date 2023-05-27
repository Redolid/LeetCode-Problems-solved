class Solution:
    def stoneGameIII(self, stoneValue: List[int]) -> str:
        n = len(stoneValue)
        dp = [float('-inf')] * (n+3)
        dp[n] = 0
        for i in range(n-1, -1, -1):
            dp[i] = max(dp[i], sum(stoneValue[i:i+1]) - dp[i+1])
            if i + 1 < n:
                dp[i] = max(dp[i], sum(stoneValue[i:i+2]) - dp[i+2])
            if i + 2 < n:
                dp[i] = max(dp[i], sum(stoneValue[i:i+3]) - dp[i+3])
        if dp[0] > 0:
            return "Alice"
        elif dp[0] < 0:
            return "Bob"
        else:
            return "Tie"
