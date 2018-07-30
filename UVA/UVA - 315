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
vector< vector<int> > adj;
vector<int> tin, fup;
int tim, cret;
void tarjan(int nod, int p = -1){
	int childs = 0;
	int x1 = 0;
	tin[nod] = fup[nod] = tim++;
	rep(i, adj[nod]){
		int ch = adj[nod][i];
		//if (ch == p)continue;
		if (tin[adj[nod][i]] == -1){
			tarjan(ch, nod);
			fup[nod] = min(fup[nod], fup[ch]);
			if (tin[nod] <= fup[ch] && p != -1)
				x1 = 1;
			childs++;
		}
		else{
			fup[nod] = min(fup[nod], tin[ch]);
		}
	}
	if (childs > 1 && p == -1)
		x1 = 1;
		cret+=x1;
}
int main(){
	fast();
	int n;
	while (cin >> n &&n){
		tim = cret = 0;
		tin = fup = vector<int>(n, -1);
		adj = vector< vector<int> >(n, vector<int>());
		cin.ignore();
		string s;
		while (getline(cin, s) && s != "0"){
			stringstream ss;
			ss << s;
			int x, j = -1;
			while (ss >> x){
				x--;
				if (j == -1)
					j = x;
				else {
					adj[j].push_back(x);
					adj[x].push_back(j);
				}
			}
		}
		lp(i,n)
		if (tin[i] == -1)
		tarjan(0);
		cout << cret << endl;
	}
	stop();
	return 0;
}
