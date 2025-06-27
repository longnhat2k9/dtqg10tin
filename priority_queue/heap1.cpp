#include<bits/stdc++.h>
#include <queue>
using namespace std;

void cs()
{
    long long n; cin >> n;
    priority_queue<long long, vector<long long>, greater<long long>>pq;
    for(long long i = 0; i < n; i++)
    {
        long long x; cin >> x;
        pq.push(x);
    }
    long long money = 0;
    while(pq.size() > 1)
    {
        long long x = pq.top();
        pq.pop();
        money += x + pq.top();
        pq.push(x + pq.top());
        pq.pop();
    }
    cout << money << endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    freopen("heap1.inp", "r", stdin);
    freopen("heap1.out", "w", stdout);

    long long q; cin >> q;
    for(long long i = 0; i < q; i++) cs();

    return 0;
}