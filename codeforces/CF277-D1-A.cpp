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
bool a[105][105] = { 0 };
int n, m;
vector<int> v;
void dfs(int ind){
	lp(i,n)
	if (a[ind][i] && !v[i]){
		v[i] = 1;
		dfs(i);
	}
}
int main(){
	fast();
	cin >> n>>m;
	vector< vector<int> > L(m,vector<int>());
	int mx = 0;
	lp(i, n){
		int k;
		cin >> k;
		if (k == 0)
			mx++;
		while (k--){
			int s;
			cin >> s;
			s--;
		L[s].push_back(i);
		}
	}
	lp(l, m){
		rep(i,L)
		for (int j = i + 1; j < L[l].size(); j++){
			a[L[l][i]][L[l][j]] = 1;
			a[L[l][j]][L[l][i]] = 1;
		}
	}
	v=vector<int>(n, 0);
	int sum = 0;
	lp(i, n)
	if(!v[i]){
		sum++;
		v[i] = 1;
		dfs(i);
	}
	if (mx == n)
		cout << n;
	else 
	cout << sum-1 << endl;
	stop();
	return 0;
}