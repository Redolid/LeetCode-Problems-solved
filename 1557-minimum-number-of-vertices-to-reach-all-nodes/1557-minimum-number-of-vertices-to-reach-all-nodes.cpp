class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> isSink(n, true); // Initialize all nodes as sink nodes
        
        // Mark nodes that have outgoing edges as non-sink nodes
        for (const vector<int>& edge : edges) {
            isSink[edge[1]] = false;
        }
        
        vector<int> result;
        
        // Add sink nodes to the result
        for (int i = 0; i < n; ++i) {
            if (isSink[i]) {
                result.push_back(i);
            }
        }
        
        return result;
    }
};
