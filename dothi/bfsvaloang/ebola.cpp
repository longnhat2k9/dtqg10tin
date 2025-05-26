/*
- De bai da cho danh sach ke ==> Nhap vao danh sach theo tung dong, so dau tien cua moi dong la so phan tu cua danh sach ke
- Khi bfs day 1 phan tu vao queue thi danh dau/ them vao vector phan tu do
- In ra size()/ tong so luong phan tu tim duoc va in ra cac phan tu cua no
*/

#include<bits/stdc++.h>
using namespace std;

int n, k;
const int MX = 1e6 + 10;
vector<int>a[MX];
vector<int>d(MX, 0);
queue<int>q;

void exp()
{
    int cnt = 0;
    for(int i = 1; i <= n; i++) cnt += d[i];
    cout << cnt << endl;
    for(int i = 1; i <= n; i++) 
    {
        if(d[i] == 1) cout << i << " ";
    }
    exit(0);
}

void bfs()
{
    while(q.size() != 0)
    {
        int x = q.front();
        for(int i = 0; i < a[x].size(); i++)
        {
            if(d[a[x][i]] == 0)
            {
                d[a[x][i]] = 1;
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
    
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        int m; cin >> m;
        for(int j = 0; j < m; j++)
        {
            int x; cin >> x;
            a[i].push_back(x);
        }
    }
    
    q.push(k);
    d[k] = 1;
    bfs();
    
    return 0;
}