#include <fstream>
#include <vector>
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
    Rode(int x=0, int y=0, int t=0): x(x), y(y), t(t) {}
};

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

int merge(int n, vector<Node> &tree) {
    for (int i = 1; i <= n; i++) {
        for (int j : tree[i].children) {
            int fi = find(i, tree);
            int fj = find(j, tree);

            tree[fj].parent = (fi == fj) ? fj : fi;
        }
    }
    return 0;
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // ifstream cin("in");

    int n,m;
    cin >> n >> m;
    vector<Rode> rodes(m+1);
    for (int i = 1; i <= m; i++) {
        cin >> rodes[i].x >> rodes[i].y >> rodes[i].t;
    }

    vector<Node> tree(n + 1);
    for (int i = 1; i <= n; i++) {
        tree[i].parent = i;
    }
    for (int i = 1; i <= m; i++) {
        int p = rodes[i].x;
        int c = rodes[i].y;
        tree[c].parent = p;
        tree[p].children.push_back(c);
    }
    merge(n, tree);

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(find(i, tree) == find(j, tree)) {
                
            } else {
                cout << -1;
                return 0;
            }
        }
        
    }

    return 0;
}