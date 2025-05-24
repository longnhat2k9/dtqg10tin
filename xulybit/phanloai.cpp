#include<bits/stdc++.h>
using namespace std;

/*
    n hang
    m cot
    [hang]
*/

const vector<char>dna = {'A', 'T', 'G', 'C'};

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    freopen("CLASSIFY.inp", "r", stdin);
    freopen("CLASSIFY.out", "w", stdout);
    
    int n, m, cnt = 0; cin >> n >> m;
    vector<string>a(n), b(n); cin.ignore();
    for(int i = 0; i < n; i++) getline(cin, a[i]);
    for(int i = 0; i < n; i++) getline(cin, b[i]);

    for(int i = 0; i < m; i++)
    {
        unordered_map<char, int>c, d;
        for(int j = 0; j < n; j++)
        {
            c[a[j][i]] = 1;
            d[b[j][i]] = 1;
        }
        bool ck = true;
        for(auto x : dna)
        {
            if(c[x] == 1 && d[x] == 1) 
            {
                ck = false;
                break;
            }
        }
        cnt += ck;
    }

    cout << cnt << endl;

    return 0;
}