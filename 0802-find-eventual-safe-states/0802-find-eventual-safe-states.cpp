class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> outDegrees(n); // Store the out-degrees of nodes
        vector<vector<int>> reverseGraph(n); // Reverse graph for checking safe nodes
        queue<int> q; // Queue for BFS traversal
        vector<int> safeNodes; // Resultant safe nodes
        
        // Build the reverse graph and calculate out-degrees
        for (int i = 0; i < n; i++) {
            outDegrees[i] = graph[i].size();
            for (int j : graph[i]) {
                reverseGraph[j].push_back(i);
            }
            
            // Add nodes with out-degree 0 to the queue
            if (outDegrees[i] == 0) {
                q.push(i);
            }
        }
        
        // Perform BFS traversal starting from nodes with out-degree 0
        while (!q.empty()) {
            int currNode = q.front();
            q.pop();
            
            // Mark the node as safe
            safeNodes.push_back(currNode);
            
            // Reduce the out-degree of adjacent nodes in the reverse graph
            for (int adjNode : reverseGraph[currNode]) {
                if (--outDegrees[adjNode] == 0) {
                    q.push(adjNode);
                }
            }
        }
        
        // Sort the safe nodes in ascending order
        sort(safeNodes.begin(), safeNodes.end());
        
        return safeNodes;
    }
};
