class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        queue<int> radiant, dire; // position of senators in the queue
        for (int i = 0; i < n; i++) {
            if (senate[i] == 'R') {
                radiant.push(i);
            } else {
                dire.push(i);
            }
        }
        while (!radiant.empty() && !dire.empty()) {
            int r = radiant.front(); radiant.pop();
            int d = dire.front(); dire.pop();
            if (r < d) { // Radiant senator gets to ban a Dire senator's right
                radiant.push(r+n);
            } else { // Dire senator gets to ban a Radiant senator's right
                dire.push(d+n);
            }
        }
        return radiant.empty() ? "Dire" : "Radiant";
    }
};
