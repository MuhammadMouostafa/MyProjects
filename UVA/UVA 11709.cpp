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
map<string, vector<string> > adj;
map<string, int> dfn,lown;
stack<string> sk;
vector< vector<string> > scom;
map<string, bool> instak;
int tim;
void tarjan(string node){
	dfn[node] = lown[node] = tim++;
	instak[node] = 1;
	sk.push(node);
	rep(i, adj[node]){
		string ch = adj[node][i];
		if (dfn[ch] == -1){
			tarjan(ch);
			lown[node] = min(lown[node], lown[ch]);
		}
		else if (instak[ch])
			lown[node] = min(lown[node],dfn[ch]);
	}
	if (lown[node] == dfn[node]){
		scom.push_back(vector<string>());
		string s;
		while (s != node){
			s = sk.top(); sk.pop();
			instak[s] = 0;
			scom.back().push_back(s);
		}
	}
}
int main(){
	fast();
	int n,m;
	while (cin >> n>>m&&(n||m)){
		tim = 0;
		adj.clear();
		dfn.clear();
		lown.clear();
		sk = stack<string>();
		scom.clear();
		instak.clear();
		cin.ignore();
		while (n--){
			string s;
			getline(cin, s);
			dfn[s] = -1;
		}
		while (m--){
			string from,to;
			getline(cin,from);
			getline(cin, to);
			adj[from].push_back(to);
		}
		for (auto i : dfn){
			if (i.second == -1)
				tarjan(i.first);
		}
		cout << scom.size() << endl;
	}
	stop();
	return 0;
}
