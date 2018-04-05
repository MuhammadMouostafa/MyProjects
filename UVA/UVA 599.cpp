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
map<char, vector<char>> adj;
map<char, bool> v;
void dfs(char c){
	v[c] = 1;
	rep(i, adj[c])
	if (!v[adj[c][i]])
		dfs(adj[c][i]);
}
int main(){
	fast();
	int t;
	cin >> t;
	while (t--){
		adj.clear();
		v.clear();
		string s;
		cin >> s;
		while (s[0] != '*'){
			adj[s[1]].push_back(s[3]);
			adj[s[3]].push_back(s[1]);
			cin >> s;
		}
		cin >> s;
		rep(i,s)
		if (i % 2 == 0)
			v[s[i]] = 0;
		int co = 0,tr=0;
		rep(i, s)
		if (i % 2 == 0){
			if (!v[s[i]]){
				v[s[i]] = 1;
				if (adj[s[i]].size() == 0)
					co++;
				else{
					tr++;
					dfs(s[i]);
				}
			}
		}
		cout << "There are "<<tr<<" tree(s) and "<<co<<" acorn(s)." << endl;
	}
	stop();
	return 0;
}
