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
	int m;
	cin >> m;
	while (m--){
 
		int n;
		ll mx;
		cin >> n >> mx;
		int a[22];
		lp(i, n)
			cin >> a[i];
		int f = 0;
		for (int t = 0; t < (1 << n); t++){
			ll sum = 0;
			lp(i, n)if (t&(1 << i)){
				sum += a[i];
			}
			if (sum == mx)
				f = 1;
		}
		if (f)
			cout << "Yes" << endl;
		else cout << "No" << endl;
 
	}
	//system("pause");
	return 0;
} 