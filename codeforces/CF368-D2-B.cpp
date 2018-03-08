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
int a[100005], s[100005];
bool v[100005];
int main(){
	fast();
	int n,m;
	cin >> n>>m;
	lp(i, n)
		cin >> a[i];
	for (int i = n - 1; i >= 0; i--){
		s[i] += s[i + 1];
		if (!v[a[i]]){
			v[a[i]] = 1;
			s[i] += 1;
		}
		
	}
	while (m--){
		int t;
		cin >> t;
		t--;
		cout << s[t] << endl;
	}
	
	
//	system("pause");
	return 0;
}