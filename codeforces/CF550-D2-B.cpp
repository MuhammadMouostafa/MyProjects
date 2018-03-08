#define _CRT_SECURE_NO_WARNINGS
//#define __builtin_popcount__popcnt
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
//#define __builtin_popcount__popcnt

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
	int n,l,r,m,s=0;
	cin >> n>>l>>r>>m;
	vector<int> a(n);
	lp(i, n)
		cin >> a[i];
	lp(t, (1 << n)){
		int sum = 0, mx = 0, mn = 1e8,num=0;
		lp(i,n)
		if (t&(1 << i)){
			num++;
			sum += a[i];
			mx = max(mx,a[i]);
			mn = min(mn, a[i]);
		}
		if (sum >= l  &&  sum <= r && (mx - mn) >= m   &&   num >= 2)
			s++;
	
	}
	cout << s;
//	system("pause");
	return 0;
}