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
int n, m;
vector<ll> a;
ll  foo(ll s){
	vector<ll> st;
	lp(i, n)
		st.push_back(a[i] + (i + 1)*s);
	ll sum = 0;
	sort(st.begin(),st.end());
	lp(i,(int)s)
		sum += st[i];
	return sum;
}
int main(){
	fast();
	cin >> n >> m;
	a = vector<ll>(n);
	lp(i, n)
		cin >> a[i];
	ll lo = 0, hi = n;
	ll ans = 0, f = 0;
	while (lo <= hi){
		ll mid = (hi - lo) / 2 + lo;
		if (foo(mid) <= m){
			ll res = foo(mid);
			if (mid > ans){
				ans = mid;
				f = res;
			}
			else if (mid == ans)
				f = min(f, res);
			lo = mid + 1;
		}
		else  hi = mid - 1;
	}
	cout << ans << " " << f;
	stop();
	return 0;
}