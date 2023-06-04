#include <vector>

class Solution {
public:
    int findCircleNum(std::vector<std::vector<int>>& isConnected) {
        int n = isConnected.size();
        int provinces = 0;
        std::vector<bool> visited(n, false);
        
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, isConnected, visited);
                provinces++;
            }
        }
        
        return provinces;
    }
    
private:
    void dfs(int city, std::vector<std::vector<int>>& isConnected, std::vector<bool>& visited) {
        visited[city] = true;
        
        for (int neighbor = 0; neighbor < isConnected.size(); neighbor++) {
            if (isConnected[city][neighbor] == 1 && !visited[neighbor]) {
                dfs(neighbor, isConnected, visited);
            }
        }
    }
};
