#include <bits/stdc++.h>
using namespace std;

// 定义扑克牌结构体
struct Pai {
    int suit;   // 牌面值：0-小王,1-大王,3-3,4-4,...,13-K,14-A,15-2
    int color;  // 花色：1-4 分别代表黑桃、红心、梅花、方片
    
    // 重载小于运算符，用于排序
    bool operator<(const Pai &rhs) const { return suit < rhs.suit; }
    
    // 重载等于运算符，用于查找和比较
    bool operator==(const Pai &rhs) const {
        return suit == rhs.suit && color == rhs.color;
    }
};

// 定义手牌结构体
struct HandIn {
    vector<Pai> cards;  // 存储所有手牌的向量
    vector<int> nums;   // 统计每种牌面值的数量，下标对应牌面值
    
    // 更新nums数组，统计每种牌的数量
    void getNum() {
        nums.assign(20, 0);  // 初始化数组为20个0
        for (auto &x : cards) {
            nums[x.suit]++;  // 根据牌面值计数
        }
    }
    
    // 构造函数
    HandIn(vector<Pai> c, vector<int> n) : cards(c), nums(n) { getNum(); }
};

int n, ans;  // n: 手牌数量, ans: 最小出牌次数
const int INF = 0x3f3f3f3f;  // 定义无穷大值

// 贪心计算非顺子牌的最小出牌次数
int calc(vector<int> cnt) {
    int res = 0;  // 结果：出牌次数
    int c[5] = {0};  // c[i]表示有i张相同牌面的牌的种类数
    
    // 统计各种牌的数量（跳过无效位置1）
    for (int i = 0; i <= 15; i++) {
        if (i == 1) continue; // 跳过无效位置
        c[cnt[i]]++;  // 统计有cnt[i]张牌的种类数
    }
    
    // 火箭：双王（牌面值0和1）
    if (cnt[0] > 0 && cnt[1] > 0) {
        res++;  // 火箭算一次出牌
    }
    
    // 四带二对：四张相同牌 + 两个对子
    while (c[4] > 0 && c[2] >= 2) {
        c[4]--;    // 消耗一个四张牌
        c[2] -= 2; // 消耗两个对子
        res++;     // 算一次出牌
    }
    
    // 四带二单：四张相同牌 + 两张单牌
    while (c[4] > 0 && c[1] >= 2) {
        c[4]--;    // 消耗一个四张牌
        c[1] -= 2; // 消耗两张单牌
        res++;     // 算一次出牌
    }
    
    // 四带一对：四张相同牌 + 一个对子
    while (c[4] > 0 && c[2] >= 1) {
        c[4]--; // 消耗一个四张牌
        c[2]--; // 消耗一个对子
        res++;  // 算一次出牌
    }
    
    // 三带二：三张相同牌 + 一个对子
    while (c[3] > 0 && c[2] >= 1) {
        c[3]--; // 消耗一个三张牌
        c[2]--; // 消耗一个对子
        res++;  // 算一次出牌
    }
    
    // 三带一：三张相同牌 + 一张单牌
    while (c[3] > 0 && c[1] >= 1) {
        c[3]--; // 消耗一个三张牌
        c[1]--; // 消耗一张单牌
        res++;  // 算一次出牌
    }
    
    // 剩下的牌：炸弹、三张、对子、单牌各算一次出牌
    res += c[1] + c[2] + c[3] + c[4];
    return res;
}

