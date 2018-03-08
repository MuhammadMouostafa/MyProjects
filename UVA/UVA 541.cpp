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
	int n;
	cin >> n;
	while (n){
		int a[105][105] = { 0 };
		lp(i, n)
			lp(j,n){
			cin >> a[i][j];
			a[i][n] += a[i][j];
			a[n][j] += a[i][j];
		}
		int s1 = 0, s2 = 0, f1 = 0, f2 = 0;
		lp(i, n){
			if (a[i][n] % 2)
				f1++, s1 = i;
			if (a[n][i] % 2)
				f2++, s2 = i;
		}
		if (f1 == 0 && f2 == 0)
			cout << "OK" << endl;
		else if(f1 == 1 && f2 == 1)
			cout << "Change bit (" << s1 + 1 << "," << s2 + 1 << ")" << endl;
		else cout << "Corrupt" << endl;
		cin >> n;
	}
	system("pause");
	return 0;
}