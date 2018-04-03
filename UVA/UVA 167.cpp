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
int q[10][2];
vector< vector<int> > st;
vector<int> c, r;
bool valed(int i, int j, int l){
	for (int t = 1; t < i; t++){
		if (q[t][0] - j == q[t][1] - l || q[t][0] - j == l - q[t][1])
			return 0;
	}
	return 1;
}
void foo(int i){
	if (i == 9){
		st.push_back(c);
		return;
	}
	for (int l = 1; l <= 8; l++)
		if (c[l] == -1){
			if (valed(i, i, l)){
				r[i] = l;
				c[l] = i;
				q[i][0] = i;
				q[i][1] = l;
				foo(i + 1);
				r[i] = -1;
				c[l] = -1;
			}
		}
}
int main(){
	fast();
	int t;
	cin >> t;
	while (t--){
		memset(q, -1, sizeof(q));
		c = vector<int>(10, -1);
		r = vector<int>(10, -1);
		int k[10][10];
		for (int i = 1; i <= 8; i++)
		for (int j = 1; j <= 8; j++)
			cin >> k[i][j];
			foo(1);
		int mx = 0;
		rep(it,st){
			vector<int> h =st[it];
			int sum = 0;
			for (int i = 1; i <= 8; i++)
				sum += k[h[i]][i];
			mx = max(mx, sum);
		}
		st.clear();
		cout <<setw(5)<< mx << endl;
	}
	stop();
	return 0;
}
