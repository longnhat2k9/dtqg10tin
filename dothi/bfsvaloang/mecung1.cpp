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

void exp(int rtnx, int rtny)
{
    vector<toado>ans;
    toado llm = toado(rtnx, rtny);
    ans.push_back(llm);
    while(d[llm.x][llm.y] != 1)
    {
        if(d[llm.x - 1][llm.y] == d[llm.x][llm.y] - 1)
        {
            ans.push_back(toado(llm.x - 1, llm.y));
            llm.x--;
        }
        else if(d[llm.x][llm.y - 1] == d[llm.x][llm.y] - 1)
        {
            ans.push_back(toado(llm.x, llm.y - 1));
            llm.y--;
        }
        else if(d[llm.x + 1][llm.y] == d[llm.x][llm.y] - 1)
        {
            ans.push_back(toado(llm.x + 1, llm.y));
            llm.x++;
        }        
        else if(d[llm.x][llm.y + 1] == d[llm.x][llm.y] - 1)
        {
            ans.push_back(toado(llm.x, llm.y + 1));
            llm.y++;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for(auto &vcl : ans)
    {
        cout << vcl.x << " " << vcl.y << endl;
    }
    exit(0);
}

void bfs()
{
    while(q.size() != 0)
    {
        toado res = q.front();
        
        if(a[res.x - 1][res.y] == 0 && d[res.x - 1][res.y] == 0)
        {
            d[res.x - 1][res.y] = d[res.x][res.y] + 1;
            q.push(toado(res.x - 1, res.y - 0));
            if(res.x - 1 == 1 || res.y == 1 || res.x - 1 == n || res.y == m) exp(res.x - 1, res.y);
        }
        
        if(a[res.x][res.y - 1] == 0 && d[res.x][res.y - 1] == 0)
        {
            d[res.x][res.y - 1] = d[res.x][res.y] + 1;
            q.push(toado(res.x - 0, res.y - 1));
            if(res.x == 1 || res.y - 1 == 1 || res.x == n || res.y - 1 == m) exp(res.x, res.y - 1);
        }
        
        if(a[res.x + 1][res.y] == 0 && d[res.x + 1][res.y] == 0)
        {
            d[res.x + 1][res.y] = d[res.x][res.y] + 1;
            q.push(toado(res.x + 1, res.y - 0));
            if(res.x + 1 == 1 || res.y == 1 || res.x + 1 == n || res.y == m) exp(res.x + 1, res.y);
        }
        
        if(a[res.x][res.y + 1] == 0 && d[res.x][res.y + 1] == 0)
        {
            d[res.x][res.y + 1] = d[res.x][res.y] + 1;
            q.push(toado(res.x - 0, res.y + 1));
            if(res.x == 1 || res.y + 1 == 1 || res.x == n || res.y + 1 == m) exp(res.x, res.y + 1);
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
    freopen("MECUNG.inp", "r", stdin);
    freopen("MECUNG.out", "w", stdout);
    
    memset(a, 1, sizeof(a));
    
    cin >> n >> m;
    cin >> stx >> sty;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
    
    q.push(toado(stx, sty));
    d[stx][sty] = 1;
    
    if(stx == 1 || sty == 1 || stx == n || sty == m) 
    {
        cout << 1 << endl;
        cout << stx << " " << sty << endl;
        
        return 0;
    }
    
    bfs();
    
    cout << 0 << endl;
    
    // for(int i = 0; i < t; i++) cs();
    
    return 0;

}