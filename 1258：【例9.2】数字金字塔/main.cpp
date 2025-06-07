#include "bits/stdc++.h"
using namespace std;

struct Node {
    int value, max;

    Node* left;
    Node* right;

    Node(int v, int m, Node* l, Node* r)
        : value(v), max(m), left(l), right(r) {}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ifstream fin("in");
    cin.rdbuf(fin.rdbuf());

    int R;
    cin >> R;
    int N = R * (R + 1) / 2;

    vector<Node*> nodes(N);
    for (int i = 0; i < N; i++) {
        nodes[i] = new Node(0, 0, nullptr, nullptr);
        cin >> nodes[i]->value;
        nodes[i]->max = nodes[i]->value;
    }

    // Build the tree
    for (int i = 0; i < R; i++) {
        for (int j = 0; j <= i; j++) {
            int index = i * (i + 1) / 2 + j;
            if (i < R - 1) {
                nodes[index]->left = nodes[index + i + 1];
                nodes[index]->right = nodes[index + i + 2];
            }
        }
    }


    for (int i = 0; i < N; i++) {
        if (nodes[i]->left != nullptr) {
            nodes[i]->left->max = max(nodes[i]->left->max, nodes[i]->max+nodes[i]->left->value);
            nodes[i]->right->max = max(nodes[i]->right->max, nodes[i]->max+nodes[i]->right->value);
        }
    }

    int maxValue = INT_MIN;
    for (int i = 0; i < N; i++) {
        maxValue = max(maxValue, nodes[i]->max);
    }
    cout << maxValue << endl;
    return 0;
}