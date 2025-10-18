#include "bits/stdc++.h"
using namespace std;

struct Obj {
    int a, b, c;  // a: O2含量, b: N2含量, c: 重量
    Obj(int a = 0, int b = 0, int c = 0) : a(a), b(b), c(c) {}
};

int solve(int m, int n, int k, const vector<Obj> &objs) {
    // dp[j][l]表示至少获得j单位O2和l单位N2所需的最小重量
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
    dp[0][0] = 0;  // 初始状态：0氧气0氮气需要0重量
    
    for (int i = 1; i <= k; i++) {
        // 倒序遍历防止物品重复使用
        for (int j = m; j >= 0; j--) {
            for (int l = n; l >= 0; l--) {
                int prev_j = max(0, j - objs[i].a);
                int prev_l = max(0, l - objs[i].b);
                
                // 只有前序状态可达时才更新（避免INT_MAX溢出）
                if (dp[prev_j][prev_l] != INT_MAX) {
                    dp[j][l] = min(dp[j][l], objs[i].c + dp[prev_j][prev_l]);
                }
            }
        }
    }
    
    return dp[m][n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream cin("in");  // 注释掉文件输入，方便标准输入测试
    
    int m, n, k;
    cin >> m >> n >> k;
    vector<Obj> objs(k + 1);  // 1-based索引
    for (int i = 1; i <= k; i++) {
        cin >> objs[i].a >> objs[i].b >> objs[i].c;
    }
    
    int result = solve(m, n, k, objs);
    cout << result << "\n";
    
    return 0;
}
