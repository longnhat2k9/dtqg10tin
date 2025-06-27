#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    freopen("bocsoi13.inp", "r", stdin);
    freopen("bocsoi13.out", "w", stdout);

    long long n; cin >> n;
    priority_queue<long long, vector<long long>, greater<long long>>pq;
    for(long long i = 0; i < n; i++)
    {
        long long x; cin >> x;
        pq.push(x);
    }

    long double money = 0;
    while(pq.size() > 1)
    {
        long long x = pq.top();
        pq.pop();
        pq.push(pq.top() + x);
        money += (pq.top() + x) * 0.05;
        pq.pop();
    }

    cout << fixed << setprecision(2) << money << endl;
}