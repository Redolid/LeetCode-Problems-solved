class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    int n = s.length();
    int ans = 0;
    int i = 0, j = 0;
    unordered_set<char> set;

    while (i < n && j < n) {
        // Try to extend the sliding window [i, j]
        if (set.count(s[j]) == 0) {
            set.insert(s[j++]);
            ans = max(ans, j - i);
        } else {
            set.erase(s[i++]);
        }
    }
    return ans;
}

};