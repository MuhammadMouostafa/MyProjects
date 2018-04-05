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
int main(){
	fast();
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		vector<int> a(n, 0);
		int mn = 1e9;
		cin.ignore();
		lp(i, n){
			string s;
			getline(cin, s);
			stringstream ss;
			ss << s;
			int x;
			while (ss >> x){
				a[i]++;
			}
			mn = min(mn, a[i]);
		}
		int x = 0;
		lp(i,n)
		if (a[i] == mn){
			if (x)
				cout << " " << i + 1;
			else cout << i + 1;
			x = 1;
		}
		cout << endl;
	}
	stop();
	return 0;
}
