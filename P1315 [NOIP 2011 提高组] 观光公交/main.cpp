#include <algorithm>
#include <vector>

#include "bits/stdc++.h"
using namespace std;

#define DEBUG
#ifdef DEBUG
#define dbg(x) cout << __LINE__ << ":" #x << " = " << x << "\n"
#else
#define dbg(x)
#endif

struct Person {
    int t, a, b;
    bool operator<(const Person &other) const { return t < other.t; }
    Person(int t = 0, int a = 0, int b = 0) : t(t), a(a), b(b) {}
};

struct Plece {
    int arrive;
    int people;
    int totalTime;
    Plece(int arrive = 0, int people = 0, int totalTime = 0)
        : arrive(arrive), people(people), totalTime(totalTime) {}
};
int maxPeopleIndex(vector<Plece> &places) {
    int index = 0;
    int maxPeople = 0;
    for (int i = 0; i < places.size(); i++) {
        if (places[i].people > maxPeople) {
            maxPeople = places[i].people;
            index = i;
        }
    }
    return index;
}

void getPlacePerson(vector<Plece> &places, vector<Person> &person) {
    int n = places.size() - 1;
    int m = person.size();
    int curPlace = 1;
    for (int i = 0; i < m; i++) {
        curPlace = max(curPlace, person[i].a);
        for (int j = 1; j < n; j++) {
            if (person[i].a <= j && person[i].b >= j + 1) {
                places[j].people++;
            }
        }
    }
}

int solve(int n, int m, int k, vector<int> &d, vector<Person> &persons) {
    sort(persons.begin(), persons.end());
    vector<Plece> places(n + 1);
    for (int i = 1; i <= n; i++) {
        places[i] = Plece(places[i - 1].arrive + d[i - 1], 0);
    }
    getPlacePerson(places, persons);
    for (int i = 1; i <= n; i++) {
        places[i].totalTime += places[i].people * d[i - 1];
    }
    while (k--) {
        int index = maxPeopleIndex(places);
        places[index].totalTime -= places[index].people * 1;
    }
    int totalTime1 = 0;
    for (auto &place : places) {
        totalTime1 += place.totalTime;
    }
    return totalTime1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ifstream cin("in");
    // ofstream cout("out");

    int n, m, k;
    cin >> n >> m >> k;
    vector<int> d(n);
    for (int i = 1; i < n; i++) {
        cin >> d[i];
    }
    vector<Person> persons(m);
    for (auto &p : persons) {
        cin >> p.t >> p.a >> p.b;
    }

    int ans = solve(n, m, k, d, persons);
    cout << ans << "\n";

    return 0;
}
