class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
    int n = obstacles.size();
    vector<int> ans(n);
    vector<int> increasing_heights;
    for(int i = 0; i < n; i++){
        int curr = obstacles[i];
        if(increasing_heights.empty() || curr >= increasing_heights.back()){
            increasing_heights.push_back(curr);
            ans[i] = increasing_heights.size();
        }
        else{
            int idx = upper_bound(increasing_heights.begin(), increasing_heights.end(), curr) - increasing_heights.begin();
            increasing_heights[idx] = curr;
            ans[i] = idx + 1;
        }
    }
    return ans;
}
};