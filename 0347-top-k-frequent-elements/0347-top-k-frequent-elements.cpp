class Solution {
public:
    vector<int> topKFrequent(std::vector<int>& nums, int k) {
    // Step 1: Count the frequency of each number
    std::unordered_map<int, int> freqMap;
    for (int num : nums) {
        freqMap[num]++;
    }
    
    // Step 2: Create a min-heap
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> minHeap;
    
    // Step 3: Add elements to the min-heap
    for (auto& pair : freqMap) {
        minHeap.push({pair.second, pair.first});
        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }
    
    // Step 4: Extract elements from the min-heap
    std::vector<int> result;
    while (!minHeap.empty()) {
        result.push_back(minHeap.top().second);
        minHeap.pop();
    }
    
    // Reverse the result to get the elements in descending order of frequency
    std::reverse(result.begin(), result.end());
    
    return result;
}
};