class UnionFind {
public:
    vector<int> parent;
    UnionFind(int n) {
        parent.resize(n);
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
    void merge(int x, int y) {
        parent[find(x)] = find(y);
    }
    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};

class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        vector<pair<int, int>> idx;
        for (int i = 0; i < queries.size(); i++) {
            idx.push_back({ queries[i][2], i });
        }
        sort(idx.begin(), idx.end());
        UnionFind uf(n);
        vector<bool> ans(queries.size(), false);
        int i = 0;
        sort(edgeList.begin(), edgeList.end(), [](auto& a, auto& b) {
            return a[2] < b[2];
        });
        for (auto& p : idx) {
            int limit = p.first, idx = p.second;
            while (i < edgeList.size() && edgeList[i][2] < limit) {
                uf.merge(edgeList[i][0], edgeList[i][1]);
                i++;
            }
            ans[idx] = uf.connected(queries[idx][0], queries[idx][1]);
        }
        return ans;
    }
};
