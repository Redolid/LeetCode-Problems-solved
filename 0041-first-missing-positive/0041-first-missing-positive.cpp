class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();
    
    // Move all positive integers to their corresponding index
    for (int i = 0; i < n; i++) {
        while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
            swap(nums[i], nums[nums[i] - 1]);
        }
    }
    
    // Find the first missing positive integer
    for (int i = 0; i < n; i++) {
        if (nums[i] != i + 1) {
            return i + 1;
        }
    }
    
    // If all integers are present, the next missing integer is n+1
    return n + 1;
}

};