#include <bits/stdc++.h>
using namespace std;

// while calling any function always put tl = 0, and tr = arr.size() - 1 and of v 1;
class SegmentTreeP {
   public:
    vector<int> t;
    int n;

    SegmentTreeP(const int N, vector<int>& v) {
        t.assign(4 * N + 1, 0);
        n = N;
        build(v, 1, 0, n - 1);
    }

    void build(vector<int>& a, int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = a[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(a, v * 2, tl, tm);
            build(a, v * 2 + 1, tm + 1, tr);
            t[v] = t[v * 2] + t[v * 2 + 1];
        }
    }

    void solUpdate(int v, int tl, int tr, int pos, int new_val) {
        if (tl == tr) {
            t[v] = new_val;
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                solUpdate(v * 2, tl, tm, pos, new_val);
            else
                solUpdate(v * 2 + 1, tm + 1, tr, pos, new_val);
            t[v] = t[v * 2] + t[v * 2 + 1];
        }
    }

    int solQuery(int v, int tl, int tr, int l, int r) {
        if (l > r)
            return 0;
        if (l == tl && r == tr) {
            return t[v];
        }
        int tm = (tl + tr) / 2;
        return solQuery(v * 2, tl, tm, l, min(r, tm)) + solQuery(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    }

    int query(int l, int r) {
        return solQuery(1, 0, n - 1, l, r);
    }

    void update(int pos, int new_val) {
        solUpdate(1, 0, n - 1, pos, new_val);
    }
};

class SegmentTreeR {
   public:
    vector<int> t;
    int n;

    SegmentTreeR(const int N, vector<int>& v) {
        t.assign(4 * N + 1, 0);
        n = N;
        build(v, 1, 0, n - 1);
    }

    void build(vector<int>& a, int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = a[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(a, v * 2, tl, tm);
            build(a, v * 2 + 1, tm + 1, tr);
            t[v] = t[v * 2] + t[v * 2 + 1];
        }
    }

    void solUpdate(int v, int tl, int tr, int l, int r, int new_val) {
        if (tl == tr) {
            t[v] = new_val;
        } else {
            int tm = (tl + tr) / 2;
            if (l <= tm)
                solUpdate(v * 2, tl, tm, l, tm, new_val);
            if (r > tm)
                solUpdate(v * 2 + 1, tm + 1, tr, tm + 1, r, new_val);
            t[v] = t[v * 2] + t[v * 2 + 1];
        }
    }

    int solQuery(int v, int tl, int tr, int l, int r) {
        if (l > r)
            return 0;
        if (l == tl && r == tr) {
            return t[v];
        }
        int tm = (tl + tr) / 2;
        return solQuery(v * 2, tl, tm, l, min(r, tm)) + solQuery(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    }

    int query(int l, int r) {
        return solQuery(1, 0, n - 1, l, r);
    }

    void update(int l, int r, int new_val) {
        solUpdate(1, 0, n - 1, l, r, new_val);
    }
};

int32_t main() {
    int n;
    vector<int> a;
    SegmentTree seg(n);
    seg.build(a, 0, 0, a.size() - 1);
}