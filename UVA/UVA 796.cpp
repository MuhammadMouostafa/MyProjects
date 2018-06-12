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
// convert str  s into    int s    a=atoi(s.c_str());
ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
vector< vector<int> > adj;
vector<int> dfn, lown;
set<pair<int,int>> st;
int tim=0;
void tarjan(int node,int par=-1){
	dfn[node] = lown[node] = tim++;
	rep(i, adj[node]){
		int ch = adj[node][i];
		if (ch == par)
			continue;
		if (dfn[ch] == -1){
			tarjan(ch,node);
			lown[node] = min(lown[node], lown[ch]);
			if (dfn[node] < lown[ch])
				st.insert({ min(node, ch),max(node,ch) });
		}
		else lown[node] = min(lown[node], dfn[ch]);
	}
}
int main(){
	fast();
	int n;
	while (cin >> n){
		adj = vector< vector<int> >(n, vector<int>());
		dfn = lown = vector<int>(n, -1);
		st.clear();
		lp(i, n){
			int from, to;
			cin >> from;
			string s;
			cin >> s;
			s = s.substr(1,s.size()-2);
			int m = atoi(s.c_str());
			while (m--){
				cin >> to;
				adj[from].push_back(to);
			}
		}
		lp(i ,n)
			if (dfn[i]== -1){
				tim = 0;
				tarjan(i);
		}
		cout << st.size()<<" critical links" << endl;
		for (auto i : st){
			cout <<i.first<<" - "<<i.second<< endl;
		}
		cout << endl;
	}
	stop();
	return 0;
}
