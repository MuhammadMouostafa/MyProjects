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
ll a[100000], s[100000];
int main(){
	fast();
	ll n, m;
	cin >> n >> m;
	
	lp(i, n)cin >> a[i];
	lp(i, n)cin >> s[i];
	unsigned long long lo = 0, hi = 2e9, ans = 0;
	while (lo <= hi){
		unsigned long long mid = (hi + lo) / 2;
		unsigned long long s1 = 0;
		int v = 0;
		lp(i, n){
			unsigned long long g = mid * a[i];
			if (g >s[i]){
				s1 += g;
				s1 = (ll)s1 - s[i];
			}

			if (s1 > m){
				(ll)mid--;
				hi = mid;
				v = 1;
				break;
			}
		}
		if (v)
			continue;
		//cout << lo << " " << mid << " " << hi <<" "<<s1<< endl;
		if (s1 <= m){
			ans = mid;
			lo = mid + 1;
		}
		else {
			(ll)mid--;
			hi = mid;
		}
	}
	cout <<ans;
		//system("pause");
	return 0;
}