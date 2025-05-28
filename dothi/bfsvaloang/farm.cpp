/*
- Setup:
+ Ga(c) = 1
+ Cao(f) = 2
+ Vuon(.) = 0
+ Rao(#) = -1
+ Dem tong ga, tong Cao

- BFS:
+ Dung lai bai dem vung, moi vung dem so ga, so Cao
+ Neu ga > cao thi tong cao -= cao nguoc lai thi tong ga -= ga

- Xuat:
cout << tong cao << " " << tong ga << endl;
*/

#include<bits/stdc++.h>
using namespace std;

const int MX = 1e3 + 10;
int m, n;
int tongcao = 0, tongga = 0;
int a[MX][MX];
struct toado
{
    int x, y;
    toado(int vaicalin, int ditconme) : x(vaicalin), y(ditconme) {};
};
queue<toado>q;

void setup()
{
    cin >> m >> n;
    memset(a, 0, sizeof(a));
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            char me; cin >> me;
            if(me == 'c') a[i][j] = 1, tongga++;
            else if(me == 'f') a[i][j] = 2, tongcao++;
            else if(me == '.') a[i][j] = 0;
            else a[i][j] = -1;
        }
    }

    // log
    // for(int i = 1; i <= m; i++)
    // {
    //     for(int j = 1; j <= n; j++)
    //     {
    //         cout << a[i][j] << " ";
    //     }
    //     cout << endl;
    // }
}

void bfs()
{
    int ga = 0, cao = 0;
    while(q.size() != 0)
    {
        toado res = q.front();

        if(res.x + 1 <= m && a[res.x + 1][res.y] >= 0)
        {
            if(a[res.x + 1][res.y] == 1) ga++;
            if(a[res.x + 1][res.y] == 2) cao++;
            a[res.x + 1][res.y] = -1;
            q.push(toado(res.x + 1, res.y));
        }

        if(res.y + 1 <= n && a[res.x][res.y + 1] >= 0)
        {
            if(a[res.x][res.y + 1] == 1) ga++;
            if(a[res.x][res.y + 1] == 2) cao++;
            a[res.x][res.y + 1] = -1;
            q.push(toado(res.x, res.y + 1));
        }

        if(res.x - 1 > 0 && a[res.x - 1][res.y] >= 0)
        {
            if(a[res.x - 1][res.y] == 1) ga++;
            if(a[res.x - 1][res.y] == 2) cao++;
            a[res.x - 1][res.y] = -1;
            q.push(toado(res.x - 1, res.y));
        }

        if(res.y - 1 > 0 && a[res.x][res.y - 1] >= 0)
        {
            if(a[res.x][res.y - 1] == 1) ga++;
            if(a[res.x][res.y - 1] == 2) cao++;
            a[res.x][res.y - 1] = -1;
            q.push(toado(res.x, res.y - 1));
        }

        q.pop();
    }

    if(ga > cao) tongcao -= cao;
    else tongga -= ga;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("FARM.inp", "r", stdin);
    freopen("FARM.out", "w", stdout);

    setup();
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(a[i][j] >= 0)
            {
                q.push(toado(i, j));
                bfs();
            }
        }
    }

    cout << tongcao << " " << tongga << endl;

    return 0;
}