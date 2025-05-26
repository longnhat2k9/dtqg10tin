/*
- Chuong luon o (1,1) ==> Tim duong di ngan nhat tu C(x, y) toi o (1,1)
- Chuyen . sang 0, * sang 1. 0 la co, 1 la da
- BFS
*/

/*
5 6
B...*.
..*...
.**.*.
..***.
*..*.C

---
9
*/

#include<bits/stdc++.h>
using namespace std;

struct toado
{
    int x, y;
    toado(int k, int h) : x(k), y(h) {};
};

int r, c;
int stx, sty;
const int MX = 1e2 + 10;
int a[MX][MX];
int d[MX][MX];
queue<toado>q;

void exp()
{
    cout << d[1][1] << endl;
    exit(0);
}

void bfs()
{
    while(q.size() != 0)
    {
        toado res = q.front();
        
        // cout << "Node: " << res.x << " " << res.y << endl; // log
        
        // cout << "Check " <<  res.x + 1 << " " << res.y << endl; // log
        if(d[res.x + 1][res.y] == -1 && a[res.x + 1][res.y] == 0)
        {
            d[res.x + 1][res.y] = d[res.x][res.y] + 1;
            q.push(toado(res.x + 1, res.y));
            
            if(res.x + 1 == 1 && res.y == 1) exp();
            
            // cout << "Push " <<  res.x + 1 << " " << res.y << endl; // log
        }
        
        // cout << "Check " <<  res.x << " " << res.y + 1 << endl; // log
        if(d[res.x][res.y + 1] == -1 && a[res.x][res.y + 1] == 0)
        {
            d[res.x][res.y + 1] = d[res.x][res.y] + 1;
            q.push(toado(res.x, res.y + 1));
            
            if(res.x == 1 && res.y + 1 == 1) exp();
            
            // cout << "Push " <<  res.x << " " << res.y + 1 << endl; // log
        }
        
        // cout << "Check " <<  res.x - 1 << " " << res.y << endl; // log
        if(d[res.x - 1][res.y] == -1 && a[res.x - 1][res.y] == 0)
        {
            d[res.x - 1][res.y] = d[res.x][res.y] + 1;
            q.push(toado(res.x - 1, res.y));
            
            if(res.x - 1 == 1 && res.y == 1) exp();
            
            // cout << "Push " <<  res.x - 1 << " " << res.y << endl; // log
        }
        
        // cout << "Check " <<  res.x << " " << res.y - 1 << endl; // log
        if(d[res.x][res.y - 1] == -1 && a[res.x][res.y - 1] == 0)
        {
            d[res.x][res.y - 1] = d[res.x][res.y] + 1;
            q.push(toado(res.x, res.y - 1));
            
            if(res.x == 1 && res.y - 1 == 1) exp();
            
            // cout << "Push " <<  res.x << " " << res.y - 1 << endl; // log
        }
        
        /*
        // log
    
        for(int i = 1; i <= r; i++)
        {
            for(int j = 1; j <= c; j++)
            {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
        
        for(int i = 1; i <= r; i++)
        {
            for(int j = 1; j <= c; j++)
            {
                cout << d[i][j] << " ";
            }
            cout << endl;
        }
        */
        
        q.pop();
    }
    
    cout << "zero" << endl;
    exit(0);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen("dt.inp", "r", stdin);
    // freopen("dt.out", "w", stdout);

    memset(d, -1, sizeof(d));
    memset(a, 1, sizeof(d));

    cin >> r >> c;
    for(int i = 1; i <= r; i++)
    {
        for(int j = 1; j <= c; j++)
        {
            char vcl; cin >> vcl;
            // cout << vcl << endl; //log
            if(vcl == '.') a[i][j] = 0;
            else if(vcl == '*') a[i][j] = 1;
            else if(vcl == 'C') a[i][j] = 0, stx = i, sty = j;
            else a[i][j] = 0;
        }
    }
    
    /*
    // log
    
    for(int i = 1; i <= r; i++)
    {
        for(int j = 1; j <= c; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    
    for(int i = 1; i <= r; i++)
    {
        for(int j = 1; j <= c; j++)
        {
            cout << d[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << stx << " " << sty << endl; // log
    */
    
    q.push(toado(stx, sty));
    d[stx][sty] = 0;
    
    bfs();
    
    return 0;
}