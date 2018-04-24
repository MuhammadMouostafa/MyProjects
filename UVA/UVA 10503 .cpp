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
int n, m, x2;
vector< vector<int> > a;
vector<bool> vis;
bool backtrak(int cun, int prv){
	if (cun == n){
		return prv == x2;
	}
	lp(i,m)
	if (!vis[i]){
		vis[i] = 1;
		if (prv == a[i][0]){
			if (backtrak(cun + 1, a[i][1]))
				return 1;
		}
		else if(prv == a[i][1]){
			if (backtrak(cun + 1, a[i][0]))
				return 1;
		}
		vis[i] = 0;
	}
	return 0;
}
int main(){
	fast();
	while (cin >> n >> m){
		int x1, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		a = vector< vector<int> >(m, vector<int>(2));
		vis = vector<bool>(m, 0);
		lp(i, m)
			cin >> a[i][0] >> a[i][1];
		if (backtrak(1,y1))
			cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	stop();
	return 0;
}