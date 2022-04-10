#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAX = 100005;
int parent[MAX];
int ran[MAX];

int find(int x) {
    return (parent[x] == x ? x : parent[x] = find(parent[x]));
}

void uni(int a, int b) {
    int pa = find(a);
    int pb = find(b);
    if (pa != pb) {
        if (ran[pa] > ran[pb]) {
            parent[pb] = pa;
        }
        else if (ran[pa] < ran[pb]) {
            parent[pa] = pb;
        }
        else {
            parent[pa] = pb;
            ran[pb]++;
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, pair<int, int>>> vc;

    for (int i = 0; i < n; ++i) {
        parent[i] = i;
        ran[i] = i;
        for (int j = 0; j < n; ++j) {
            int t;
            cin >> t;
            if (i > j) {
                vc.push_back({t, {i, j}});
            }
        }
    }

    sort(vc.begin(), vc.end());

}
//this line is added