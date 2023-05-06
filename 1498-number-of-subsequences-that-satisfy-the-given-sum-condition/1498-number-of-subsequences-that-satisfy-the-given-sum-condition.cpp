class Solution {
public:
    int MOD = 1e9 + 7;

    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0, l = 0, r = n - 1;
        while (l <= r) {
            if (nums[l] + nums[r] <= target) {
                ans = (ans + pow2(r - l)) % MOD;
                l++;
            } else {
                r--;
            }
        }
        return ans;
    }

    int pow2(int n) {
        long long ans = 1, x = 2;
        while (n > 0) {
            if (n & 1) ans = (ans * x) % MOD;
            x = (x * x) % MOD;
            n >>= 1;
        }
        return ans;
    }
};
