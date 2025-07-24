#include<bits/stdc++.h>
using namespace std;

const long long INF = 1e18;
long long m, n, q; 
char a[1010][1010];
long long price[1010][1010];
priority_queue<pair<long long, pair<long long, long long>>, 
                vector<pair<long long, pair<long long, long long>>>, 
                greater<pair<long long, pair<long long, long long>>>> pq;

void bfs() {
    while(!pq.empty()) {
        long long k = pq.top().first;
        long long x = pq.top().second.first;
        long long y = pq.top().second.second;
        pq.pop();
        
        if (k > price[x][y]) continue;
        
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        
        for (int i = 0; i < 4; i++) {
            long long nx = x + dx[i];
            long long ny = y + dy[i];
            
            if (nx < 1 || nx > m || ny < 1 || ny > n) continue;
            
            long long new_cost = k;
            if (a[x][y] != a[nx][ny]) {
                new_cost += 1;
            }
            
            if (new_cost < price[nx][ny]) {
                price[nx][ny] = new_cost;
                pq.push({new_cost, {nx, ny}});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    freopen("pathgame.inp", "r", stdin);
    freopen("pathgame.out", "w", stdout);

    cin >> m >> n >> q;
    
    for (long long i = 1; i <= m; i++) {
        for (long long j = 1; j <= n; j++) {
            price[i][j] = INF;
        }
    }
    
    for (long long i = 1; i <= m; i++) {
        for (long long j = 1; j <= n; j++) {
            cin >> a[i][j];
            if (a[i][j] == '*') {
                price[i][j] = 0;
                pq.push({0, {i, j}});
            }
        }
    }
    
    bfs();

    while (q--) {
        long long x, y; 
        cin >> x >> y;
        cout << price[x][y] << endl;
    }
    
    return 0;
}