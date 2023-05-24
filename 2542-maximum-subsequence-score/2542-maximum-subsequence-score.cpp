class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        
        vector<pair<int, int>> pairs;
        for (int i = 0; i < n; i++) {
            pairs.push_back(make_pair(nums1[i], nums2[i]));
        }
        sort(pairs.begin(), pairs.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second;
        });

        priority_queue<int, vector<int>, greater<int>> top_k_heap;
        long long top_k_sum = 0;
        for (int i = 0; i < k; i++) {
            top_k_heap.push(pairs[i].first);
            top_k_sum += pairs[i].first;
        }

        long long answer = top_k_sum * pairs[k - 1].second;
        for (int i = k; i < n; i++) {
            top_k_heap.push(pairs[i].first);
            top_k_sum += pairs[i].first;

            int smallest = top_k_heap.top();
            top_k_heap.pop();
            top_k_sum -= smallest;

            long long score = top_k_sum * pairs[i].second;
            answer = max(answer, score);
        }

        return answer;
    }
};