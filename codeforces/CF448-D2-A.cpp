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
	int n, s1 = 0, s2 = 0;
	lp(i, 3){
		cin >> n;
		s1 += n;
	}
	lp(i, 3){
		cin >> n;
		s2 += n;
	}
	cin >> n;
	int s = s1 / 5;
	if (s1 % 5)
		s++;
	s += s2 / 10;
	if (s2 % 10)
		s++;
	string x[] = { "NO","YES" };
	cout << x[s<=n];
	//system("pause");
	return 0;
}