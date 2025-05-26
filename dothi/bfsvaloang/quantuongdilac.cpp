/*
- Memset a = 0
- BFS
- Neu khong gap ndx, ndy va queue = 0 ==> -1
*/

/*
3 5 7 5

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
int ndx, ndy;
const int MX = 1e2 + 10;
int a[MX][MX];
int d[MX][MX];
queue<toado>q;

void exp()
{
    cout << d[ndx][ndy] << endl;
    exit(0);
}

void bfs()
{
    while(q.size() != 0)
    {
        toado res = q.front();
        
        // cout << "Node: " << res.x << " " << res.y << endl; // log
        
        // cout << "Check " <<  res.x + 2 << " " << res.y - 2 << endl; // log
        if(d[res.x + 2][res.y - 2] == -1 && a[res.x + 2][res.y - 2] == 0)
        {
            d[res.x + 2][res.y - 2] = d[res.x][res.y] + 1;
            q.push(toado(res.x + 2, res.y - 2));
            
            if(res.x + 2 == ndx && res.y - 2 == ndy) exp();
            
            // cout << "Push " <<  res.x + 2 << " " << res.y - 2 << endl; // log
        }
        
        // cout << "Check " <<  res.x - 2 << " " << res.y + 2 << endl; // log
        if(d[res.x - 2][res.y + 2] == -1 && a[res.x - 2][res.y + 2] == 0)
        {
            d[res.x - 2][res.y + 2] = d[res.x][res.y] + 1;
            q.push(toado(res.x - 2, res.y + 2));
            
            if(res.x - 2 == ndx && res.y + 2 == ndy) exp();
            
            // cout << "Push " <<  res.x - 2 << " " << res.y + 2 << endl; // log
        }
        
        // cout << "Check " <<  res.x - 2 << " " << res.y - 2<< endl; // log
        if(d[res.x - 2][res.y - 2] == -1 && a[res.x - 2][res.y - 2] == 0)
        {
            d[res.x - 2][res.y - 2] = d[res.x][res.y] + 1;
            q.push(toado(res.x - 2, res.y - 2));
            
            if(res.x - 2 == ndx && res.y - 2 == ndy) exp();
            
            // cout << "Push " <<  res.x - 2 << " " << res.y - 2 << endl; // log
        }
        
        // cout << "Check " <<  res.x + 2 << " " << res.y + 2 << endl; // log
        if(d[res.x + 2][res.y + 2] == -1 && a[res.x + 2][res.y + 2] == 0)
        {
            d[res.x + 2][res.y + 2] = d[res.x][res.y] + 1; 
            q.push(toado(res.x + 2, res.y + 2));
            
            if(res.x + 2 == ndx && res.y + 2 == ndy) exp();
            
            // cout << "Push " <<  res.x + 2 << " " << res.y + 2 << endl; // log
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
    
    // cout << "END" << endl;
    cout << -1 << endl;
    exit(0);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen("dt.inp", "r", stdin);
    // freopen("dt.out", "w", stdout);

    memset(d, -1, sizeof(d));
    memset(a, 0, sizeof(d));
    r = 8, c = 8;
    cin >> stx >> sty >> ndx >> ndy;
    /*
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
    */
    
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