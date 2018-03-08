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
ll a[100005], s[100005];
int main(){
	fast();
	int n;
	cin >> n;
	
	lp(i, n)
		cin >> a[i],s[i]=a[i];
	sort(s, s + n);
	for (int i = 1; i < n; i++){
		a[i] += a[i - 1];
		s[i] += s[i - 1];
	}
	int m;
	cin >> m;
	while (m--){
		int r, l, f;
		ll sum = 0;
		cin >> f >> l >> r;
		r--;
		l--;
		if (f == 1){
			sum = a[r];
			if (l)
				sum -= a[l - 1];
		}
		else {
			sum = s[r];
			if (l)
				sum -= s[l - 1];
		}
		cout << sum << endl;
	}
//	system("pause");
	return 0;
}