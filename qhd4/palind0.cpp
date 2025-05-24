#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int MAXN = 1000; 

int n;
bool dp[MAXN][MAXN]; 
int start, maxLen; 
string s;

void longestPalindrome() {
    if (n == 0) {
        cout << 0;
        return;
    }

    for (int i = 0; i < n; ++i) {
        dp[i][i] = true;
    }

    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = true;
        }
    }

    for (int len = 3; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1; 
            if (s[i] == s[j] && dp[i + 1][j - 1]) {
                dp[i][j] = true;
            }
        }
    }

    start = 0;
    maxLen = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if (dp[i][j] && (j - i + 1) > maxLen) {
                start = i;
                maxLen = j - i + 1;
            }
        }
    }
    cout << maxLen << endl;
}

int main() {
    freopen("Palind0.inp", "r", stdin);
    freopen("Palind0.out", "w", stdout);

    getline(cin, s);
    n = s.length();

    longestPalindrome();

    return 0;
}