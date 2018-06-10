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
void stop(){
#ifndef ONLINE_JUDGE
	system("pause");
#endif
}
void fast()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
}
ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
vector< vector<int> > adj;
vector< vector<bool> >vis;
int n;
bool valid(int i, int j){
	return i >= 0 && j >= 0 && i < n&&j < n;
}
void dfs(int i, int j){
	vis[i][j]=1;
	lp(k, 4){
		int x = dx[k] + i;
		int y = dy[k] + j;
		if (valid(x, y) && adj[i][j] == adj[x][y] && !vis[x][y])
			dfs(x, y);
	}
}
int main(){
	fast();
	while (cin >> n  && n){
		adj = vector< vector<int> >(n, vector<int>(n,n-1));
		vis = vector< vector<bool> >(n, vector<bool>(n,0));
		cin.ignore();
		lp(i, n - 1){
			string s;
			getline(cin, s);
			stringstream ss;
			ss << s;
			int x, y;
			while (ss >> x){
				ss >> y;
				x--; y--;
				adj[x][y] = i;
			}
		}
		bool ok = 1;
		vector<bool> clor(n, 0);
		lp(i,n)
			lp(j,n)
		if (!vis[i][j]){
			if (clor[adj[i][j]])
				ok = 0;
			else {
				clor[adj[i][j]] = 1;
				dfs(i, j);
			}
		}
		if (ok)
			cout << "good" << endl;
		else cout << "wrong" << endl;
	}
	stop();
	return 0;
}
