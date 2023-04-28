class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        vector<int> parent(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if (isSimilar(strs[i], strs[j])) {
                    int parent_i = find(parent, i);
                    int parent_j = find(parent, j);
                    if (parent_i != parent_j) {
                        parent[parent_i] = parent_j;
                    }
                }
            }
        }
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (parent[i] == i) {
                count++;
            }
        }
        return count;
    }
    
    int find(vector<int>& parent, int i) {
        if (parent[i] == i) {
            return i;
        }
        return parent[i] = find(parent, parent[i]);
    }
    
    bool isSimilar(string& s1, string& s2) {
        int diff = 0;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                diff++;
            }
        }
        return diff == 0 || diff == 2;
    }
};