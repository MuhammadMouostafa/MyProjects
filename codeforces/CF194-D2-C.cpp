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
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int n, m;
vector< vector<char> > a;
vector< vector<bool> > vis;
bool valid(int i, int j){
	return i >= 0 && j >= 0 && i < n&&j < m;
}
void dfs(int i, int j){
	if (!valid(i, j) || a[i][j] == '.')
		return ;
	if (vis[i][j])
		return ;
	vis[i][j] = 1;
	lp(k, 4)
		dfs(i + dx[k], j + dy[k]);
}
int main(){
	fast();
	cin >> n >> m;
	a = vector< vector<char> >(n, vector < char>(m));
	int mx = 0;
	lp(i, n)
		lp(j, m){
			cin >> a[i][j];
			if (a[i][j] == '#')
				mx++;
		}
	if (mx <= 2)
		cout << -1;
	else{
		int f = 2;
		lp(i,n)
			lp(j, m)
		if(a[i][j]=='#'){
			vis = vector< vector<bool> >(n, vector < bool>(m, 0));
			int sum = 0;
			a[i][j] = '.';
			lp(i1,n)
				lp(j1,m)
			if (!vis[i1][j1] && a[i1][j1] == '#')
				dfs(i1,j1),sum++;
			if (sum > 1)
				f = 1;
			a[i][j] = '#';
			}
		cout << f;
	}
	stop();
	return 0;
}