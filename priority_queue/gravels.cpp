#include<bits/stdc++.h>
using namespace std;

void print128(__int128 x) {
    if(x == 0) {
        cout << "0";
        return;
    }
    string result = "";
    while(x > 0) {
        result = char('0' + x % 10) + result;
        x /= 10;
    }
    cout << result;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    freopen("gravels.inp", "r", stdin);
    freopen("gravels.out", "w", stdout);
    
    int n;
    cin >> n;
    
    vector<long long> a(n);
    __int128 total = 0;
    
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        total += a[i];
    }
    
    __int128 k = total / n;
    
    __int128 cost = 0;
    __int128 carry = 0;
    
    for(int i = 0; i < n - 1; i++) {
        carry += a[i] - k;
        cost += (carry < 0) ? -carry : carry;  // abs(carry)
    }
    
    print128(cost);
    cout << "\n";
    
    return 0;
}