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
int main(){
	fast();
	int n, m, t = 1;
	cin >> n >> m;
	while (n&&m){
		vector<int> a(n);
		lp(i , n)
			cin >> a[i];
		sort(a.begin(), a.end());
		cout << "CASE# "<<t<<":" << endl;
		while (m--){
			int s;
			cin >> s;
			int ans = -1;
			int lo = 0, hi = n-1;
			while (lo <= hi){
				ll mid = (hi - lo) / 2 + lo;
				if (a[mid]>= s){
					if (s == a[mid])
					ans = mid;
					hi = mid - 1;
				}
				else lo = mid + 1;
			}
			if (ans == -1)
				cout << s << " not found" << endl;
			else cout << s << " found at " << ans + 1 << endl;
		}
	
		cin >> n >> m;
		t++;
	}
		//system("pause");
	return 0;
}
