#include<bits/stdc++.h>
using namespace std;

string s;
int a[10000][10000];
int mx = 1;
int cnt = 0;

void setup()
{
    if(s.size() == 0) 
    {
        cout << 0 << endl;
        cout << 0 << endl;
        exit(0);
    }

    memset(a, 0, sizeof(a));

    for(int i = 0; i < s.size(); i++)
    {
        a[i][i] = 1;
    }
    cnt = s.size();
}

void cs()
{
    for(int i = 0; i < s.size() - 1; i++)
    {
        a[i][i + 1] = (s[i] == s[i + 1]);
        if(a[i][i + 1] == 1 && mx != 2) mx = 2, cnt = 0;
        if(a[i][i + 1] == 1) cnt++;
    }

    for(int l = 3; l <= s.size(); l++)
    {
        for(int i = 0; i < s.size() - l + 1; i++)
        {
            if(s[i] == s[i + l - 1])
            {
                a[i][i + l - 1] = a[i + 1][i + l - 2];
                if(a[i][i + l - 1] == 1 && mx < l) mx = l, cnt = 1;
                else if(a[i][i + l - 1] == 1) cnt++;
            }
        }
    }

    cout << mx << endl;
    cout << cnt << endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    freopen("PALIND2.inp", "r", stdin);
    freopen("PALIND2.out", "w", stdout);

    cin >> s;
    setup();
    cs();

    return 0;
}