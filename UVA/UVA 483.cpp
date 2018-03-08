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
string a[100000];
int main(){
	fast();
	string s;
	while (getline(cin,s)){
		int t = 0;
		a[0] = "";
		lp(i, s.size())
		if (s[i] == ' ')
			t++,a[t]="";
		else a[t] += s[i];
		lp(i, t+1)
			reverse(a[i].begin(),a[i].end());
		cout << a[0];
		for (int i = 1; i <= t; i++)
			cout << " " << a[i];
		cout << endl;
	}
	system("pause");
	return 0;
}