#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    freopen("partition.inp", "r", stdin);
    freopen("partition.out", "w", stdout);

    long long n, l; cin >> l >> n;
    priority_queue<long long, vector<long long>, greater<long long>>pq;
    long long sum = 0;
    for(long long i = 0; i < n; i++)
    {
        long long x; cin >> x;
        pq.push(x);
        sum += x;
    }
    if(sum != l)
    {
        pq.push(l - sum);
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