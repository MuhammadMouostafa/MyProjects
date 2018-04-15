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
int n, m;
vector < vector<char> >adj;
vector < vector<bool> >vis;
bool valid(int i, int j){
	return i >= 0 && j >= 0 && i < n&&j < m;
}
int cun = 0;
vector < pair<char, pair<int, int>> > p;
void dfs(int i, int j, bool f){
	vis[i][j] = 1;
	p[cun++]={ 'B',{i+1,j+1} };
	lp(k, 4)
	if (valid(i + dx[k], j + dy[k]) && adj[i + dx[k]][j + dy[k]] == '.'  &&!vis[i + dx[k]][j + dy[k]])
		dfs(i+dx[k],j+dy[k],1);
	if (f){
		p[cun++] = { 'D', { i + 1, j + 1 } };
		p[cun++] = { 'R', { i + 1, j + 1 } };
	}
}
int main(){
	fast();
	cin >> n >> m;
	adj = vector < vector<char> >(n, vector<char>(m));
	vis = vector < vector<bool> >(n, vector<bool>(m,0));
	p = vector < pair<char, pair<int, int>> >(n*m * 3);
	int x, y;
	lp(i,n)
		lp(j, m){
			cin >> adj[i][j];
		}
	lp(i, n)
		lp(j, m)
	if (!vis[i][j] && adj[i][j] == '.')
		dfs(i, j, 0);
	cout << cun<< endl;
	lp(i, cun)
		cout << p[i].first << " " << p[i].second.first << " " << p[i].second.second << '\n';
	stop();
	return 0;
}
