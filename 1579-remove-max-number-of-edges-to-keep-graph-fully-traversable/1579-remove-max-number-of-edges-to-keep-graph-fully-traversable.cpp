class UnionFind {
public:
    UnionFind(int n) : parent(n), size(n, 1), count(n) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    bool unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) {
            return false;
        }
        if (size[px] < size[py]) {
            swap(px, py);
        }
        parent[py] = px;
        size[px] += size[py];
        count--;
        return true;
    }
    
    int getCount() {
        return count;
    }

private:
    vector<int> parent, size;
    int count;
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        int ans = 0;
        UnionFind alice(n), bob(n);
        for (const auto& e : edges) {
            if (e[0] == 3) {
                if (alice.unite(e[1] - 1, e[2] - 1)) {
                    bob.unite(e[1] - 1, e[2] - 1);
                } else {
                    ans++;
                }
            }
        }
        for (const auto& e : edges) {
            if (e[0] == 1) {
                if (!alice.unite(e[1] - 1, e[2] - 1)) {
                    ans++;
                }
            } else if (e[0] == 2) {
                if (!bob.unite(e[1] - 1, e[2] - 1)) {
                    ans++;
                }
            }
        }
        if (alice.getCount() > 1 || bob.getCount() > 1) {
            return -1;
        }
        return ans;
    }
};
