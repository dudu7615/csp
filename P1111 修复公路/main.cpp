#include "bits/stdc++.h"
using namespace std;

#define DEBUG
#ifdef DEBUG
#define dbg(x) cout << __LINE__ << ": " << #x << " = " << (x) << "\n";
#else
#define dbg(x)
#endif

struct Rode {
    int x, y, t;
    bool operator<(const Rode& o) {
        return t<o.t;
    }
    Rode(int x = 0, int y = 0, int t = 0) : x(x), y(y), t(t) {}
};

struct Node {
    int parent;
    vector<int> children;
    Node(int p) : parent(p) {}
};

int find(int x, vector<Node>& tree) {
    if (tree[x].parent == x) {
        return x;
    } else {
        return find(tree[x].parent, tree);
    }
}

int merge(int x, int y, vector<Node>& tree) {
    int px = find(x, tree);
    int py = find(y, tree);
    if (px != py) {
        tree[py].parent = px;
        tree[px].children.push_back(py);
    }

    return 0;
}

int solve(vector<Rode>& roads, vector<Node>& nodes) {
    int mmax = 0;
    for (int i = 1; i < roads.size(); i++) {
        int px = roads[i].x;
        int py = roads[i].y;
        if (px != py) {
            merge(px, py, nodes);
            mmax = max(mmax, roads[i].t);
        }
    }

    int p = find(1,nodes);
    for (int i = 1; i < nodes.size(); i++) {
        if (find(i,nodes) != p) {
            return -1;
        }
    }
    return mmax;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ifstream cin("in");

    int n, m;
    cin >> n >> m;
    vector<Rode> rodes(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> rodes[i].x >> rodes[i].y >> rodes[i].t;
    }
    sort(rodes.begin(),rodes.end());

    vector<Node> nodes(1,Node(0));
    for (int i = 1; i <= m; i++) {
        nodes.push_back(Node(i));
    }

    cout << solve(rodes, nodes);

    return 0;
}