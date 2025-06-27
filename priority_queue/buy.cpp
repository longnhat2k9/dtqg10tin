#include<bits/stdc++.h>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    freopen("buy.inp", "r", stdin);
    freopen("buy.out", "w", stdout);
    
    long long m, n; cin >> m >> n;
    long long money = 0;
    vector<long long>a(n, 0);
    priority_queue<pair<long long, pair<long long, long long>>, vector<pair<long long, pair<long long, long long>>>, greater<pair<long long, pair<long long, long long>>>> pq;
    for(long long i = 0; i < n; i++)
    {
        long long x, y; cin >> x >> y;
        pq.push(make_pair(y, make_pair(x, i)));
    }

    while(pq.size() != 0)
    {
        pair<long long, pair<long long, long long>> x = pq.top();
        // cout << x.first << " " << x.second.first << " " << x.second.second << " "  << m << endl;
        if(x.second.first <= m)
        {
            m -= x.second.first; // cout << m << endl;
            a[x.second.second] = x.second.first;
            money += x.first * x.second.first;
            pq.pop();
        }
        else
        {
            a[x.second.second] = m;
            money += m * x.first;
            m = 0;
            break;
        }
    }

    cout << money << endl;
    for(long long i = 0; i < n; i++)
    {
        cout << a[i] << endl;
    }
}