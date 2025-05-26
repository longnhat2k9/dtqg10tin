#include<bits/stdc++.h>
using namespace std;

int n, m, t; // n row, m col
const int MX = 1e3 + 10;
int a[MX][MX];
int d[MX][MX];
int stx, sty;

struct toado
{
    int x; 
    int y;
    
    toado(int k, int h) : x(k), y(h) {};
};
    
queue<toado>q;

void bfs()
{
    while(q.size() != 0)
    {
        toado res = q.front();
        
        if(a[res.x - 1][res.y] == 0 && d[res.x - 1][res.y] == 0)
        {
            d[res.x - 1][res.y] = 1;
            q.push(toado(res.x - 1, res.y - 0));
        }
        
        if(a[res.x][res.y - 1] == 0 && d[res.x][res.y - 1] == 0)
        {
            d[res.x][res.y - 1] = 1;
            q.push(toado(res.x - 0, res.y - 1));
        }
        
        if(a[res.x + 1][res.y] == 0 && d[res.x + 1][res.y] == 0)
        {
            d[res.x + 1][res.y] = 1;
            q.push(toado(res.x + 1, res.y - 0));
        }
        
        if(a[res.x][res.y + 1] == 0 && d[res.x][res.y + 1] == 0)
        {
            d[res.x][res.y + 1] = 1;
            q.push(toado(res.x - 0, res.y + 1));
        }
        
        q.pop();
    }
}

void cs()
{
    int x, y; cin >> x >> y;
    cout << d[x][y] << endl;
}    

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("MECUNG0.inp", "r", stdin);
    freopen("MECUNG0.out", "w", stdout);
    
    memset(a, 1, sizeof(a));
    
    cin >> n >> m >> t;
    cin >> stx >> sty;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
    
    q.push(toado(stx, sty));
    
    bfs();
    
    for(int i = 0; i < t; i++) cs();
    
    return 0;

}