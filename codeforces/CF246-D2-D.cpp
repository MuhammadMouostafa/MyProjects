#define __popcnt __builtin_popcount
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#define	 clr(v,d)       memset(v,d,sizeof(v))
#define  lp(i,n)        for(int i=0; i<n; i++)
#define  rep(i,v)       for(int i=0; i<(int)v.size(); i++)
#define cini(n)         scanf("%d",&n)
#define cinl(n)         scanf("%lld",&n)
#define cind(n)         scanf("%Lf",&n)
#define cinf(n)         scanf("%f",&n)   
#define cinc(n)         scanf("%c",&n)
#define cins(n)         scanf("%s",&n)
#define cinsl(n)        cin.ignore(), scanf("%[^\n]%*c",n)
#define couti(n)         printf("%d",n)
#define coutl(n)         printf("%lld",n)
#define coutd(n)         printf("%Lf",n)
#define coutdd(n)         printf("%.9l f",n)
#define coutf(n)         printf("%f",n)   
#define coutc(n)         printf("%c",n)
#define coutarc(n)         printf("%s",n)
#define couts(n)         printf("%s",n.c_str())
#define coutln()         printf("\n")   
#define coutsp(n)         printf(" ")


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
void stop(){
#ifndef ONLINE_JUDGE
	system("pause");
#endif
}
int main(){
	fast();
	int n, m;
	cin >> n >> m;
	vector<int> s(n);
	vector< set<int> > a(100005, set<int>());
	vector<bool> f(100005, 0);
	lp(i, n)
		cin >> s[i],f[s[i]]=1;
	while (m--){
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		if (s[x] == s[y])
			continue;
		a[s[x]].insert(s[y]);
		a[s[y]].insert(s[x]);
	}
	int mx = a[s[0]].size(), clr = s[0];
	lp(i, 100005){
		if (a[i].size() > mx){
			mx = a[i].size();
			clr = i;
		}
		else if (a[i].size() == mx){
			if(f[i])
			clr = min(clr,i);
		}
	}
	cout << clr;
	stop();
	return 0;
}