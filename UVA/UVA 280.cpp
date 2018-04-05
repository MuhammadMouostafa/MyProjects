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
int main(){
	fast();
	int n;
	cin >> n;
	while (n){
		vector< vector<int> >a(n+5, vector<int>());
		string s;
		cin.ignore();
		while (getline(cin, s)){
			if (s == "0")
				break;
			stringstream ss;
			ss << s;
			int x, c;
			ss >> c;
			c;
			while (ss >> x){
				x;
				if (x)
					a[c].push_back(x);
			}
		}
		int m;
		cin >> m;
		while (m--){
			int x;
			cin >> x;
			x;
			queue<int> q;
			vector<bool> v(n + 5, 0);
			q.push(x);
			while (q.size()){
				int g = q.front();
				q.pop();
				rep(i, a[g]){
					if (!v[a[g][i]]){
						v[a[g][i]] = 1;
						q.push(a[g][i]);
					}
				}
			}
			int sum = 0;
			for (int i = 1; i <= n; i++)
				sum += 1 - v[i];
			cout << sum;
			for (int i = 1; i <= n; i++)
			if (!v[i])
				cout << " " << i;
			cout << endl;
		}
		cin >> n;
	}
	stop();
	return 0;
}
