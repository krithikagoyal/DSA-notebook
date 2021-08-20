#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
int n;

void topoSortBFS() {  // also tells cycle
    vector<int> indegree(n + 1, 0);
    for (int i = 0; i <= n; i++) {
        for (auto x : adj[i])
            indegree[i]++;
    }
    queue<int> q;
    for (int i = 0; i <= n; i++) {
        if (indegree[i] == 0)
            q.push(i);
    }
    vector<int> ans;
    int num = 0;
    bool isCycle = false;  // to check for cycle;
    while (q.size()) {
        auto node = q.front();
        q.pop();
        for (auto x : adj[node]) {
            indegree[x]--;
            if (indegree[x] == 0) {
                ans.push_back(x);
                q.push(x);
            }
        }
        num++;
    }
    if (num != n)
        isCycle = true;
    // "ans" contains sorted nodes.
}

void dfsSort(int v, vector<bool>& vis, vector<vector<int>>& adj, vector<int>& ans) {
    vis[v] = true;
    for (int u : adj[v]) {
        if (!vis[u])
            dfsSort(u, vis, adj, ans);
    }
    ans.push_back(v);
}  // for topo sort

void topoSortDFS() {
    vector<bool> vis(n + 1, false);
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        if (!vis[i])
            dfsSort(i, vis, adj, ans);
    }
    reverse(ans.begin(), ans.end());
}

void bipartiteBFS() {
    queue<int> q;
    q.push(1);
    vector<int> color(n + 1, -1);
    color[1] = 0;
    bool ok = true;
    while (q.size()) {
        int node = q.front();
        q.pop();
        for (auto x : adj[node]) {
            if (color[x] == -1) {
                color[x] = color[node] ^ 1;
                q.push(x);
            } else if (color[x] == color[node]) {
                ok = false;
            }
        }
    }
    // "ok" tells whether graph is bipartite or not.
}

bool bipartiteDFS(int v, vector<int>& color, vector<bool>& vis) {
    vis[v] = true;
    for (int u : adj[v]) {
        if (vis[u] == false) {
            color[u] = !color[v];
            if (!bipartiteDFS(u, color, vis))
                return false;
        } else if (color[u] == color[v])
            return false;
    }
    return true;
}

bool dfsCycle(int v, vector<int>& color, vector<int>& parent, int& cycleStart, int& cycleEnd) {
    color[v] = 1;
    for (int u : adj[v]) {
        if (color[u] == 0) {
            parent[u] = v;
            if (dfsCycle(u, color, parent, cycleStart, cycleEnd))
                return true;
        } else if (color[u] == 1) {
            cycleEnd = v;
            cycleStart = u;
            return true;
        }
    }
    color[v] = 2;
    return false;
}

void findCycle() {
    vector<int> color(n + 1, 0);
    vector<int> parent(n + 1, -1);
    int cycleStart = -1, cycleEnd = -1;

    for (int v = 0; v < n; v++) {
        if (color[v] == 0 && dfsCycle(v, color, parent, cycleStart, cycleEnd))
            break;
    }

    if (cycleStart == -1) {
        cout << "Acyclic" << endl;
    } else {
        vector<int> cycle;
        cycle.push_back(cycleStart);
        for (int v = cycleEnd; v != cycleStart; v = parent[v])
            cycle.push_back(v);

        cycle.push_back(cycleStart);
        reverse(cycle.begin(), cycle.end());

        cout << "Cycle found: ";
        for (int v : cycle)
            cout << v << " ";
        cout << endl;
    }
}

void dijkstra() {
    vector<vector<pair<int, int>>> adj;  // {node, distance}
    int src;
    set<pair<int, int>> s;
    vector<int> d(n + 1, INT32_MAX);
    s.insert({0, src});
    while (s.size()) {
        auto node = *s.begin();
        s.erase(s.begin());
        if (d[node.first] == INT32_MAX)
            break;
        for (auto x : adj[node.second]) {
            if (d[x.first] > node.first + x.second) {
                s.erase({d[x.first], x.first});
                d[x.first] = node.first + x.second;
                s.insert({d[x.first], x.first});
            }
        }
    }
    // "d" contains all the distance.
}

void bellman() {
    int src;
    vector<int> d(n, INT32_MAX);
    d[src] = 0;
    vector<vector<int>> e; // "e" edge from e[0] -> e[1] with cost e[2]
    for (;;) {
        bool any = false;

        for (int j = 0; j < e.size(); j++) {
            if (d[e[j][0]] < INT32_MAX) {
                if (d[e[j][1]] > d[e[j][0]] + e[j][2]) {
                    d[e[j][1]] = d[e[j][0]] + e[j][2];
                    any = true;
                }
            }
        }

        if (!any) break;
    }
    // display d, for example, on the screen
}

int32_t main() {
}