#include <bits/stdc++.h>
using namespace std;

struct Pai {
    // suit: 0-13: A,2,3,4,5,6,7,8,9,10,J,Q,K
    // color: 1-4: 黑桃、红心、梅花、方片
    // 王: 0,1 0,2
    int suit, color;

    bool operator<(const Pai &rhs) const { return suit < rhs.suit; }
    bool operator==(const Pai &rhs) const { return suit == rhs.suit; }
};

struct HandIn {
    vector<Pai> cards;
    vector<int> nums;
    vector<int> typeCount;

    void getNum() {
        for (auto &x : cards) {
            nums[x.suit]++;
        }
    }

    void getTypeCount() {
        typeCount.assign(5, 0);
        for (int i = 0; i <= 15; i++) {
            if (i == 1) continue; // 跳过无效位置
            typeCount[nums[i]]++;
        }
        
    }

    HandIn(vector<Pai> c, vector<int> n) : cards(c), nums(n) { getNum(); }
};

bool isNext(const Pai *a, const Pai *b) {
    return (a->suit + 1 == b->suit) || (a->suit == 13 && b->suit == 1);
}

vector<Pai *> shunZi1(HandIn &hand) {
    vector<Pai *> res = {};
    vector<Pai *> tmp;
    for (auto &i : hand.cards) {
        if (i.suit >= 3 || i.suit == 1) {
            if (tmp.empty() || isNext(tmp.back(), &i)) {
                tmp.push_back(&i);
            } else if (tmp.back()->suit == i.suit) {
                continue;
            } else {
                if (tmp.size() >= 5 && tmp.size() > res.size()) {
                    res = tmp;
                }
                tmp.clear();
                tmp.push_back(&i);
            }
        }
    }
    return res;
}

vector<Pai *> shunZi2(HandIn &hand) {
    vector<Pai *> res = {};
    vector<Pai *> tmp;
    for (auto &i : hand.cards) {
        if (i.suit >= 3 || i.suit == 1) {
            if (tmp.empty() ||
                (tmp.size() >= 2 && tmp.back()->suit == i.suit &&
                 tmp[tmp.size() - 2]->suit != tmp.back()->suit) ||
                (tmp.size() >= 2 && isNext(tmp.back(), &i) &&
                 tmp[tmp.size() - 2]->suit == i.suit) ||
                (tmp.size() == 1 && tmp.back()->suit == i.suit)) {
                tmp.push_back(&i);
            } else {
                if (tmp.size() >= 6 && tmp.size() > res.size()) {
                    res = tmp;
                }
                tmp.clear();
                tmp.push_back(&i);
            }
        }
    }
    return res;
}

vector<Pai *> shunZi3(HandIn &hand) {
    vector<Pai *> res = {};
    vector<Pai *> tmp;
    for (auto &i : hand.cards) {
        if (i.suit >= 3 || i.suit == 1) {
            if (tmp.empty() ||
                (tmp.size() >= 3 && tmp.back()->suit == i.suit &&
                 tmp[tmp.size() - 2]->suit == i.suit &&
                 isNext(tmp[tmp.size() - 3], &i)) ||

                (tmp.size() >= 3 && tmp.back()->suit == i.suit &&
                 isNext(tmp[tmp.size() - 2], &i)) ||

                (tmp.size() >= 3 && isNext(tmp.back(), &i)) ||

                (tmp.size() == 2 && tmp.back()->suit == i.suit) ||

                (tmp.size() == 1 && tmp.back()->suit == i.suit)) {
                tmp.push_back(&i);
            } else {
                if (tmp.size() >= 6 && tmp.size() > res.size()) {
                    res = tmp;
                }
                tmp.clear();
                tmp.push_back(&i);
            }
        }
    }
    return res;
}

vector<Pai *> rocket(HandIn &hand) {
    vector<Pai *> res = {};
    if (hand.nums[0] && hand.nums[1]) {
        for (auto &x : hand.cards) {
            if (x.suit == 0) {
                res.push_back(&x);
            }
        }
    }
    if (res.size() != 2) res.clear();
    return res;
}

vector<Pai *> bomb(HandIn &hand) {
    vector<Pai *> res = {};
    for (int i = 0; i <= 13; i++) {
        if (hand.nums[i] == 4) {
            for (auto &x : hand.cards) {
                if (x.suit == i) {
                    res.push_back(&x);
                }
            }
            break;
        }
    }
    return res;
}

vector<Pai *> doub(HandIn &hand) {
    vector<Pai *> res = {};
    for (int i = 0; i <= 13; i++) {
        if (hand.nums[i] == 2) {
            for (auto &x : hand.cards) {
                if (x.suit == i) {
                    res.push_back(&x);
                    if (res.size() == 2) break;
                }
            }
            break;
        }
    }
    return res;
}

vector<Pai *> tri(HandIn &hand) {
    vector<Pai *> res = {};
    for (int i = 0; i <= 13; i++) {
        if (hand.nums[i] == 3) {
            for (auto &x : hand.cards) {
                if (x.suit == i) {
                    res.push_back(&x);
                    if (res.size() == 3) break;
                }
            }
            break;
        }
    }
    return res;
}

vector<Pai *> (*methods[])(HandIn &) = {shunZi1, shunZi2, shunZi3, rocket,
                                        bomb,    doub,    tri};
vector<int> methodCount(7, 0);

void getBest(HandIn &hand, int &times) {
    vector<Pai *> best;
    int bestIdx = -1;
    for (int i = 0; i <= 6; ++i) {
        auto res = methods[i](hand);
        if (res.size() > best.size()) {
            best = res;
            bestIdx = i;
        }
    }
    if (bestIdx != -1) {
        methodCount[bestIdx]++;
        for (auto &x : best) {
            auto it = find(hand.cards.begin(), hand.cards.end(), *x);
            if (it != hand.cards.end()) {
                hand.cards.erase(it);
                hand.nums[x->suit]--;
            }
        }
        times++;
        getBest(hand, times);
    } else {
        return;
    }
}
int solve(HandIn &hand) {
    int times = 0;
    int canTake = 0;
    int lasting = hand.cards.size();

    getBest(hand, times);

    // 3with2
    if (lasting != 0) {
        int maxTakes = min(methodCount[6], methodCount[5]);
        lasting -= maxTakes * 2;
    }
    // 3with1 || 4with2
    if (lasting != 0) {
        int maxTakes = min((methodCount[4] * 2 + methodCount[6]), lasting);
        lasting -= maxTakes;
    }
    if (lasting > 0) {
        times += lasting;
    }
    return times;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream cin("in");

    int T, n;
    cin >> T >> n;
    while (T--) {
        vector<Pai> cards(n);
        vector<int> nums(15);
        for (auto &x : cards) {
            cin >> x.suit >> x.color;
        }
        sort(cards.begin(), cards.end());
        HandIn hand(cards, nums);
        int res = solve(hand);
        cout << res << "\n";
    }
    return 0;
}