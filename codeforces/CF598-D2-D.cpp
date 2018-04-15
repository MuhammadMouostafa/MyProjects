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
int dx[] = { 0,   0, -1,  1 , 1 ,  1 , -1 , -1 };
int dy[] = { 1, - 1,  0,  0 , 1 , -1 ,  1 , -1 };
int n, m,k;
vector < vector<char> >adj;
bool valid(int i, int j){
	return i >= 0 && j >= 0 && i < n&&j < m;
}
vector <vector<int> > vis1;
vector <vector<bool> >vis2;
int mx = 0;
void dfs(int i, int j){
	if (!valid(i, j)){
		return;
	}
	if (adj[i][j] == '*'){
		mx++;
		return;
	}
	if (vis2[i][j])
		return;
	vis2[i][j] = 1;
	lp(l, 4)
		dfs(i+dx[l],j+dy[l]);
}
void dfs2(int i, int j){
	if (!valid(i, j)){
		return;
	}
	if (adj[i][j] == '*'){
		return;
	}
	if (vis1[i][j]!=-1)
		return;
	vis1[i][j] = mx;
	lp(l, 4)
		dfs2(i + dx[l], j + dy[l]);
	
}
int main(){
	fast();
		cin >> n >> m>>k;
		adj = vector< vector<char> >(n, vector<char>(m));
		vis1 = vector <vector<int> >(n, vector<int>(m,-1));
		vis2 = vector <vector<bool> >(n, vector<bool>(m, 0));
		lp(i, n)
			lp(j, m)
				cin >> adj[i][j];
		lp(i, n)
			lp(j, m)
		if (!vis2[i][j]&&adj[i][j] == '.'){
			mx = 0;
			dfs(i,j);
			dfs2(i, j);
		}
		while (k--){
			int s, a;
			cin >> a >> s;
			s--;
			a--;
			cout << vis1[a][s] << endl;
		}
	stop();
	return 0;
}
