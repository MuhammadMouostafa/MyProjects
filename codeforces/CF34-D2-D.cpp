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
int n, r1,r2;
vector < vector<int> >adj;
vector<int> vis;
void dfs(int i, int prv){
	if (vis[i] != -1)
		return;
	vis[i] = prv;
	rep(l, adj[i])
		dfs(adj[i][l], i);
}
int main(){
	fast();
		cin >> n >> r1>>r2;
		r1--; r2--;
		adj = vector< vector<int> >(n, vector<int>());
		vis =vector<int> (n,-1);
		lp(i, n - 1){
			int a;
			cin >> a;
			a--;
			if (i < r1){
				adj[i].push_back(a);
				adj[a].push_back(i);
			}
			else{
				adj[i+1].push_back(a);
				adj[a].push_back(i+1);
			}
		}
		dfs(r2,-1);
		lp(i, n)if(i!=r2){
			cout << vis[i] + 1 << " ";
		}
	stop();
	return 0;
}
