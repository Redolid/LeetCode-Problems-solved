#include <vector>
#include <unordered_map>

class Solution {
public:
    int numOfMinutes(int n, int headID, std::vector<int>& manager, std::vector<int>& informTime) {
        std::unordered_map<int, std::vector<int>> adjList;
        
        // Build the adjacency list
        for (int i = 0; i < n; i++) {
            if (manager[i] != -1) {
                adjList[manager[i]].push_back(i);
            }
        }
        
        return dfs(headID, adjList, informTime);
    }
    
private:
    int dfs(int employee, std::unordered_map<int, std::vector<int>>& adjList, std::vector<int>& informTime) {
        if (adjList.find(employee) == adjList.end()) {
            return 0;  // Leaf node, no subordinates
        }
        
        int maxTime = 0;
        for (int subordinate : adjList[employee]) {
            maxTime = std::max(maxTime, dfs(subordinate, adjList, informTime));
        }
        
        return maxTime + informTime[employee];
    }
};
