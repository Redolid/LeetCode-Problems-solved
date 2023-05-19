class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n, 0); // Colors for nodes (0: uncolored, 1: color A, -1: color B)
        
        for (int i = 0; i < n; i++) {
            if (colors[i] == 0 && !dfs(graph, colors, i, 1)) {
                return false;
            }
        }
        
        return true;
    }
    
    bool dfs(vector<vector<int>>& graph, vector<int>& colors, int node, int color) {
        colors[node] = color;
        
        for (int neighbor : graph[node]) {
            if (colors[neighbor] == color) {
                return false; // Neighbor has the same color, not bipartite
            }
            
            if (colors[neighbor] == 0 && !dfs(graph, colors, neighbor, -color)) {
                return false; // Recursive call to neighbor with the opposite color
            }
        }
        
        return true;
    }
};
