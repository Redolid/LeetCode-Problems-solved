class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        
        for (int i = 0; i < 32; i++) {
            int count = 0;
            
            for (int num : nums) {
                // Count the number of set bits at position i
                if ((num >> i) & 1) {
                    count++;
                }
            }
            
            // If count is not divisible by 3, set the bit in the result
            if (count % 3 != 0) {
                result |= (1 << i);
            }
        }
        
        return result;
    }
};
