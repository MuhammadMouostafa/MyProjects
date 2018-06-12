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
map<string, int> dfn, lown;
set<string> st;
int tim=0,ispar=0;
void tarjan(string node){
	dfn[node] = lown[node] = tim++;
	rep(i, adj[node]){
		string ch = adj[node][i];
		if (dfn[ch] == -1){
			tarjan(ch);
			lown[node] = min(lown[node], lown[ch]);
			if (dfn[node] <= lown[ch]){
				if (ispar == 0 && dfn[node] == 0)
					ispar = 1;
				else st.insert(node);
			}
		}
		else lown[node] = min(lown[node], dfn[ch]);
	}
}
int main(){
	fast();
	int n,t=1;
	while (cin >> n&&n){
		if (t > 1)
			cout << endl;
		ispar=tim = 0;
		adj.clear();
		dfn.clear();
		lown.clear();
		st.clear();
		while (n--){
			string s;
			cin >> s;
			lown[s] = dfn[s] = -1;
		}
		cin >> n;
		while (n--){
			string from, to;
			cin >> from >> to;
			adj[from].push_back(to);
			adj[to].push_back(from);
		}
		for (auto i : dfn)
			if (i.second == -1){
				ispar = tim = 0;
				tarjan(i.first);
		}
	
		cout << "City map #"<<t++<<": "<<st.size()<<" camera(s) found" << endl;
		for (auto i : st){
			cout << i << endl;
		}
	}
	stop();
	return 0;
}
