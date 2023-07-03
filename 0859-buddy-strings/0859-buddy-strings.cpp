class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.length() != goal.length()) {
            return false;
        }
        
        // If s and goal are identical, check if there are any repeating characters
        if (s == goal) {
            vector<int> charCount(26, 0);
            for (char c : s) {
                if (++charCount[c - 'a'] > 1) {
                    return true;
                }
            }
            return false;
        }
        
        vector<int> diffIndices;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != goal[i]) {
                diffIndices.push_back(i);
            }
        }
        
        return diffIndices.size() == 2 && s[diffIndices[0]] == goal[diffIndices[1]] && s[diffIndices[1]] == goal[diffIndices[0]];
    }
};
