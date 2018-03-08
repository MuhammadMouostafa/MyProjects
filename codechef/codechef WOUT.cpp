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
int a[1000005];
int main(){
	fast();
	int t;
	cin >> t;
	while (t--){
		int n, m;
		cin >> n >> m;
		clr(a, 0);
		lp(i, n){
			int l, r;
			cin >> l >> r;
			a[0]++;
			a[l]--;
			a[r + 1]++;
		}
		for (int i = 1; i < n; i++)
			a[i] += a[i - 1];
		int i = 0, j = 0;
		int mx = 1e9, sum = 0;
		while (j < n){
			sum += a[j];
			if ((j - i + 1) == m){
				//cout << sum << "   ";
				mx = min(mx, sum);
				sum -= a[i];
				i++;
			}
			j++;
		}
		//cout << endl;
		cout << mx << endl;
	}
	//system("pause");
	return 0;
} 