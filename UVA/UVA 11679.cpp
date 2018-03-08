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
	int n, m;
	cin >> n >> m;
	while (n&&m){
		int f = 1;
		int a[100];
		lp(i, n)
			cin >> a[i];
		while (m--){
			int s1, s2, s;
			cin >> s1 >> s2 >> s;
			s1--;
			s2--;
			a[s1] -= s;
			a[s2] += s;
		}
		lp(i,n)
		if (a[i] < 0)
			f = 0;
		if (f)
			cout << "S" << endl;
		else cout << "N" << endl;
		cin >> n >> m;
	}
	//system("pause");
	return 0;
}