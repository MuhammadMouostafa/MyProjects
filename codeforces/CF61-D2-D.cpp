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
void stop(){
#ifndef ONLINE_JUDGE
	system("pause");
#endif
}
ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
int n;
vector<int> v;
vector< vector< pair<int, int> > > a;
ll dfsMX(int ind){
	ll mx = 0;
	v[ind] = 1;
	rep(i, a[ind])
	if(!v[a[ind][i].first]){
		mx = max(mx, a[ind][i].second + dfsMX(a[ind][i].first));
	}
	return mx;
}
int main(){
	fast();
	cin >> n;
	a = vector< vector< pair<int, int> > >(n, vector<pair<int, int>>());
	ll sum = 0;
	lp(i, n - 1){
		int s, t, w;
		cin >> s >> t >> w;
		s--;
		t--;
		sum += 2 * w;
		a[s].push_back({t,w});
		a[t].push_back({s,w});
	}
	v = vector<int>(n, 0);
	cout <<sum - dfsMX(0);
	stop();
	return 0;
}