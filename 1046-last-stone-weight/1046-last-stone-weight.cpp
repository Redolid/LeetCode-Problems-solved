class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
    // Create a max heap to store stone weights
    priority_queue<int> maxHeap(stones.begin(), stones.end());
    
    // Keep smashing stones until there's only one or none left
    while (maxHeap.size() > 1) {
        // Get the two heaviest stones
        int stone1 = maxHeap.top();
        maxHeap.pop();
        int stone2 = maxHeap.top();
        maxHeap.pop();
        
        // Calculate the new weight of the remaining stone
        int newStone = stone1 - stone2;
        
        // Add the new stone to the heap if it's not completely smashed
        if (newStone > 0) {
            maxHeap.push(newStone);
        }
    }
    
    // Return the weight of the last remaining stone, or 0 if there are none left
    return maxHeap.empty() ? 0 : maxHeap.top();
}
};