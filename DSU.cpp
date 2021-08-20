#include <bits/stdc++.h>
using namespace std;

class DSU {
   public:
    vector<int> par, R;
    // initialise the parents to -1 and size of trees to be 0.
    DSU(const int n) {
        par.assign(n, -1);
        R.assign(n, 0);
    }
    int root(int val) {
        return par[val] < 0 ? val : par[val] = root(par[val]);
    }
    // worst case: logn, average: 1
    void merge(int a, int b) {
        if ((a = root(a)) == (b = root(b))) 
            return;
        if (R[a] > R[b]) swap(a, b);
        par[a] = b;
        R[b] = max(R[b], R[a] + 1);
    }
};

// Kruskal's algorithm
int MST(int n, map<pair<int, int>, int> &mp) {
    multimap<int, pair<int, int>> m;
    for (auto &x : mp) m.insert({x.second, x.first});
    DSU dsu(n);
    int ans = 0;
    for (auto x : m) {
        if (dsu.root(x.second.first) != dsu.root(x.second.second)) {
            dsu.merge(x.second.first, x.second.second);
            ans += x.first;
        }
    }
    return ans;
}