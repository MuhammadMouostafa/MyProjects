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
		cin.ignore();
		int mn = 1e5, sum = 0;
		lp(i, n){
			string a;
			getline(cin,a);
			int s = 0;
			rep(j,a)
			if (a[j] == ' ')
				s++;
			mn = min(mn, s);
			sum += s;
		}
		cout << sum - (n*mn) << endl;
		cin >> n;
	}
	//system("pause");
	return 0;
}