// 深度优先搜索函数，step表示已经出的牌次数
void dfs(HandIn &hand, int step) {
    // 剪枝：如果当前步数已经大于等于已知最小答案，直接返回
    if (step >= ans) return;
    
    // 贪心剪枝：用当前步数+剩余牌的最小出牌次数更新答案
    ans = min(ans, step + calc(hand.nums));
    
    // 枚举所有可能的单顺（5-12张连续单牌）
    for (int k = 5; k <= 12; k++) {        // k: 顺子长度
        for (int i = 3; i <= 14 - k + 1; i++) { // i: 顺子起始牌面值（从3开始）
            bool flag = true;  // 标记是否能
            // 组成顺子
            // 检查从i开始的k张牌是否都能组成顺子
            for (int j = i; j < i + k; j++) {
                if (hand.nums[j] < 1) {  // 如果某张牌数量不足
                    flag = false;        // 不能组成顺子
                    break;
                }
            }
            if (!flag) continue;  // 不能组成顺子，跳过
            
            // 能组成顺子，暂时移除这些牌
            for (int j = i; j < i + k; j++) hand.nums[j]--;
            // 递归搜索
            dfs(hand, step + 1);
            // 回溯，恢复牌的数量
            for (int j = i; j < i + k; j++) hand.nums[j]++;
        }
    }
    
    // 枚举所有可能的双顺（3-10对连续对子）
    for (int k = 3; k <= 10; k++) {        // k: 对子顺长度
        for (int i = 3; i <= 14 - k + 1; i++) { // i: 起始牌面值
            bool flag = true;
            // 检查是否能组成双顺
            for (int j = i; j < i + k; j++) {
                if (hand.nums[j] < 2) {  // 需要至少2张相同牌
                    flag = false;
                    break;
                }
            }
            if (!flag) continue;
            
            // 移除双顺的牌
            for (int j = i; j < i + k; j++) hand.nums[j] -= 2;
            dfs(hand, step + 1);
            // 回溯
            for (int j = i; j < i + k; j++) hand.nums[j] += 2;
        }
    }
    
    // 枚举所有可能的三顺（2-6组连续三张）
    for (int k = 2; k <= 6; k++) {        // k: 三张顺长度
        for (int i = 3; i <= 14 - k + 1; i++) { // i: 起始牌面值
            bool flag = true;
            // 检查是否能组成三顺
            for (int j = i; j < i + k; j++) {
                if (hand.nums[j] < 3) {  // 需要至少3张相同牌
                    flag = false;
                    break;
                }
            }
            if (!flag) continue;
            
            // 移除三顺的牌
            for (int j = i; j < i + k; j++) hand.nums[j] -= 3;
            dfs(hand, step + 1);
            // 回溯
            for (int j = i; j < i + k; j++) hand.nums[j] += 3;
        }
    }
}

// 转换牌面值函数
void convertCards(vector<Pai>& cards) {
    for (auto &card : cards) {
        if (card.suit == 0) continue; // 小王不变
        // 牌面值转换：
        if (card.suit == 1) card.suit = 14; // A转换为14
        else if (card.suit == 2) card.suit = 15; // 2转换为15
        // 3-13保持不变
    }
}

// 以下为空函数，仅为了保持原有的接口结构
vector<Pai *> shunZi1(HandIn &hand) { return {}; }
vector<Pai *> shunZi2(HandIn &hand) { return {}; }
vector<Pai *> shunZi3(HandIn &hand) { return {}; }
vector<Pai *> rocket(HandIn &hand) { return {}; }
vector<Pai *> bomb(HandIn &hand) { return {}; }
vector<Pai *> doub(HandIn &hand) { return {}; }
vector<Pai *> single(HandIn &hand) { return {}; }

// 方法函数指针数组（保持原有结构）
vector<Pai *> (*methods[])(HandIn &) = {rocket, bomb, shunZi3, shunZi2, shunZi1, doub, single};
vector<int> methodCount(7, 0);  // 方法计数数组（保持原有结构）

// 求解函数
int solve(HandIn &hand) {
    // 转换牌面值为内部表示
    convertCards(hand.cards);
    // 更新牌的数量统计
    hand.getNum();
    
    // 初始化答案为无穷大
    ans = INF;
    // 开始深度优先搜索
    dfs(hand, 0);
    return ans;
}

int main() {
    ios::sync_with_stdio(false);  // 关闭cin和cout的同步，提高速度
    cin.tie(nullptr);             // 解除cin和cout的绑定
    
    int T, n;  // T: 测试用例数, n: 手牌数量
    cin >> T >> n;
    
    // 处理每个测试用例
    while (T--) {
        vector<Pai> cards(n);    // 存储手牌
        vector<int> nums(20);    // 牌数量统计数组
        
        // 读入每张牌
        for (int i = 0; i < n; i++) {
            cin >> cards[i].suit >> cards[i].color;
        }
        
        // 创建手牌对象
        HandIn hand(cards, nums);
        // 求解并输出结果
        int res = solve(hand);
        cout << res << "\n";
    }
    return 0;
}