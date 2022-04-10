#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll MAX = 1e5 + 10;
ll dist[MAX];
ll parent[MAX];
set<pair<ll, ll>> ss;
vector<pair<ll, ll>> adj[MAX];

void dijkstra(int start) {
    dist[start] = 0;
    parent[start] = 0;
    ss.insert({0, start});
    while (!ss.empty()) {
        ll u = ss.begin()->second;
        ss.erase(ss.begin());
        for (auto v : adj[u]) {
            if (dist[v.first] > dist[u] + v.second) {
                ss.erase({dist[v.first], v.first});
                dist[v.first] = dist[u] + v.second;
                ss.insert({dist[v.first], v.first});
                parent[v.first] = u;
            }
        }
    }
}

void print(int end) {
    stack<ll> stc;
    ll ind = end;
    do {
        stc.push(ind);
        ind = parent[ind];
    } while (parent[ind] != ind);
    stc.push(ind);
    while (!stc.empty()) {
        cout << stc.top() + 1 << ' ';
        stc.pop();
    }
    cout << endl;
}

int main() {
    ll n, m;
    cin >> n >> m;
    for (ll i = 0; i < n; ++i) {
        dist[i] = LONG_LONG_MAX;
    }
    for (ll i = 0; i < m; ++i) {
        ll w, a, b;
        cin >> a >> b >> w;
        a--;b--;
        adj[a].emplace_back(b, w);
        adj[b].emplace_back(a, w);
    }
    dijkstra(0);
    if (dist[n - 1] == LONG_LONG_MAX) {
        cout << -1 << endl;
    }
    else {
        print(n - 1);
    }
}
