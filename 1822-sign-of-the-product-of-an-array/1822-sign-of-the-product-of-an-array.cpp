class Solution {
public:
    int arraySign(vector<int>& nums) {
        int product = 1;
        for(int c : nums) {
            if(c > 0) {
                product *= 1;
            }
            else if(c < 0) {
                product *= -1;
            }
            else {
                return 0;
            }
        }
        return product > 0 ? 1 : -1; //return 1 if product is positive otherwise return -1
    }
};
