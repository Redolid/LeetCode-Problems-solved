class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end()); // Sort the array in ascending order
        
        int diff = arr[1] - arr[0]; // Calculate the common difference
        
        // Check if differences between consecutive pairs are equal to diff
        for (int i = 2; i < arr.size(); i++) {
            if (arr[i] - arr[i - 1] != diff) {
                return false; // If any difference is different, return false
            }
        }
        
        return true; // All differences are equal, return true
    }
};
