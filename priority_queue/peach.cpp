#include<bits/stdc++.h>
using namespace std;

struct P {
    long long t;
    int k;

    bool operator<(const P& o) const {
        return t < o.t;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("peach.inp", "r", stdin);
    freopen("peach.out", "w", stdout);

    int n;
    long long a, b;
    cin >> n >> a >> b;

    vector<P> ps(n);
    for (int i = 0; i < n; i++) {
        cin >> ps[i].t >> ps[i].k;
    }

    sort(ps.begin(), ps.end());

    priority_queue<int> pq;
    long long s = 0;
    int i = 0;
    long long c = a;

    while (c < b) {
        while (i < n && ps[i].t <= c) {
            if (ps[i].t < b) {
                pq.push(ps[i].k);
            }
            i++;
        }

        if (!pq.empty()) {
            s += pq.top();
            pq.pop();
            c++;
        } else {
            if (i < n) {
                c = max(c + 1, ps[i].t);
                if (c >= b) {
                    break;
                }
            } else {
                break;
            }
        }
    }

    cout << s << endl;

    return 0;
}