/*
- Setup cac o duong di la 1, con lai la 0. Danh dau tren mang do cac vi tri da tham.
- Duyet trau cac o de tim o trong cac o thi o nao bang 0 goi toi ham bfs
- Moi lan goi bien dem tang 1
*/

#include<bits/stdc++.h>
using namespace std;

struct toado
{
    int x, y;
    toado(int vaicalin, int ditconme) : x(vaicalin), y(ditconme) {};
};

const int MX = 1e3 + 10;
int m, n, k;
int a[MX][MX];
int cnt = 0;
queue<toado>q;

void setup()
{
    memset(a, 0, sizeof(a));
    cin >> m >> n >> k;
    for(int l = 0; l < k; l++)
    {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        for(int i = x1; i <= x2; i++)
        {
            for(int j = y1; j <= y2; j++)
            {
                a[i][j] = 1;
            }
        }
    }
}

void bfs()
{
    while(q.size() != 0)
    {
        toado res = q.front();

        if(a[res.x + 1][res.y] == 0 && res.x + 1 <= m)
        {
            a[res.x + 1][res.y] = 1;
            q.push(toado(res.x + 1, res.y));
        }

        if(a[res.x][res.y + 1] == 0 && res.y + 1 <= n)
        {
            a[res.x][res.y + 1] = 1;
            q.push(toado(res.x, res.y + 1));
        }

        if(a[res.x - 1][res.y] == 0 && res.x - 1 > 0)
        {
            a[res.x - 1][res.y] = 1;
            q.push(toado(res.x - 1, res.y));
        }

        if(a[res.x][res.y - 1] == 0 && res.y - 1 > 0)
        {
            a[res.x][res.y - 1] = 1;
            q.push(toado(res.x, res.y - 1));
        }

        q.pop();
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("SOVUNG.inp", "r", stdin);
    freopen("SOVUNG.out", "w", stdout);

    setup();
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(a[i][j] == 0)
            {
                cnt++;
                q.push(toado(i, j));
                bfs();
            }
        }
    }

    cout << cnt << endl;
    return 0;
}