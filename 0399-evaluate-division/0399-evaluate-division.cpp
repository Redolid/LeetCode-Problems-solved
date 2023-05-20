class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> graph;
        
        // Build the graph
        for (int i = 0; i < equations.size(); i++) {
            const string& dividend = equations[i][0];
            const string& divisor = equations[i][1];
            double quotient = values[i];
            
            // Add edges for both directions
            graph[dividend][divisor] = quotient;
            graph[divisor][dividend] = 1.0 / quotient;
        }
        
        vector<double> results;
        
        // Evaluate each query
        for (const auto& query : queries) {
            const string& dividend = query[0];
            const string& divisor = query[1];
            
            // If any variable is not in the graph, the result cannot be determined
            if (!graph.count(dividend) || !graph.count(divisor)) {
                results.push_back(-1.0);
            } else {
                unordered_set<string> visited;
                double result = backtrack(graph, dividend, divisor, visited);
                results.push_back(result);
            }
        }
        
        return results;
    }
    
    double backtrack(unordered_map<string, unordered_map<string, double>>& graph, const string& curr, const string& target, unordered_set<string>& visited) {
        // If we reach the target variable, return the accumulated quotient
        if (curr == target) {
            return 1.0;
        }
        
        visited.insert(curr);
        
        // Explore all neighbors of the current variable
        for (const auto& neighbor : graph[curr]) {
            const string& next = neighbor.first;
            double edgeQuotient = neighbor.second;
            
            // If the neighbor is not visited, perform DFS
            if (!visited.count(next)) {
                double result = backtrack(graph, next, target, visited);
                if (result != -1.0) {
                    return edgeQuotient * result;
                }
            }
        }
        
        // The target variable cannot be reached from the current variable
        return -1.0;
    }
};
