#include "bits/stdc++.h"
using namespace std;
using ll = long long;

struct Car {
    int d, v, a;
};

struct Area {
    int start, end;
    bool operator()(int place) const {
        return start <= place && place <= end;
    }
};

bool overSpeed(Car car, int place, int V) {
    if (place < car.d) {
        return false;
    }
    int v = sqrt(car.v * car.v + 2 * car.a * (place - car.d));
    return v >= V;
}

Area getOverSpeedArea(Car car, int V) {
    if (car.a == 0) {
        if (car.v >= V) {
            return {0, INT_MAX};
        } else {
            return {-1, -1};
        }
    } else if (car.a > 0) {
        int d = (V * V - car.v * car.v) / (2 * car.a);
        if (d < 0) {
            return {-1, -1};
        } else {
            return {car.d + d, INT_MAX};
        }
    } else {
        if (car.v < V) {
            return {-1, -1};
        } else {
            int d = (car.v * car.v - V * V) / (2 * car.a);

            return {car.d, car.d + d};
        }
    }
}

vector<Area> getOverSpeedAreas(const vector<Car>& cars, int V) {
    vector<Area> areas;
    for (const auto& car : cars) {
        Area area = getOverSpeedArea(car, V);
        if (area.start != -1) {
            areas.push_back(area);
        }
    }
    return areas;
}

vector<vector<int>> gotByMs(const vector<int>& mm, const vector<Area>& areas) {
    vector<vector<int>> got(areas.size());
    for(int i = 0; i < areas.size(); ++i) {
        for(int j = 0; j < mm.size(); ++j) {
            if(areas[i](mm[j])) {
                got[i].push_back(j);
            }
        }
    }
    return got;
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ifstream fin("in");
    cin.rdbuf(fin.rdbuf());

    int T;
    cin >> T;
    while (T--) {
        int n, m, L, V;
        cin >> n >> m >> L >> V;
        vector<Car> cars(n);
        vector<int> mm(m);
        for (auto& car : cars) {
            cin >> car.d >> car.v >> car.a;
        }
        for (int& i : mm) {
            cin >> i;
        }
        sort(mm.begin(), mm.end());
        int overSpeedCount = 0;
        for (int i = 0; i < n; ++i) {
            if (overSpeed(cars[i], L, V)) {
                overSpeedCount++;
            }
        }
        cout << overSpeedCount << '\n';
    }
    return 0;
}