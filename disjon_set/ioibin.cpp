#include<bits/stdc++.h>
using namespace std;

const long long mx = 1e5 + 10;
long long n; 
long long lab[mx];
long long x, y, f;

long long findset(long long u)
{
	return lab[u] < 0 ? u : lab[u] = findset(lab[u]);
}

void cs1()
{
	long long r = findset(x), s = findset(y);

	if(r != s)
	{
		if (lab[s] < lab[r])
        	swap(r, s);
    	lab[r] += lab[s];
    	lab[s] = r;
	}
}

void cs2()
{
	long long r = findset(x), s = findset(y);

	if(r == s)
	{
		cout << 1 << endl;
	}
	else
	{
		cout << 0 << endl;
	}

}

int main() 
{
	ios_base::sync_with_stdio(0); cin.tie(0); 

	freopen("ioibin.inp", "r", stdin);
	freopen("ioibin.out", "w", stdout);

	memset(lab, -1, sizeof(lab));

	cin >> n;
	for(long long i = 0; i < n; i++)
	{
		cin >> x >> y >> f;
		if(f == 1)
		{
			cs1();
		}
		else
		{
			cs2();
		}
	}
}