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
int lef[1000005], rigt[1000005];
int main(){
	fast();
	int n;
	cin >> n;
	while (n){
		string s;
		cin >> s;
		clr(rigt, 0);
		clr(lef, 0);
		lef[0] = rigt[n - 1] = 1e8;
		lp(i, n){
			if (i)
				lef[i] += lef[i - 1]+1;
			if (s[i] == 'Z' || s[i] == 'R')
				lef[i] = 0;
		}
		for(int i=n-1; i>=0; i--){
				rigt[i] += rigt[i + 1]+1;
			if (s[i] == 'Z' || s[i] == 'R')
				rigt[i] = 0;
		}
		int mx = 1e9;
		lp(i,n)
		if (s[i] == 'Z' || s[i] == 'D'){
			mx = min(mx, min(lef[i], rigt[i]));
		}
		cout << mx<<endl;
		cin >> n;
	}
	//system("pause");
	return 0;
}