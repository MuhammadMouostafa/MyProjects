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
vector<bool> vis;
set<int> st;
void dfs(int node){
	vis[node]=1;
	st.insert(node);
	rep(i, adj[node])
	if (!vis[adj[node][i]])
		dfs(adj[node][i]);
}
int main(){
	fast();
	int n,m,l, t;
	cin >> t;
	while (t--){
		cin >> n>>m>>l;
		adj = vector< vector<int> >(n, vector<int>());
		vis =vector<bool>(n,0);
		while (m--){
			int from, to;
			cin >> from >> to;
			from--; to--;
			adj[from].push_back(to);
		}
		while (l--){
			int x;
			cin >> x;
			x--;
			if (!vis[x])
				dfs(x);
		}
		cout << st.size() << endl;
		st.clear();
	}
	stop();
	return 0;
}
