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
ll n, m;
vector<ll> a;
void fact(){
	a.push_back(1);
	int t = 0;
	do{
		a.push_back(1);
		t++;
		a[t] = m*a[t - 1];
		//7 2
		//cout << t << " " << a[t] << endl;
	} while (a[t]<=100000000000000000);

}
ll  foo(ll s){
	ll sum = 0;
	int t = 0;
	while (s>=a[t]){
		sum += s / a[t];
		t++;
	}
	return sum;
}
int main(){
	fast();
	cin >> n >> m;
	fact();
	ll lo = 1, hi = 1e10, ans = 1e15;
	while (lo <= hi){
		ll mid = (hi-lo)/2 + lo;
		if (foo(mid) >= n){
			ans = mid;
			hi = mid - 1;
		}
		else lo = mid + 1;
	}
	cout << ans;
//	system("pause");
	return 0;
}
