#include <vector>

#include "bits/stdc++.h"
using namespace std;

#define DEBUG
#ifdef DEBUG
#define dbg(x) cout << __LINE__ << ": " << #x << " = " << (x) << "\n"
#else
#define dbg(x)
#endif

struct Node {
    int parent;
    vector<int> children;
    Node() : parent(0) {}
};
int find(int x, vector<Node> &tree) {
    if (tree[x].parent == x) {
        return x;
    } else {
        return find(tree[x].parent, tree);
    }
}

void merge(int n, vector<Node> &tree) {
    for (int i = 1; i <= n; i++) {
        for (int j : tree[i].children) {
            int fi = find(i, tree);
            int fj = find(j, tree);

            tree[fj].parent = (fi == fj) ? fj : fi;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream cin("in");

    int n, m;
    cin >> n >> m;
    vector<Node> tree(n + 1);
    for (int i = 1; i <= n; i++) {
        tree[i].parent = i;
    }
    for (int i = 1; i <= m; i++) {
        int p, c;
        cin >> p >> c;
        tree[c].parent = p;
        tree[p].children.push_back(c);
    }
    merge(n, tree);

    int q, c, d;
    cin >> q;
    while (q--) {
        cin >> c >> d;
        if (find(c, tree) == find(d, tree)) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}