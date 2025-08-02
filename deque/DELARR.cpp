#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("DELARR.INP", "r", stdin);
    freopen("DELARR.OUT", "w", stdout);
    long long n; cin >> n;
    deque<long long>q;
    long long sum = 0;
    for(long long i = 0; i < n; i++)
    {
        long long x; cin >> x;
        sum += x;
        q.push_back(x);
    }
    sort(q.begin(), q.end());
    while(sum != 0 && !q.empty())
    {
        if(sum > 0)
        {
            sum -= q.back();
            q.pop_back();
        }
        else
        {
            sum -= q.front();
            q.pop_front();
        }
    }
    cout << n - q.size();
}