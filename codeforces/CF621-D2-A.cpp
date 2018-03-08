#include<bits/stdc++.h>
#define	 clr(v,d)       memset(v,d,sizeof(v))
#define  lp(i,n)        for(int i=0; i<n; i++)
#define  rep(i,v)       for(int i=0; i<(int)v.size(); i++)
typedef  long long ll;
using namespace std;
void fast()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
}
ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
int main(){
	fast();
	ll n, a, s=0,mn=1e9;
	cin >> n;
	lp(i, n){
		cin >> a;
		s += a;
		if (a % 2)
			mn= min(mn, a);
	}
	if (s % 2)
		s -= mn;
		cout << s;

	//system("pause");
	return 0;
}