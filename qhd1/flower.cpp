#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    freopen("flowers.inp", "r", stdin);
    freopen("flowers.out", "w", stdout);

    int n, delta; cin >> n >> delta;
    vector<pair<int, string>>a(n);
    for(int i = 0; i < n; i++)
    {
        int x; string y; cin >> x >> y;
        a[i] = make_pair(x, y);
    }
    sort(a.begin(), a.end());

    int cnt = 1, mx = 1;
    unordered_map<string, int>c;
    c[a[0].second]++;
    int l = 0;
    for(int i = 1; i < n; i++)
    {
        while(a[i].first - a[l].first > delta)
        {
            c[a[l].second]--;
            if(c[a[l].second] == 0) cnt--;
            l++;
        }
        c[a[i].second]++;
        if(c[a[i].second] == 1) cnt++;
        mx = max(mx, cnt);
    }
    cout << mx << endl;
}