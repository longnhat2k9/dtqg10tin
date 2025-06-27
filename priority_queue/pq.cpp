#include<bits/stdc++.h>
using namespace std;

/*Fixed Bugs - Wait to OJ (OJ Host is down)*/
/*
Logs 1 - (PQ.cpp - WA)
Bugs: 
- Loop if number add to queue not the max number
- Can't pop all the number loop if it is the max number 
- Can't print 1 time per number because of the loop number (also the max or not the max)

Logs 2 - (PQ.cpp - WA)
Bugs:
- Reset the d[pq.top()] before pop
*/

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    freopen("pq.inp", "r", stdin);
    freopen("pq.out", "w", stdout);

    long long n; cin >> n; cin.ignore();

    priority_queue<long long>pq;
    unordered_map<long long, long long> d;

    for(long long i = 0; i < n; i++)
    {
        string s;
        getline(cin, s);

        if(s == "-")
        {
            if(pq.size() != 0) 
            {
                d[pq.top()] = 0;
                pq.pop();
            }
        }
        else
        {
            s.erase(s.begin());
            if(d[stoll(s)] == 0)
            {
                d[stoll(s)] = 1;
                pq.push(stoll(s));
            }
        }
    }

    cout << pq.size() << endl;
    while(pq.size() > 0)
    {
        cout << pq.top() << " ";
        pq.pop();
    }
}