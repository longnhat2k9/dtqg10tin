#include<bits/stdc++.h>
using namespace std;

const int mx = 1e5 + 5;
int n;
int a[mx];
int visited[mx];
int cnt[mx];

void dfs(int start) {
    vector<int> path;
    int current = start;
    
    while (visited[current] == 0) {
        visited[current] = 1;
        path.push_back(current);
        current = a[current];
    }

    if (cnt[current] > 0) {
        for (int i = path.size() - 1; i >= 0; i--) {
            cnt[path[i]] = cnt[a[path[i]]] + 1;
        }
        return;
    }

    int cyclest = -1;
    for (int i = 0; i < path.size(); i++) {
        if (path[i] == current) {
            cyclest = i;
            break;
        }
    }

    int sz = path.size() - cyclest;

    for (int i = cyclest; i < path.size(); i++) {
        cnt[path[i]] = sz;
    }
    
    for (int i = cyclest - 1; i >= 0; i--) {
        cnt[path[i]] = cnt[a[path[i]]] + 1;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    freopen("treat.inp", "r", stdin);
    freopen("treat.out", "w", stdout);
    
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    for (int i = 1; i <= n; i++) {
        if (visited[i] == 0) {
            dfs(i);
        }
        cout << cnt[i] << "\n";
    }
    
    return 0;
}