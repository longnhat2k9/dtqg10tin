#include<bits/stdc++.h>
using namespace std;

int n, m;
const int mx = 1e6 + 10;
vector<int>a[mx];
queue<int>q;
vector<int>d(mx, -1);
int st = 1, nd;

/*
Danh sach ke
1: 2, 3
2: 3, 4
3: 1, 5, 7
4: 6
5:
6: 2, 8
7: 8, 6
8:
Danh sach ke ===> Oke
----
Queue:

----
Danh dau:
Node    1   2   3   4   5   6   7   8
Parent  0   1   1   2   3   4   3   7
*/

void exp()
{
    int cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        if(d[i] != -1) cnt++;
    }
    cout << cnt << endl;
    exit(0);
}

void bfs()
{
    while(q.size() != 0)
    {
        int x = q.front();
        for(int i = 0; i < a[x].size(); i++)
        {
            if(d[a[x][i]] == -1)
            {
                d[a[x][i]] = x;
                q.push(a[x][i]);
            }
        }
        q.pop();
    }
    exp();
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    // freopen("dt.inp", "r", stdin);
    // freopen("dt.out", "w", stdout);

    cin >> n >> m >> st;

    for(int i = 1; i <= m; i++)
    {
        int x, y; cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    
    for(int i = 1; i <= n; i++)
    {
        sort(a[i].begin(), a[i].end());
    }

    d[st] = 0; q.push(st);
    bfs();

    return 0;
}